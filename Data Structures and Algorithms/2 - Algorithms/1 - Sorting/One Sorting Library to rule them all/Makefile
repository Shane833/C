CFLAGS=-Wall -g -Isrc -O2 
LIBS=-ldl

SOURCES=$(wildcard src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TARGET=main

TEST=$(wildcard test/*_tests.c)
TEST_OBJ=$(patsubst %.c,%.o,$(TEST))
TESTS=$(patsubst %.c,%,$(TEST))

tests: all
	$(CC) $(TEST_OBJ) $(OBJECTS) -o $(TESTS)
	./$(TESTS)

all: $(OBJECTS) $(TEST_OBJ)
	
clean:
	del /q src\*.o
	del $(TARGET).exe
	del /q test\*.exe
	del /q test\*.o
	
	
