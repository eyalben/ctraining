# Linking & Compiling

## Part 1 - Compilation Process

### Separating Compilation from Linking

What if my code was split to multiple files and I used the following command to compile?

`gcc main.c file1.c file2.c file3.c -o myapp`

What if I had 3000 files to do so?

- Story #1: Long compilation process (OpenOffice Story, Gentoo, 3-days compilation process)
- (Anecdote for story #1: Intel IA-64 vs x86-64 vs amd64 - not exactly the same - hence different compiler)

There must be a more efficient way (and there is!) - _Diagram #1_ - we can `compile` each file separately:

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

### Awesome - let's talk about preprocessor

`gcc -E`

1. Define
2. Multiple import issues
3. Header Guards
4. Pragma Once (and Pragma)
5. Why to never put code in header files!

### Separating compilation process

gcc -c
gcc -S
`nm` command (important!)
compile with g++ and then run nm to see name demangling
`ld`
objdump -D lib.o

Any more questions of how to separate files or to compile separately?

## Part 2 - Shared Libraries

https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html

> - C Preprocessor: This stage processes all the preprocessor directives. Basically, any line that starts with a #, such as #define and #include.
> - Compilation Proper: Once the source file has been preprocessed, the result is then compiled. Since many people refer to the entire build process as compilation, this stage is often referred to as compilation proper. This stage turns a .c file into an .o (object) file.
> - Linking: Here is where all of the object files and any libraries are linked together to make your final program. Note that for static libraries, the actual library is placed in your final > program, while for shared libraries, only a reference to the library is placed inside. Now you have a complete program that is ready to run. You launch it from the shell, and the program is > handed off to the loader.
> - Loading: This stage happens when your program starts up. Your program is scanned for references to shared libraries. Any references found are resolved and the libraries are mapped into your > program.

We'll start with two stories:

1. Anyone tried to run old games and ran into message like `Could not locate msvcrt97.dll/directx97.dll`?
2. Background Story: 3D Games, Static Compiling vs Dynamic Compiling (space on disk, ram)

- Demo of how it is done
- search path
- -lXXX

## Part 2.1 - Note on the extern keyword

extern changes the linkage. With the keyword, the function / variable is assumed to be available somewhere else and the resolving is deferred to the linker.
There's a difference between extern on functions and on variables.

For **_variables_** it doesn't instantiate the variable itself, i.e. doesn't allocate any memory. This needs to be done somewhere else. Thus it's important if you want to import the variable from somewhere else.

For **_functions_**, this only tells the compiler that linkage is extern. As this is the default (you use the keyword static to indicate that a function is not bound using extern linkage) you don't need to use it explicitly.
