CFLAGS = -Wall -g -Isrc
LIBS =

SRC= $(wildcard src/*.c)
OBJS= $(patsubst %.c, %.o, $(SRC))

TEST_SRC = $(wildcard test/*_tests.c)
# The spaces you leave below will actually be appended in the result
# TEST = $(patsubst %.c, %, $(TEST_SRC)), this won't work but the below works
TEST = $(patsubst %.c,%,$(TEST_SRC)) 

TARGET = main

all: compile link
	./$(TARGET)

compile: $(OBJS)

link:
	$(CC) $(OBJS) -o $(TARGET) $(LIBS)

test: $(TEST)
	./$(TEST)

cleanw:
	del /q src\*.o
	del /q $(TARGET).exe
	del /q test\*.exe

clean:
	rm -f src/*.o
	rm -f $(TARGET)
	rm -f $(TEST)