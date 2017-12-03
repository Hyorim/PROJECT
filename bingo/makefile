.PHONY: clean

bingo: main.o
	gcc -o bingo -L../lib main.o -lfuncs
	
main.o: main.c
	gcc -c -I../include main.c -o main.o

clean:
	rm main.o bingo
