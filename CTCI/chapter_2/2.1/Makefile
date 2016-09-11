# File name is the problem number

FILENAME = main

# We’ll use gcc for C compilation and g++ for C++ compilation

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

# The 1st target gets built when you type "make".

$(FILENAME): $(FILENAME).o mylist.o
	$(CXX) -o $(FILENAME) $(FILENAME).o mylist.o
	rm *.o

# Object files dependencies

$(FILENAME).o: $(FILENAME).cpp mylist.h
#main.o: main.c myadd.h
$mylist.o: mylist.cpp mylist.h


# Always provide the "clean" target that removes intermediate files.

.PHONY: clean
clean:
	rm -f *.o a.out core $(FILENAME)

# "all" target is useful if your Makefile builds multiple programs.
# Here we’ll have it first do "clean", and rebuild the main target.

.PHONY: all
all: clean $(FILENAME)

.PHONY: run
run: clean main
	valgrind --leak-check=yes ./main
