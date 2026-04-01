CFLAGS=-Wall -Wextra -Wpedantic -ggdb -O2 -std=c23 -Isrc 
SANITIZE=-fsanitize=undefined -fsanitize-trap

SRC = $(wildcard src/*.c)
OBJ = $(patsubst %.c,%.o, $(SRC))

TEST_SRC = $(wildcard tests/*.c)
TESTS = $(patsubst %.c,%, $(TEST_SRC))

TARGET = logfind

all: compile test

compile: $(OBJ) src/path.h src/file.h

link:
	$(CC) $(SANITIZE) $(OBJ) -o $(TARGET) 

test: CFLAGS+=$(OBJ)
test: $(TESTS)
	./$(TESTS)

clean:
	-rm src/*.o
	-rm *.exe
	-rm tests/*.exe
