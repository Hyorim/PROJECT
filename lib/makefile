.PHONY: clean
FUNCTION = bingo_diag_right.o bingo_diag_left.o bingo_row.o bingo_column.o com_delete.o com_make.o user_delete.o user_make.o

libfuncs.a: $(FUNCTION)
	ar rv libfuncs.a $(FUNCTION) -I../include

bingo_diag_right.o: bingo_diag_right.c bingo_diag_right.h
	gcc -c bingo_diag_right.c -I../include

bingo_diag_left.o: bingo_diag_left.c bingo_diag_left.h
	gcc -c bingo_diag_left.c -I../include

bingo_row.o: bingo_row.c bingo_row.h
	gcc -c bingo_row.c -I../include

bingo_column.o: bingo_column.c bingo_column.h
	gcc -c bingo_column.c -I../include

bingo_print.o: bingo_print.c bingo_print.h
	gcc -c bingo_print.c -I../include

com_delete.o: com_delete.c com_delete.h
	gcc -c com_delete.c -I../include

com_make.o: com_make.c com_make.h
	gcc -c com_make.c -I../include

user_delete.o: user_delete.c user_delete.h
	gcc -c user_delete.c -I../include

user_make.o: user_make.c user_make.h
	gcc -c user_make.c -I../include

clean:
	rm *.o
	rm libfuncs.a
