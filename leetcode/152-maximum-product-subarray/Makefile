# Variables
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11 -g
TARGET = main
OBJS = main.o sol.o

# Default target
all: $(TARGET)

# Link the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile the main.c file
main.o: main.c sol.h
	$(CC) $(CFLAGS) -c main.c

# Compile the sol.c file
sol.o: sol.c sol.h
	$(CC) $(CFLAGS) -c sol.c

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
