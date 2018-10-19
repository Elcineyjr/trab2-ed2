all:
	gcc *.c TADs/*.c -o trab2 -Wall -g

clean:
	rm -f *.o trab2