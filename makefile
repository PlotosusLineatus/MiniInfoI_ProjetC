CFLAGS=-Wall

all: mainNB

mainNB: mainNB.o module_SequenceCodante.o module_transcription.o module_traduction.o utils.o
	gcc mainNB.o module_SequenceCodante.o module_transcription.o module_traduction.o utils.o -o ProgrammeNB

mainNB.o: mainNB.c module_SequenceCodante.c module_transcription.c module_traduction.c utils.c
	gcc mainNB.c module_SequenceCodante.c module_transcription.c module_traduction.c utils.c $(CFLAGS)

module_SequenceCodante.o:module_SequenceCodante.c 
	gcc -c module_SequenceCodante.c utils.c $(CFLAGS)

module_transcription.o: module_transcription.c 
	gcc -c module_transcription.c utils.c $(CFLAGS)

module_traduction.o:module_traduction.c 
	gcc -c module_traduction.c utils.c $(CFLAGS)

utils.o : utils.c 
	gcc -c utils.c $(CFLAGS)


clean:
	rm -f *.o

mrproper: clean
	rm -f mainNB