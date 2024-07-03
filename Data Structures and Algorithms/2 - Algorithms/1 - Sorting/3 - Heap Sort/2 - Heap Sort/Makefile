CFLAGS=-Wall -g -Isrc/headers -O2
LIBS=

SOURCES=$(wildcard src/*.c src/**/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TARGET=main

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LIBS)
	./$(TARGET)
	
clean:
	del /q $(TARGET).exe
	del /q src\*.o