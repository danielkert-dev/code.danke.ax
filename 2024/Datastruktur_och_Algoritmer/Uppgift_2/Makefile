CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC = $(wildcard src/*.c)

TARGET = bin/program.out

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
