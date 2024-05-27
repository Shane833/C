CFLAGS=-Wall -g -Wextra -O2 -rdynamic


TARGET=main
SOURCES=main.c
OBJECTS=main.o

all: $(TARGET)

$(TARGET):build $(SOURCES) 
	@echo "Building the executibles"
	$(CC) $(OBJECTS) -o $(TARGET)

build:
	@echo "Compiling into objects"
	$(CC) $(SOURCES) -c $(OBJECTS)
	
clean: 
	del $(TARGET).exe
	del $(OBJECTS)