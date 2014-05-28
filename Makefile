CC=gcc
CFLAGS=-Wall -fopenmp
TARGETS=hello_world reduction laplace function matrix_product

all: $(TARGETS)

reduction: reduction.c
	$(CC) $(CFLAGS) reduction.c -o reduction

hello_world: hello_world.c
	$(CC) $(CFLAGS) hello_world.c -o hello_world

laplace: laplace.c
	$(CC) $(CFLAGS) laplace.c -o laplace -lm

function: function.c
	$(CC) $(CFLAGS) function.c -o function -lm

matrix_product: function.c
	$(CC) $(CFLAGS) matrix_product.c -o matrix_product

clean:
	$(RM) $(TARGETS)

.PHONY: all clean
