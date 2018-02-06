CC = gcc
CFLAGS = -O4 -Wall 

all: wash 

wash: wash.c 
	$(CC) $(CFLAGS) -o wash wash.c 

clean:
	rm -f *.o wash *~ x xd

print:
	a2ps -L72 --delegate=no -T 4 -q -Avirtual -2 -o xd wash.c 

