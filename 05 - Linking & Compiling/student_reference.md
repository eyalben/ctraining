# Compilation, Linking & Libraries — Student Reference

A condensed cheat sheet of the key concepts and commands. For the full
explanations and examples, see `full_instructor_notes.md`.

---

## 1. Two-Stage Build

Building is split into two stages so changing one file only requires
recompiling that one file (not the whole project).

| Stage | What it does | Command |
|-------|--------------|---------|
| **Compilation** | Translate each `.c` → `.o` (machine code) | `gcc -c file.c` |
| **Linking** | Glue all `.o` files → one executable | `gcc *.o -o app` |

Full pipeline: **Preprocessing → Compiling → Assembling → Linking**

---

## 2. Symbols & Linking

The linker connects "undefined" symbols (functions you call) to their
definitions (functions you provide).

### `nm` — list symbols in a binary

```bash
$ nm main.o
                 U sum    # U = Undefined (needs this function)
0000000000000000 T main   # T = Text  (defines this function)
```

| Symbol | Meaning |
|--------|---------|
| `U` | Undefined — "I need this" |
| `T` (uppercase) | Global — defined here, visible to linker |
| `t` (lowercase) | Local — `static`, private to this file |

### `objdump` — see the assembly

```bash
$ objdump -D -M intel main.o
  12:   e8 00 00 00 00          call   ...   # address is 00 00 00 00
```

Before linking, `call` addresses are blank `00 00 00 00`. The linker fills
them in.

---

## 3. Why Headers

**C links by name only** — it ignores argument count/types. Calling a
function with the wrong number of arguments compiles (warning only) and
links with **no error** → silent undefined behavior.

Fix: declare functions before use so the compiler can check calls.

```c
int sum(int a, int b);   // declaration
int sub(int a, int b);   // declaration
```

Share declarations across files via a header (`#include "math.h"`) instead
of duplicating them.

### Compiler vs Linker errors

| Error Type | When | Example |
|------------|------|---------|
| **Compiler** | `gcc -c` | Wrong argument count (only if declared) |
| **Linker** | `gcc *.o` | `undefined reference` (e.g. typo in name) |

---

## 4. The Preprocessor (`gcc -E`)

`#include` is a literal **copy-paste** of the file's contents.

```bash
$ gcc -E main.c     # shows the fully expanded source
```

### Double-include problem & guards

Including a header twice duplicates its contents → `redefinition` errors
(especially for `struct`s). Prevent with a guard:

**Classic header guard:**
```c
#ifndef SHARED_H
#define SHARED_H
... declarations ...
#endif
```

**Modern (`#pragma once`):**
```c
#pragma once
... declarations ...
```

`#pragma` = compiler-specific extension (`once`, `pack(1)`,
`GCC optimize("O3")`, …). `#pragma once` is not in the C standard but is
universally supported.

### Never `#include` a `.c` file

Including an implementation file leads to `multiple definition` errors at
link time. Correct pattern:

```
math.h  →  Declarations (what exists)
math.c  →  Definitions  (the code)
main.c  →  #include "math.h"
```

---

## 5. Namespaces

C function names share **one global namespace** — no two functions can have
the same name, and C does **not** support overloading (defining a second
`sum` with different parameters gives a `redefinition` error).

### Avoiding collisions in C

1. **Prefixes** — `MATH_sum()`, `SDL_Init()`, `gtk_init()`, `pthread_create()`
2. **`static`** — mark private helpers `static` so they don't appear as
   global symbols (`t` instead of `T` in `nm`).

---

## 6. Shared Libraries (Dynamic Linking)

### Create & link

```bash
$ gcc -shared math.c -o libmath.so   # build the library
$ gcc main.c -L. -lmath -o my_app    # link against it
```

| Flag | Meaning |
|------|---------|
| `-shared` | Create a library, not an executable |
| `-L.` | Look for libraries in the current folder |
| `-lmath` | Link `libmath.so` (adds `lib` prefix + `.so` suffix) |

### Runtime dependencies

Linux does **not** search the current directory for libraries (security:
avoids loading a malicious `libc.so`). At runtime you may see:

```
error while loading shared libraries: libmath.so: cannot open
```

Inspect dependencies with `ldd`, then point the loader at the directory:

```bash
$ ldd my_app                  # libmath.so => not found
$ export LD_LIBRARY_PATH=.
$ ./my_app
```

### Static vs Dynamic

| Aspect | Dynamic | Static |
|--------|---------|--------|
| **File size** | Smaller executables | Larger executables |
| **Distribution** | Requires dependencies present | Self-contained |
| **Security updates** | Update the library once | Rebuild every app |
| **Compatibility** | May break if library changes | Always works |

---

## 7. The `extern` Keyword

`extern` changes linkage: the function/variable is assumed to live
elsewhere, and resolution is deferred to the linker.

- **Variables:** does *not* allocate memory — the actual definition must
  exist in some other file. Use it to import a variable.
- **Functions:** only states that linkage is external. This is already the
  default, so it's usually unnecessary (use `static` for the opposite —
  internal linkage).
