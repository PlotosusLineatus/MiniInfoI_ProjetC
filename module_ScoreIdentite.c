#include "utils.h"
#include "module_ScoreIdentite.h"


void scoreId(char seq1[], char seq2[]) {
	/*Cette procédure renvoie le score d'identité entre deux séquences, donc le pourcentage d'acides aminés ou de nucléotides présents à la même place dans les deux séquences*/
	
	int n=strlen(seq1); //taille des séquences
	int nbId=0; //nombre de résidus identiques
	char idSeq[n]; //chaine de caractère qui retient où sont les identités de séquence et qui elles sont
	
	for (int i=0;i<n;i++) {
		if(seq1[i]==seq2[i] && seq1[i]!='-'){
			nbId+=1; //une identité trouvée
			idSeq[i]=seq1[i]; //on note l'identité à sa place dans la séquence identité
		}
		else 
			idSeq[i]='-'; //il n'y a pas d'identité, on met donc un gap
	}
		
	double nombreId=nbId;
	double nbChar=n;
	double scoreIdentite=(nombreId/nbChar); //on calcule le pourcentage d'identité
		
	printf("\nIdentité de séquence: %d/%d soit %lf%%\n",nbId,n,scoreIdentite*100);
	
	printf("seq1 ");
	for (int k=0;k<n;k++) 
		printf("%c",seq1[k]);
		
	printf("\nseq2 ");
	for (int l=0;l<n;l++) 
		printf("%c",seq2[l]);
			
	printf("\n-id- ");
	for (int j=0;j<n;j++) 
		printf("%c",idSeq[j]);
		
	printf("\n");
}


void module_ScoreIdentite() {
	printf("\n\033[34;01mBienvenue dans le module 4: Calcul du score d'identité entre 2 séquences\033[00m\n\n");
    printf("Quels sont les fichiers contenant les séquences dont vous voulez savoir le score d'identité? (Attention, les séquences doivent avoir la même taille.)\nséquence 1 : ");
    char *path_input1=NULL ;
    scanf("%s",path_input1);
    
    printf("\n\nséquence 2 : ");
    char *path_input2=NULL;
    scanf("%s",path_input2);
    
    Seq1Seq2 sequences=recupereSeq1Seq2(path_input1, path_input2);
    
    if (sequences.memeLongueur=='N') 
    	printf("\n\nERREUR.\nLes séquences doivent avoir la même taille.");
    
    else
    	scoreId(sequences.seq1, sequences.seq2);
}
