CFLAGS=-Wall

all: main_transcription

main_transcription: main_transcription.o module_transcription.o utils.o
	gcc main_transcription.o module_transcription.o utils.o -o main_transcription

main_transcription.o : main_transcription.c
	gcc -c main_transcription.c module_transcription.c utils.c $(CFLAGS)

module_transcription.o: module_transcription.c 
	gcc -c module_transcription.c utils.c $(CFLAGS)

utils.o : utils.c 
	gcc -c utils.c $(CFLAGS)


clean:
	rm -f *.o

mrproper: clean
	rm -f main_transcription