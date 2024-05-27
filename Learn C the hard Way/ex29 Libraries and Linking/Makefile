CFLAGS=-Wall -g -O2 -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
# The -rdynamic flag allows the compiler to output all the symbols(variables, data structures etc.) to the symbol table of the executible
# so that any dynamic libraries or when you debug using gdb, all those symbols are available for use
SOURCES=$(wildcard src/*.c)
LIB_SOURCES=$(wildcard src/libc/*.c)

OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
LIB_OBJECTS=$(patsubst %.c,%.o,$(LIB_SOURCES))

TARGET=bin/main
LIB_TARGET=build/lib.so

all: build compile $(LIB_TARGET) $(TARGET)

windows: buildw compile $(LIB_TARGET) $(TARGET)

# Cannot provide OBJECTS or LIB_OBJECTS bcz it will lead to error
# as apparently you cannot compile multiple files as give multiple outputs
compile: $(SOURCES) $(OBJECTS) $(LIB_SOURCES) $(LIB_OBJECTS)
# So it seems like that just providing these pre-requistites seem to do the work
# Still I don't understand how it works
	
$(TARGET):
	$(CC) $(SOURCES) -o $@

# ar is a UNIX command for developing archives
# ranlib is 
$(LIB_TARGET):
	ar rcs $@ $(LIB_OBJECTS)
	ranlib $@
	$(CC) -shared $(LIB_OBJECTS) -o $@

# The @ tag implies that the command should execute in the background
# and its output should not appear on the console
build:
	@mkdir -p build 
	@mkdir -p bin

buildw:
	@mkdir build
	@mkdir bin

clean:
	rm -f src/*.o
	rm -f src/libc/*.o
	rm -rf build
	rm -rf bin

# Code to convert / to \ for windows
# Just like patsubst, we have subst
WIN_SRC_OBJ=$(subst /,\,$(OBJECTS))
WIN_LIB_OBJ=$(subst /,\,$(LIB_OBJECTS))

# /Q flag is for quiet mode else it will ask permission before deleting
cleanw:
	del /q src\*.o
	del /q src\libc\*.o
	rmdir /s /q build
	rmdir /s /q bin

# NOTE : _w ending rules are for windows

# SHIT WORKS MAN!!!
# INPUT : ./bin/main build/lib.so uppercase shivang
# OUTPUT : SHIVANG