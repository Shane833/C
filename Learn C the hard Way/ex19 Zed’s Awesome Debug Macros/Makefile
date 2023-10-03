all: compile

# Compiler
CC = gcc
# Source File
SRC = main.c
# Output File
OUT = main
# Compilation Flags
CFLAGS = -Wall -g

# You can define certain variables while compiling a program by using the -D flag
# Usage -D variable_name

# Compiling
compile:
	$(CC) $(CFLAGS) $(SRC) -DNDEBUG -o $(OUT)

# Cleaning
clean:
	rm -f $(OUT)