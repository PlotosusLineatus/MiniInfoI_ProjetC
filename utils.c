#include "utils.h"

/*je n'ai pas testé la procédure*/
void extract_sequence(const char* path_input, char* sequence) {
	/*cette procédure récupère la séquence fasta simplifiée et la met dans sequence*/
	FILE * fasta = fopen(path_input,"r");
	char c;
	int indice=0;
	while((c=fgetc(fasta))!=EOF) {
		if (c!='\n')
			sequence[indice]=c;
		indice++;
	}
}


double scoreId(char seq1[], char seq2[]) {
	/*Cette fonction renvoie le score d'identité entre deux séquences, donc le pourcentage d'acides amnés ou de nucléotides présents à la même place dans les deux séquences*/
	int lMin=min(seq1,seq2).length; //longueur de la plus petite sequence
	double lMax=max(seq1,seq2).length; //longueur de la plus grande sequence
	double nbId=0; //nombre de résidus identiques
	for (int i=0;i<lMin;i++) {
		if(seq1[i]==seq2[i])
			nbId+=1; //une identité trouvée
	}
	double scoreIdentite=(nbId/lMax);
	printf("nbId= %lf lMax=%lf\nscoreIdentite=%lf\n",nbId, lMax, scoreIdentite);
	return scoreIdentite;
}
		
		
		
		
IdLongueur min(char seq1[], char seq2[]) {
	/*cette fonction retourne l'identifiant de la séquence la plus courte et sa longueur: 1 si c'est seq1, et 2 si c'est seq2. Si les séquences ont même longueur, la fonction renvoie 2 par défaut*/
	IdLongueur seqPlusCourte;
	int lenSeq1=strlen(seq1); //on calcule la longueur de seq1
	int lenSeq2=strlen(seq2);
	seqPlusCourte.idSeq=2; //par défaut
	seqPlusCourte.length=lenSeq2;
	if (lenSeq1<lenSeq2) { 
		seqPlusCourte.idSeq=1; 
		seqPlusCourte.length=lenSeq1;
	}
	return seqPlusCourte;
}

IdLongueur max(char seq1[], char seq2[]) {
	/*cette fonction retourne l'identifiant de la séquence la plus longue et sa longueur : 1 si c'est seq1, et 2 si c'est seq2. Si les séquences ont même longueur, la fonction renvoie 1 par défaut*/
	IdLongueur seqPlusLongue;
	int lenSeq1=strlen(seq1); //on calcule la longueur de seq1
	int lenSeq2=strlen(seq2);
	seqPlusLongue.idSeq=1; //par défaut
	seqPlusLongue.length=lenSeq1;
	if (lenSeq1<lenSeq2) { 
		seqPlusLongue.idSeq=2; 
		seqPlusLongue.length=lenSeq2;
	}
	return seqPlusLongue;
}
	



	
