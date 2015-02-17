CC=g++
CFLAGS = -c -Wall
LDFLAGS =
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
MAIN = Main
EXECUTABLE = log2810-tp1


PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< $@

clean:
	$(RM) *.o
