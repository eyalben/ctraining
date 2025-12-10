# Compilation, Linking, and Libraries: Under the Hood

---

## Part 1: The Philosophy

### The "OpenOffice" Problem

Imagine a massive project like OpenOffice (~10,000 files).

| Scenario | Problem |
|----------|---------|
| You change **1 line** in 1 file | Rebuilding everything takes **3.5 days** |

**Solution:** Split the build into two stages:

| Stage | What it does |
|-------|--------------|
| **Compilation** | Translate each `.c` → `.o` (machine code) |
| **Linking** | Glue all `.o` files → one executable |

> Change one file? Only recompile that one file!

---

## Part 2: Compiling Without Header Files

We'll compile code **without** headers to understand how linking works.

### Step 1: The Setup

**`math.c`**
```c
int sum(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}
```

**`main.c`**
```c
// No #include!
void main() {
    int result = sum(10, 20);
}
```

### Step 2: Compile (without linking)

```bash
$ gcc -c math.c
$ gcc -c main.c
```

**Output:**
```
main.c: warning: implicit declaration of function 'sum'
```

> The compiler **guesses** the function signature and produces `.o` files anyway.

### Step 3: Inspect with `nm`

`nm` shows **symbols** (function names) inside binary files.

```bash
$ nm main.o
```
```
                 U sum    # U = Undefined (needs this function)
0000000000000000 T main   # T = Text (has this function's code)
```

```bash
$ nm math.o
```
```
0000000000000000 T sub    # T = Defined here
0000000000000000 T sum    # T = Defined here
```

**Key:** `U` = "I need this" | `T` = "I have this"

We can also use `objdump -D` to see the actual assembly and how the call address is left blank:

```bash
$ objdump -D -M intel main.o
```
```asm
0000000000000000 <main>:
   0:   55                      push   rbp
   1:   48 89 e5                mov    rbp,rsp
   4:   48 83 ec 10             sub    rsp,0x10
   8:   be 14 00 00 00          mov    esi,0x14        # 20
   d:   bf 0a 00 00 00          mov    edi,0xa         # 10
  12:   e8 00 00 00 00          call   17 <main+0x17>  # Address is 00 00 00 00!
  17:   89 45 fc                mov    DWORD PTR [rbp-0x4],eax
```

> Notice the `call` instruction at offset `12` - the address is `00 00 00 00`. The linker will fill this in later!

### Step 4: Link

```bash
$ gcc main.o math.o -o my_app
```

The linker connects the "Undefined" symbols to their definitions. Let's inspect the final executable:

```bash
$ nm my_app | grep -E "sum|sub|main"
```
```
0000000000001149 T main
0000000000001119 T sub
0000000000001100 T sum
```

> All symbols now have **real addresses**! The linker matched `U sum` in `main.o` to `T sum` in `math.o`.

### Step 5: Verify with printf

**`main.c`** (updated)
```c
#include <stdio.h>

int main() {
    int result = sum(10, 20);
    printf("The sum is: %d\n", result);
    return 0;
}
```

```bash
$ gcc -c main.c && gcc -c math.c
$ gcc main.o math.o -o my_app
$ ./my_app
```
```
The sum is: 30
```

> It works! But we still have that "implicit declaration" warning...

---

## Part 3: Why We Need Headers

### Step 1: The "C is Dangerous" Demo

**`main.c`** (wrong number of arguments!)
```c
#include <stdio.h>

int main() {
    int result = sum(10, 20, 30, 40, 50);  // sum() takes 2 args!
    printf("The sum is: %d\n", result);
    return 0;
}
```

```bash
$ gcc -c main.c
$ gcc main.o math.o -o my_app
$ ./my_app
```
```
The sum is: 30   # Works?! (garbage luck)
```

> **C links by name only** - it ignores argument count/types!

### Step 2: Add Forward Declarations

**`main.c`**
```c
#include <stdio.h>

int sum(int a, int b);  // Declaration
int sub(int a, int b);  // Declaration

int main() {
    int result = sum(10, 20);
    printf("The sum is: %d\n", result);
    return 0;
}
```

Now wrong arguments cause a **compiler error**:
```bash
$ gcc -c main.c   # With sum(10, 20, 30)
```
```
error: too many arguments to function 'sum'
```

> **Problem:** We're duplicating declarations in every file.

### Step 3: Share Declarations via Include

**`shared.txt`**
```c
int sum(int a, int b);
int sub(int a, int b);
```

**`math.c`**
```c
#include "shared.txt"

int sum(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
```

**`main.c`**
```c
#include <stdio.h>
#include "shared.txt"

int main() {
    int result = sum(10, 20);
    printf("The sum is: %d\n", result);
    return 0;
}
```

```bash
$ gcc -c main.c && gcc -c math.c
$ gcc main.o math.o -o my_app
$ ./my_app
```
```
The sum is: 30
```

Let's see what the preprocessor does with `gcc -E`:

```bash
$ gcc -E main.c
```
```c
# 1 "main.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "main.c"
# 1 "/usr/include/stdio.h" 1 3 4
... (hundreds of lines from stdio.h) ...

# 1 "shared.txt" 1
int sum(int a, int b);
int sub(int a, int b);
# 3 "main.c" 2

int main() {
    int result = sum(10, 20);
    printf("The sum is: %d\n", result);
    return 0;
}
```

> The contents of `shared.txt` are literally **pasted** into the file!

Now with wrong arguments:
```bash
$ gcc -c main.c   # With sum(10, 20, 30)
```
```
error: too many arguments to function 'sum'
```

> Caught at **compile time** instead of silent runtime bug!

### Compiler vs Linker Errors

| Error Type | When | Example |
|------------|------|---------|
| **Compiler** | `gcc -c` | Wrong argument count |
| **Linker** | `gcc *.o` | Undefined reference |

**Wrong function NAME** (e.g., `summ`):
```bash
$ gcc -c main.c
```
```
warning: implicit declaration of function 'summ'
```
```bash
$ gcc main.o math.o -o my_app
```
```
error: undefined reference to 'summ'
```

**Wrong ARGUMENTS** (without declarations):
- Compile: warning only
- Link: **no error** - undefined behavior!

### Step 4: Function Overloading - C vs C++

**`math.c`** (attempting overload in C)
```c
int sum(int a, int b) { return a + b; }
int sum(int a, int b, int c) { return a + b + c; }
```

```bash
$ gcc -c math.c
```
```
error: redefinition of 'sum'
```

> **C does NOT support function overloading!**

**`math.cpp`** (same code in C++)
```cpp
int sum(int a, int b) { return a + b; }
int sum(int a, int b, int c) { return a + b + c; }
```

```bash
$ g++ -c math.cpp
$ nm math.o
```
```
0000000000000000 T _Z3sumii    # sum(int, int)
0000000000000014 T _Z3sumiii   # sum(int, int, int)
```

**Name Mangling Comparison:**

| Language | `sum(int, int)` | `sum(int, int, int)` |
|----------|-----------------|----------------------|
| C | `sum` | `sum` (collision!) |
| C++ | `_Z3sumii` | `_Z3sumiii` |

**Decoding `_Z3sumii`:**
- `_Z` = C++ prefix
- `3` = name length ("sum")
- `sum` = function name
- `ii` = two `int` params

```bash
$ c++filt _Z3sumii
```
```
sum(int, int)
```

> C++ encodes parameter types in the name → overloading works!

### Function Names are Global in C

All C function names share **one global namespace**:
- No two functions can have the same name
- Libraries can collide with each other

### Step 5: Solving the Namespace Problem

#### Solution 1: Prefixes

```c
int MATH_sum(int a, int b) { return a + b; }
int MATH_sub(int a, int b) { return a - b; }
```

**Real-world examples:**
- `SDL_Init()`, `SDL_CreateWindow()`
- `gtk_init()`, `gtk_window_new()`
- `pthread_create()`, `pthread_join()`

#### Solution 2: `static` Keyword

Mark "private" helper functions as `static`:

**`math.c`**
```c
static int validate(int a, int b) {  // Private!
    return (a >= 0 && b >= 0);
}

int MATH_sum(int a, int b) {
    if (!validate(a, b)) return -1;
    return a + b;
}
```

```bash
$ gcc -c math.c
$ nm math.o
```
```
0000000000000000 T MATH_sub
0000000000000020 T MATH_sum
0000000000000040 t validate   # lowercase 't' = local!
```

**Symbol Types:**
| Symbol | Meaning |
|--------|---------|
| `T` (uppercase) | Global - visible to linker |
| `t` (lowercase) | Local - private to this file |

---

## Part 4: The Preprocessor & Headers

### Step 1: What `gcc -E` Does

The preprocessor is a **copy-paste machine**.

```bash
$ gcc -E main.c
```
```c
// ... hundreds of lines from stdio.h ...

int sum(int a, int b);
int sub(int a, int b);

int main() {
    int result = sum(10, 20);
    printf("The sum is: %d\n", result);
    return 0;
}
```

> `#include` literally pastes the file contents!

#### Double-Include Problem

**`main.c`**
```c
#include "shared.txt"
#include "shared.txt"  // Included twice!
```

```bash
$ gcc -E main.c
```
```c
int sum(int a, int b);
int sub(int a, int b);
int sum(int a, int b);  // Duplicated!
int sub(int a, int b);  // Duplicated!
```

> For `struct` definitions, this causes: `error: redefinition`

### Step 2: Header Guards (Classic)

**`shared.h`**
```c
#ifndef SHARED_H
#define SHARED_H

int sum(int a, int b);
int sub(int a, int b);

#endif
```

**How it works:**
1. First include: `SHARED_H` undefined → define it, include content
2. Second include: `SHARED_H` defined → skip to `#endif`

### Step 3: `#pragma once` (Modern)

**`shared.h`**
```c
#pragma once

int sum(int a, int b);
int sub(int a, int b);
```

**What is `#pragma`?**

Compiler-specific extensions:

| Pragma | Effect |
|--------|--------|
| `#pragma once` | Include file only once |
| `#pragma pack(1)` | Change struct alignment |
| `#pragma GCC optimize("O3")` | Set optimization level |

**`#pragma once` History:**
- Originally Microsoft Visual C++ only
- Now supported by all major compilers
- Not in the C standard, but universally available

### Never `#include` a `.c` File!

**`main.c`** (bad!)
```c
#include "math.c"  // Including implementation!

int main() { return sum(1, 2); }
```

```bash
$ gcc main.c math.c -o my_app
```
```
error: multiple definition of 'sum'
```

**What happened:**
1. `main.c` includes `math.c` → contains `sum` definition
2. `math.c` compiled separately → also contains `sum` definition
3. Linker sees two `sum` → error!

**Correct Pattern:**
```
math.h  →  Declarations (what exists)
math.c  →  Definitions (the code)
main.c  →  #include "math.h"
```

---

## Part 5: Shared Libraries (Dynamic Linking)

Had anyone tried to run old games and ran into message like `Could not locate msvcrt97.dll/directx97.dll`?

### The "Gamer" Story

Imagine you're a gamer with three games, all built on the Unreal Engine.

**Static Linking (Current Situation):**
```
┌─────────────────────────────────────┐
│           Your Hard Drive           │
├─────────────────────────────────────┤
│                                     │
│  ┌─────────────────────────────┐    │
│  │     Game 1: Fortnite        │    │
│  │  ┌─────────────────────┐    │    │
│  │  │ Unreal Engine: 10GB │    │    │
│  │  └─────────────────────┘    │    │
│  │  Game Code: 15GB            │    │
│  │  Total: 25GB                │    │
│  └─────────────────────────────┘    │
│                                     │
│  ┌─────────────────────────────┐    │
│  │     Game 2: Rocket League   │    │
│  │  ┌─────────────────────┐    │    │
│  │  │ Unreal Engine: 10GB │    │    │
│  │  └─────────────────────┘    │    │
│  │  Game Code: 12GB            │    │
│  │  Total: 22GB                │    │
│  └─────────────────────────────┘    │
│                                     │
│  ┌─────────────────────────────┐    │
│  │     Game 3: Gears of War    │    │
│  │  ┌─────────────────────┐    │    │
│  │  │ Unreal Engine: 10GB │    │    │
│  │  └─────────────────────┘    │    │
│  │  Game Code: 18GB            │    │
│  │  Total: 28GB                │    │
│  └─────────────────────────────┘    │
│                                     │
│  TOTAL: 75GB (30GB is duplicated!)  │
└─────────────────────────────────────┘
```

**Dynamic Linking (Shared Engine):**
```
┌─────────────────────────────────────┐
│           Your Hard Drive           │
├─────────────────────────────────────┤
│                                     │
│  ┌─────────────────────────────┐    │
│  │  Shared: Unreal Engine 10GB │◄───┼──┬──┬──┐
│  └─────────────────────────────┘    │  │  │  │
│                                     │  │  │  │
│  ┌──────────────────┐               │  │  │  │
│  │ Game 1: Fortnite │───────────────┼──┘  │  │
│  │ Game Code: 15GB  │               │     │  │
│  └──────────────────┘               │     │  │
│                                     │     │  │
│  ┌────────────────────┐             │     │  │
│  │ Game 2: Rocket Lg. │─────────────┼─────┘  │
│  │ Game Code: 12GB    │             │        │
│  └────────────────────┘             │        │
│                                     │        │
│  ┌────────────────────┐             │        │
│  │ Game 3: Gears      │─────────────┼────────┘
│  │ Game Code: 18GB    │             │
│  └────────────────────┘             │
│                                     │
│  TOTAL: 55GB (saved 20GB!)          │
└─────────────────────────────────────┘
```

| Linking Type | Calculation | Total |
|--------------|-------------|-------|
| **Static** | (10+15) + (10+12) + (10+18) | **75GB** |
| **Dynamic** | 10 + 15 + 12 + 18 | **55GB** |

### Step 1: Create a Shared Library

So how do we create a shared library?

```bash
$ gcc -shared -fPIC math.c -o libmath.so
```

| Flag | Meaning |
|------|---------|
| `-shared` | Create library, not executable |
| `-fPIC` | Position Independent Code (can load anywhere in RAM) |

### Step 2: Link Against It

```bash
$ gcc main.c -L. -lmath -o my_game
```

| Flag | Meaning |
|------|---------|
| `-L.` | Look for libraries in current folder |
| `-lmath` | Link `libmath.so` (adds `lib` prefix and `.so` suffix) |

### Step 3: Runtime Dependencies

```bash
$ ./my_game
```
```
error while loading shared libraries: libmath.so: cannot open
```

```bash
$ ldd my_game
```
```
linux-vdso.so.1 => (0x0000...)
libmath.so => not found          # THE PROBLEM
libc.so.6 => /lib64/libc.so.6
```

### Step 4: Why It Failed (Security)

Linux does **NOT** search current directory for libraries.

**Why?** If a malicious `libc.so` is in your Downloads folder, you don't want your shell to load it instead of the system library!

**Fix:**
```bash
$ export LD_LIBRARY_PATH=.
$ ./my_game
```
```
The sum is: 30
```

---

### Discussion: Static vs Dynamic - When to Use Which?

| Aspect | Dynamic Linking | Static Linking |
|--------|-----------------|----------------|
| **File Size** | Smaller executables | Larger executables |
| **Distribution** | Requires dependencies | Self-contained |
| **Security Updates** | Easy - update library once | Hard - rebuild every app |
| **Compatibility** | May break if library changes | Always works |

#### Story 1: Chrome's Static Linking Strategy

Google Chrome ships as a **massive single executable** with most libraries statically linked.

**Why?** Chrome runs on millions of different computers with different Linux distributions, Windows versions, and macOS releases. Each system might have different versions of libraries installed.

By statically linking everything, Google guarantees that:
- Chrome works identically on every machine
- No "missing library" errors for users
- No compatibility issues with outdated system libraries
- Updates are simple: just replace one file

The downside? Chrome's installer is ~100MB+ because it includes everything it needs.

#### Story 2: The Heartbleed Disaster (2014)

In April 2014, a critical security bug called **Heartbleed** was discovered in OpenSSL, a library used for secure HTTPS connections.

**The Problem:** OpenSSL was so widely used that almost every server on the internet was vulnerable. Attackers could steal passwords, private keys, and sensitive data from any affected server.

**The Nightmare for Static Linking:**

Many applications had OpenSSL **statically linked** into their executables. This meant:
- Updating the system's OpenSSL did **nothing** - the vulnerable code was baked into each app
- Every single application had to be **recompiled** with the fixed OpenSSL
- Some vendors took **months** to release patched versions
- Some applications were **never updated** and remained vulnerable

**If Dynamic Linking Was Used:**
- Update OpenSSL once on the system
- Restart applications
- Done! Every app now uses the fixed library

**The Lesson:** Static linking trades security flexibility for distribution simplicity. For security-critical libraries, dynamic linking allows faster patching across all applications.

```
┌────────────────────────────────────────────────────────────┐
│                    HEARTBLEED FIX                          │
├────────────────────────────────────────────────────────────┤
│                                                            │
│  Dynamic Linking:          Static Linking:                 │
│                                                            │
│  ┌──────────┐              ┌──────────┐ ┌──────────┐      │
│  │ OpenSSL  │ ← Fix here   │  App 1   │ │  App 2   │      │
│  │ (shared) │              │+OpenSSL  │ │+OpenSSL  │      │
│  └────┬─────┘              └────┬─────┘ └────┬─────┘      │
│       │                         │            │             │
│  ┌────┴────┐                    ▼            ▼             │
│  │ All apps│              Rebuild      Rebuild            │
│  │  fixed! │              each one     each one           │
│  └─────────┘              separately   separately         │
│                                                            │
│  Time: Minutes             Time: Days to Months            │
└────────────────────────────────────────────────────────────┘
```
