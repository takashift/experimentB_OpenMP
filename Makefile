CC=gcc
CFLAGS=-Wall -fopenmp
TARGETS=hello_world reduction matrix_add

all: $(TARGETS)

reduction: reduction.c
	$(CC) $(CFLAGS) reduction.c -o reduction

clean:
	$(RM) $(TARGETS)

.PHONY: all clean
