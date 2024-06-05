CFLAGS=-Wall -g -Isrc/headers -O2
LIBS=

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TARGET=bin/main

all : $(TARGET)
	./$(TARGET)
debug : CLFAGS += -DNDEBUG
debug : all

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LIBS)
	
clean:
	del /q bin\*.*
	del /q src\*.o