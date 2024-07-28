# Variables
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
TARGET = test_program
SRCS = main.c sol.c
HEADERS = sol.h

# Default target
all: $(TARGET)

# Compile and link the program
$(TARGET): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Clean up generated files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
