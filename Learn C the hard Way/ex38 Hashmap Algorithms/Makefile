CFLAGS=-g -O2 -Wall -Wextra -Isrc -DNDEBUG $(OPTFLAGS)
LIBS=-ldl -lbsd $(OPTLIBS)
PREFIX?=/usr/local

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SRC=$(wildcard test/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

TARGET=build/liblcthw.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# The Target Build
all: $(TARGET) $(SO_TARGET) tests
dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all

$(TARGET): CFLAGS += -fPIC
$(TARGET): buildw $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@
$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

# -p flag check if the directory already exists then throws no error
build:
	@mkdir -p build
	@mkdir -p bin

buildw:
	mkdir build
	mkdir bin

# The Unit Tests
# Changing the CFLAGS += $(TARGET) to the $(OBJECTS) seems to do the job
.PHONY: tests
tests: CFLAGS += $(OBJECTS) 
tests: $(TESTS)
	./$(TESTS)
	sh ./tests/runtests.sh

# The Cleaner
clean:
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rm `find . -name "*.dSYM" - print`

# /q suggest quiet mode and /s means delete everything including subdirectories
cleanw:
	del /q src\*.o
	del /q src\lcthw\*.o
	del /q test\*.exe
	rmdir /q bin
	rmdir /q/s build

# The Install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

# The Checker
check:
	@echo Files with potentially dangerous functions.
	@egrep '[^_.a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)\
			|stpn?cpy|a?sn?printf|byte_)' $(SOURCES) || true