# Linking & Compiling

## Part 1 - Compilation Process

### Separating Compilation from Linking

What if my code was split to multiple files and I used the following command to compile?

`gcc main.c file1.c file2.c file3.c -o myapp`

What if I had 3000 files to do so?

- Story #1: Long compilation process (OpenOffice Story, Gentoo, 3-days compilation process)
- (Anecdote for story #1: Intel IA-64 vs x86-64 vs amd64 - not exactly the same - hence different compiler)

There must be a more efficient way (and there is!) - *Diagram #1* - we can `compile` each file separately:

```
First we translate the code (the text) to binary:
    main.c       =>      main.o
    part1.c      =>      part1.o
    part2.c      =>      part2.o
    part3.c      =>      part3.o

Then we'll merge all compiled files to a single executable file:

    main.o
    part1.o                 =>      myapp
    part2.o
    part3.o

       ^
  binary files
```

Let's overview the entire process and dig in to each part

Preprocessing -> Compiling -> Assembling -> Linking

### Separating Files in C

1. Create main with sum and sub functions
2. Move functions to `math.c` and `main.c` and compile them together (notice the 'implicit declaration')
3. Add sum and sub declaration in `main.c` - see how everything is ok
4. Change sum from int to uint32 -> see no warning occurred (bad!)
5. Copy declarations to `math.c` - it'll now detect the error (fix it!)
6. Put declaration in a shared file called `math.h` :)

### Awesome - let's talk about Linking Process

`gcc -E`

1. Define
2. Multiple import issues
3. Header Guards
4. Pragma Once (and Pragma)

### Separating compilation process

gcc -c
gcc -S
`nm` command (important!)
`ld`
objdump -D lib.o


Any more questions of how to separate files or to compile separately?


## Part 2 - Shared Libraries

We'll start with two stories:
1. Anyone tried to run old games and ran into message like `Could not locate msvcrt97.dll/directx97.dll`?
2. Background Story: 3D Games, Static Compiling vs Dynamic Compiling (space on disk, ram)

- Demo of how it is done
- search path
- -lXXX

