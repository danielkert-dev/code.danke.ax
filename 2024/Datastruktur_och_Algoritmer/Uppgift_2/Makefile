CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC = $(wildcard src/*.c)

ifeq ($(OS),Windows_NT)
    TARGET = bin/program.exe
else
    TARGET = bin/program.out
endif

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

run: all
	./$(TARGET)

clean:
	@echo "-------------------------"
	rm -f $(TARGET)

test: all run clean
