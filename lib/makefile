.PHONY: clean
FUNCTION = bingo_diag_right.o bingo_diag_left.o bingo_row.o bingo_column.o bingo_print.o com_delete.o com_make.o user_delete.o user_make.o


libfuncs.a: $(FUNCTION)
	ar rv libfuncs.a $(FUNCTION)

bingo_diag_right.o: bingo_diag_right.c
	gcc -c bingo_diag_right.c -I../include

bingo_diag_left.o: bingo_diag_left.c
	gcc -c bingo_diag_left.c -I../include

bingo_row.o: bingo_row.c
	gcc -c bingo_row.c -I../include

bingo_column.o: bingo_column.c
	gcc -c bingo_column.c -I../include

bingo_print.o: bingo_print.c
	gcc -c bingo_print.c -I../include

com_delete.o: com_delete.c
	gcc -c com_delete.c -I../include

com_make.o: com_make.c
	gcc -c com_make.c -I../include

user_delete.o: user_delete.c
	gcc -c user_delete.c -I../include

user_make.o: user_make.c
	gcc -c user_make.c -I../include

clean:
	rm *.o
	rm libfuncs.a
