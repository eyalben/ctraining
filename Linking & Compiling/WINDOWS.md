# .lib is a collection of .obj files and should have be treated equally

.text: Code 
.data: Initialized data
.bss: Uninitialized data
.rdata: Const/read-only (and initialized) data
.edata: Export descriptors
.idata: Import descriptors
.reloc: Relocation table (for code instructions with absolute addressing when
          the module could not be loaded at its preferred base address)
.rsrc: Resources (icon, bitmap, dialog, ...)
.tls: __declspec(thread) data (Fails with dynamically loaded DLLs -> hard to find bugs)

CFFExplorer


##############################
.reloc - A table that maps what we need to change when loading the binary to the non ordinal location.
#####




# Intro
/c		Compile without linking
/E, /EP, /P	Preprocess without compiling or linking
/Zg		Generate function prototypes
/Zs		Check syntax



# Precompile only
cl /P one.c




# Build objects
cl /c one.c 
cl /c main.c



###
###
LIB (lib.exe) is used to create static libraries
LINK (link.exe /DLL) is used to create dynamic libraries (it creates the .dll and an import library .lib).
###
###

# Compiler verifies the signature only on compile, on linking only symbol is verified

# Link
cl one.obj main.obj 
cl one.obj /link main.lib
link one.obj main.obj
# Also demonstrate one of the files only



# Create static object
lib one.obj


# Create DLL
cl /LD one.c

# We can now see the imports and exports
dumpbin /IMPORTS one.dll
dumpbin /EXPORTS one.dll



# Compile against library
cl main.c one.lib

# We can now see the imports 
dumpbin /IMPORTS one.dll


# DUMPBIN
dumpbin /SYMBOLS main.obj
> We can see UDNEF on hello()
dumpbin /ALL main.obj /OUT:main.dumpbin.txt
dumpbin /ALL one.lib /OUT:one.dumpbin.txt






# nm
# objdump
# readelf
# ldd