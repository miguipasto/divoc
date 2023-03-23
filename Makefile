all: divoc

inout.o: inout.c inout.h
	gcc -Wall -c inout.c

database.o: database.c database.h
	gcc -Wall -c database.c

divoc: inout.o database.o divoc.c
	gcc -Wall inout.o database.o divoc.c -o divoc

clean:
	rm -f divoc *.o *.bak *~
