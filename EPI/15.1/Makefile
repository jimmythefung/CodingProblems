CC  = gcc
CXX = g++ -std=c++11

# Let’s leave a place holder for additional include directories

INCLUDES =

# Compilation options:
# -g for debugging info and -Wall enables all warnings

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

# Linking options:
# -g for debugging info

LDFLAGS = -g

# List the libraries you need to link with in LDLIBS
# For example, use "-lm" for the math library

LDLIBS =


main: main.o mybst.o
	$(CXX) -o main main.o mybst.o
	rm *.o

$main.o: main.cpp mybst.h
$mybst.o: mybst.cpp mybst.h

.PHONY: clean
clean:
	rm -f *.o a.out core main

.PHONY: all
all: clean main

.PHONY: run
run: clean main
	valgrind --leak-check=yes ./main
