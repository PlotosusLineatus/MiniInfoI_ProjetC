#ifndef HEADER_UTILS_H /*ATTENTION A NE PAS OUBLIER _H*/
#define HEADER_UTILS_H

    //Les fonctions de bases
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

    //Les fonctions demandées pour utils
	void extract_sequence(const char* path_input, char* sequence);

	void save_sequence(const char* path_output, char* sequence);

    //Bonus: Longueur Min et Max
	typedef struct {
		int idSeq;
		int length;
	} IdLongueur ;
	
	IdLongueur min(char seq1[], char seq2[]);
	
	IdLongueur max(char seq1[], char seq2[]);

#endif
