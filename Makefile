all:
	gcc *.c TADs/*.c -o trab2 -g -O2 -w

clean:
	rm -f trab2