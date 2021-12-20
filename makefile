all : xect

xect : main.o utils.o
	gcc main.o utils.o -o xect

main.o : main.c utils.h
	gcc -c main.c -Wall
	
utils.o : utils.h utils.c
	gcc -c utils.c -Wall
