#include "utils.h"
#include "module_SimilariteSequences.h"


void scoreSimil(char seq1[], char seq2[]) {
	/*Cette procédure permet de calculer le score de similarité de polarité entre deux séquences et renvoie un affichage lié*/
	
	/*définition des polarités de sacides aminés : 
A, V, L, I, P, F, W, M, G sont hydrophobes  
C, S, T, Y, N, Q, D, E, K, R, H sont hydrophiles */
	char hydrophobe[10]="AVLIPFWMG"; //LISTE DES ACIDES AMINÉS HYDROPHOBES
	/*char hydrophile[12]="CSTYNQDEKRH"; //liste des acides aminés hydrophiles*/
	
	int n=strlen(seq1); //longueur des séquences
	int i; //variable d'incrémentation
	int nbSimil=0; //nombre de similarités de polarité retrouvées
	
	char similPol[n]; //retiendra les similarités de polarité
	
	for (i=0;i<n;i++) {
	
		if (seq1[i]=='-' || seq2[i]=='-')
		/*au moins l'un des acides aminés à la position i dans les séqueces est en fait un gap donc ni un acide aminé hydrophobe ni hydrophile*/
			similPol[i]='-';
		
		else {
			
			if (seq1[i]==hydrophobe[0] || seq1[i]==hydrophobe[1] || seq1[i]==hydrophobe[2] || seq1[i]==hydrophobe[3] || seq1[i]==hydrophobe[4] || seq1[i]==hydrophobe[5] || seq1[i]==hydrophobe[6] || seq1[i]==hydrophobe[7] || seq1[i]==hydrophobe[8]) {
			/* acide aminé i de la séquence 1 hydrophobe*/
				if (seq2[i]==hydrophobe[0] || seq2[i]==hydrophobe[1] || seq2[i]==hydrophobe[2] || seq2[i]==hydrophobe[3] || seq2[i]==hydrophobe[4] || seq2[i]==hydrophobe[5] || seq2[i]==hydrophobe[6] || seq2[i]==hydrophobe[7] || seq2[i]==hydrophobe[8]) {
				/*acide aminé i de la séquence 2 hydrophobe*/
					similPol[i]='1';
					nbSimil+=1; //une similarité trouvée
				}
				else {
				/*acide aminé i de la séquence 2 hydrophile*/
					similPol[i]='-';
				}
			}
			
			else {
			/* acide aminé i de la séquence 1 hydrophile*/
				if (seq2[i]==hydrophobe[0] || seq2[i]==hydrophobe[1] || seq2[i]==hydrophobe[2] || seq2[i]==hydrophobe[3] || seq2[i]==hydrophobe[4] || seq2[i]==hydrophobe[5] || seq2[i]==hydrophobe[6] || seq2[i]==hydrophobe[7] || seq2[i]==hydrophobe[8]) {
				/*acide aminé i de la séquence 2 hydrophobe*/
					similPol[i]='-';
				}
				else {
				/*acide aminé i de la séquence 2 hydrophile*/
					similPol[i]='0';
					nbSimil+=1; //une similarité trouvée
				}
			}
		}
	}
	
	
	/*affichage des résultats*/
	
	double longueur=n;
	double similNb=nbSimil;
	double scoreSimil=similNb/longueur; //calcul du score de similarité de polarité
	
	printf("\nSimilarité de polarité: %d/%d soit %lf%%\n",nbSimil,n,scoreSimil*100);
	
	printf("\n0: hydrophiles  1: hydrophobes  -:différents (ou gap)\n\n");
	
	printf("seq1 :       ");
	for (i=0;i<n;i++) {
		printf("%c",seq1[i]);
	}
	
	printf("\nseq2 :       ");
	for (i=0;i<n;i++) {
		printf("%c",seq2[i]);
	}
	
	printf("\nsimilarité : ");
	for (i=0;i<n;i++) {
		printf("%c",similPol[i]);
	}
	printf("\n");
}

void module_ScoreSimilaritePolarite(){
    printf("\n\033[34;01mBienvenue dans le module 5: Calcul du score de similarité de polarité entre 2 séquences\033[00m\n\n");
    printf("Quels sont les fichiers contenant les séquences dont vous voulez savoir le score de similarité de polarité ? (Attention, les séquences doivent avoir la même taille.)\n\nséquence 1 : ");
    char input1[40] ;
    scanf("%s",input1);
    
    printf("\n\nséquence 2 : ");
    char input2[40];
    scanf("%s",input2);
     
    const char* path_input1=input1;
    const char* path_input2=input2;
    
    Seq1Seq2 sequences=recupereSeq1Seq2(path_input1, path_input2);
    
    if (sequences.memeLongueur=='N') 
    	printf("\n\nERREUR.\nLes séquences doivent avoir la même taille.");
    
    else
    	scoreSimil(sequences.seq1, sequences.seq2);
}
