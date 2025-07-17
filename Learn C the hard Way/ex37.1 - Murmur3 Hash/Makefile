CFLAGS = -Wall -g -Isrc 

SRC = $(wildcard src/*.c)
OBJ = $(patsubst %.c, %.o,$(SRC))

TEST_SRC = $(wildcard test/*.c)
TESTS = $(patsubst %.c,%,$(TEST_SRC))

all: compile test

compile: $(OBJ)

test: CFLAGS += $(OBJ)
test: $(TESTS) # This will automatically build the executables
	./$(TESTS) 

clean:
	del /q src\*.o
	del /q test\*.exe
