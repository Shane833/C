CFLAGS=-Wall -g -Isrc -O2 $(OPTFLAGS)

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TARGET=main

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
	
clean:
	del /q src\*.o
	del $(TARGET).exe