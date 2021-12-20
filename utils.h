#ifndef HEADER_UTILS 
#define HEADER_UTILS
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	//void extract_sequence(const char* path_input, char* sequence);
	double scoreId(char seq1[], char seq2[]);
	
	typedef struct {
		int idSeq;
		int length;
	} IdLongueur ;
	
	IdLongueur min(char seq1[], char seq2[]);
	
	IdLongueur max(char seq1[], char seq2[]);
#endif
