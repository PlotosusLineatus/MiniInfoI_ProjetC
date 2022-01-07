CFLAGS=-Wall

all: mainNBRB

mainNBRB: mainNBRB.o module_SequenceCodante.o module_transcription.o module_traduction.o utils.o module_ScoreIdentite.o module_SimilariteSequences.o module_Consensus.o
	gcc mainNBRB.o module_SequenceCodante.o module_transcription.o module_traduction.o module_ScoreIdentite.o module_SimilariteSequences.o module_Consensus.o utils.o -o ProgrammeNBRB

mainNBRB.o: mainNBRB.c module_SequenceCodante.c module_transcription.c module_traduction.c module_ScoreIdentite.c module_SimilariteSequences.c module_Consensus.c utils.c
	gcc -c mainNBRB.c module_SequenceCodante.c module_transcription.c module_traduction.c module_ScoreIdentite.c module_SimilariteSequences.c module_Consensus.c utils.c $(CFLAGS)

module_SequenceCodante.o:module_SequenceCodante.c 
	gcc -c module_SequenceCodante.c utils.c $(CFLAGS)

module_transcription.o: module_transcription.c 
	gcc -c module_transcription.c utils.c $(CFLAGS)

module_traduction.o:module_traduction.c 
	gcc -c module_traduction.c utils.c $(CFLAGS)

module_ScoreIdentite.o:module_ScoreIdentite.c 
	gcc -c module_ScoreIdentite.c utils.c $(CFLAGS)

module_SimilariteSequences.o:module_SimilariteSequences.c 
	gcc -c module_SimilariteSequences.c utils.c $(CFLAGS)

module_Consensus.o:module_Consensus.c 
	gcc -c module_Consensus.c utils.c $(CFLAGS)
	
utils.o : utils.c 
	gcc -c utils.c $(CFLAGS)


clean:
	rm -f *.o

mrproper: clean
	rm -f mainNB
