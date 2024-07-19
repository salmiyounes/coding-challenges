MODULE_NAME = foo

CC = gcc
CFLAGS = -O3 -Wall
CYTHON = cython
PYTHON = python3
PYTHON_CONFIG = $(PYTHON)-config

PYTHON_INCLUDES = $(shell $(PYTHON_CONFIG) --includes)
PYTHON_LIBS = $(shell $(PYTHON_CONFIG) --libs)

TARGET = $(MODULE_NAME).so
PYX_SRC = $(MODULE_NAME).pyx
C_SRC = $(MODULE_NAME).c

all: $(TARGET)

$(TARGET): $(C_SRC)
	$(CC) $(CFLAGS) $(PYTHON_INCLUDES) -shared -fPIC -o $@ $< $(PYTHON_LIBS)

$(C_SRC): $(PYX_SRC)
	$(CYTHON) $<

clean:
	rm -f $(C_SRC) $(TARGET)

.PHONY: all clean
