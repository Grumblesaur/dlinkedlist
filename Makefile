test: main.o dlinkedlist.o
	gcc main.o dlinkedlist.o -o test

main.o: main.c
	gcc -c main.c

dlinkedlist.o: dlinkedlist.c
	gcc -c dlinkedlist.c

clean:
	rm -f *.o

