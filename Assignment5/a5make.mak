a5: main.o list.o
	gcc -o a5 main.o list.o
main.o: main.c
	gcc -c main.c list.h
list.o: list.c
	gcc -c list.c list.h