# Preprocessor

Show Preprocessor output using:
`gcc -E file.c`

1. Use #define (no #include) to show how it works in search replace
2. Use #ifdef ifndef to show that files are not alawys duplicate:

```c
#ifndef BLA
#define BLA

void func();
void one();

#endif

#ifndef BLA
#define BLA

void func();
void two();

#endif
```

3. Show #include, and why do we include ".h" and not ".c" files.

# Calling Convention

Why is the declaration enough for compiling?

First two memory areas:
```
.stack R W
.code R X

// Accept values in r0, r1, return in r2
sum:
ASM
ASM
ASM
ASM
ASM
ASM

// Accept values in stack
sum:
ASM
ASM
ASM
ASM
ASM
ASM

SUM:
POP R0
POP R1
ADD R0, R1
EAX = RESULT
RETURN

PUSH 10
PUSH 20
CALL SUM
EAX contians the result
```
int32_t exp(int32_t base, int32_t value, int32_t)

# GCC

gcc -E Preprocessor
gcc -c
gcc -S

# Linking

nm
U Undefined
T Text Section

1. nm on each file
2. nm on a.out (notice that printf is still U ndefined)

# Show implementation of files

> objdump -D lib.o

# Sections

.eh_frame - For exception handling

PLT stands for Procedure Linkage Table which is, put simply, used to call external procedures/functions whose address isn't known in the time of linking, and is left to be resolved by the dynamic linker at run time.

GOT stands for Global Offsets Table and is similarly used to resolve addresses. Both PLT and GOT and other relocation information

```
gcc -c -Wall -Werror -fpic foo.c

gcc -shared -o libfoo.so foo.o

file libfoo.so
ldd foo.c

gcc -L/path/to/search main.c -lfoo
```

# Static function
create a static function and show using `nm` and compiling `gcc math.o main.o` it is hidden.