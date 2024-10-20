# Variables
CC = gcc           # Compiler
CFLAGS = -Wall -g  # Compilation flags: show warnings, include debugging info
SRCS = $(wildcard *.c)  # All .c files
EXES = $(patsubst %.c, %, $(SRCS))  # Executable names (without .c)

# Default target: compile all .c files into individual executables
all: $(EXES)

# Rule to compile each .c file into an executable
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean up compiled files
clean:
	rm -f $(EXES)
	
# Phony targets
.PHONY: all clean
