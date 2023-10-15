all: compile link

# Source Files
Src1 = ex22.c
Src2 = main.c

# Object Files
Obj = ex22.o

# Output File
OUT = main

# Compiler
CC = gcc

# Compilation flags
CFLAGS = -Wall -g

# Definitions
DEF = -DNDEBUG

# Compiling into object files
compile:
	$(CC) $(CFLAGS) $(DEF) -c $(Src1) -o $(Obj) 

# Linking with our main file
link:
	$(CC) $(CFLAGS) $(DEF) $(Src2) $(Obj) -o $(OUT)
	
	