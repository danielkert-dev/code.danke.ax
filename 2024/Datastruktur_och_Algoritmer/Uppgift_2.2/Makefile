# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -Iinclude
# Source files
SRC = $(wildcard src/*.c)
# Target executable
TARGET = bin/program.out

# Default rule
all: $(TARGET)

# Rule to build the executable directly from .c files
$(TARGET): $(SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

run: all
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET)

test: all run clean

#! Kör "make test" att testa programmet