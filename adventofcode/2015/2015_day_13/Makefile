CC = gcc
CFLAGS = -Wall -std=c99
TARGET = lookandsay
SRCS = sol.c split.c
HEADERS = split.h
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC)  -o $(TARGET) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC)  -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) 
