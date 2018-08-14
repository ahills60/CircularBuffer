# Build an executable name cbuffer from main and circularbuffer.c

all: circularbuffer.c main.c
	gcc -g -Wall -o cbuffer circularbuffer.c main.c

clean:
	$(RM) cbuffer
