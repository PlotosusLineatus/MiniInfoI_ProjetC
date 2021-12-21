#include "utils.h"

void extract_sequence(const char* path_input, char* sequence) {
	/*cette procédure récupère la séquence fasta simplifiée et la met dans sequence*/
	FILE* fasta = fopen(path_input,"r");
            if(!fasta){
                printf("L'ouverture a echoue. \n");
                exit(EXIT_FAILURE);
        }
	char c;
	int indice=0;
	while((c=fgetc(fasta))!=EOF) {
		if (c!='\n')
			sequence[indice]=c;
		indice++;
	}
}

void save_sequence(const char* path_output, char* sequence){
/* Cette procedure sauvegarde la sequence donnee afin de faciliter la lecture */
    FILE* fp= fopen(path_output, "w");
        if(!fp){
                printf("L'ouverture a echoue. \n");
                exit(EXIT_FAILURE);
        }
        int i=0;
        int compteurCaractere =0 ; /*permet de faire les retours a la ligne tous les 80 caracteres*/
        while(sequence[i]!='\0'){
                if (compteurCaractere==80){
                        fprintf(fp,"\n");
                        compteurCaractere = 0;
                        i++;
                }
                else{
                        fprintf(fp,"%c",sequence[i]);
                        compteurCaractere++;
                        i++;
                }
        }
    fclose(fp);
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
