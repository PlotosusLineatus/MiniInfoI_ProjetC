#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void seqConsensus(char align[40], FILE * cons) {
	/*ce module recherche la séquence consensus dans un fichier d'alignement de séquences. Il renvoie une séquence consensus avec un code comme suit :
	à chaque position,
	caractère : caractère conservé
	* : caractère retriuvé dans au moins 80% des séquences alignées
	- : caractère retruové dans au moins 60% des séquences alignées
	  : pas de caractère présent en majorité */
	FILE * aliSeq=fopen(align,"r");
	
	char tableau[10001][30]; //stockage des séquences
	char car; //caractère retrouvé dans le fichier
	int l=0; //lignes
	int c=0; //colonnes
	while((car=fgetc(aliSeq))!='\n') {
		tableau[l][c]=car;
		c++;
	}
	/*on a remplit la première séquence. on passe aux prochaines*/
	l++; 
	int cmax=c;
	char seq[cmax];
	
	while(fscanf(aliSeq, "%s",seq)!=EOF) {
		int i=0;
		c=0; //on se met au début de la séquence que l'on remplit
		for(i=0;i<cmax;i++) {
			tableau[l][c]=seq[i]; //on remplit le tableau
			c++; //on passe au caractère suivant
		}
		l++; //on passe à la séquence suivante
	}
	
	int lmax=l;
	c=0;
	l=0;
	
	/*on va rechercher colonne par colonne (donc place par place) les pourcentages de caractères identiques*/
	int marqueurFin=0;
	int k=l+1; //ligne de tableau autre que l
	double nbOccur=1; //nombre d'occurences du caractère testé (au moins 1)
	double nbOccurTot=0; //somme des occurences de caractères
	double nbLignes=lmax;
	char code; //ce qui sera écrit à chaque place sur la séquence consensus (char,*,-, )
	int ligneCompte=0; 
	for(c=0;c<cmax;c++) { 
		l=0;
		k=l+1;
		nbOccur=1;
		nbOccurTot=0;
		code=' '; //par défaut, modifié si on trouve un caractère majoritaire
		marqueurFin=0;	
		printf("\n%d\n",c);
		while(marqueurFin==0) {
					
			if (tableau[l][c]==tableau[k][c]) {
				nbOccur+=1;	
				if (l==(k-1)) {
					l=k; //si on réaugmente l, on ne prendra pas le même caractère que précédemment
				}	
				
				if((nbOccur/nbLignes)>=0.60){
				/*occurence d'un caractère à 60% ou plus*/
					code='-'; //on ne sais pas encore si l'occurence se fait à plus de 60%
					marqueurFin=1;
					printf("\non a cas %c majo et k=%d\n",tableau[l][c],k);
					/*on a trouvé un caractère majoritaire*/
				}
					
			}
			k++; //on teste une nouvelle ligne
			//printf("essai\n k=%d\n",k);
			
			
			if (k>=lmax) {
				printf("\n%c k>lmax   nbOccur %lf\n",tableau[l][c],nbOccur);
				l++; //on teste un nouveau caractère, le précédent n'est pas majoritaire
				k=l+1;
				nbOccurTot+=nbOccur;
				nbOccur=1;//on va compter le nombre d'occurences du nouveau caractère testé
				if (nbOccurTot/nbLignes>0.4) {
				/*plus de 40% des caractères ont été vus, il n'y aura donc pas d'occurence d'un résidu à 60% ou plus*/
				//code=' ';
				marqueurFin=1;	
				}	
			}	
			
		}
		
		if (code=='-')  {
			/*on continue de compter les occurences du caractère majoritaire*/
			printf(" \ncas majo %c k= %d nbOccu=%lf\n",tableau[l][c],k,nbOccur);
			for (ligneCompte=k;ligneCompte<lmax;ligneCompte++) {
				if (tableau[l][c]==tableau[ligneCompte][c]) 
					nbOccur+=1;	
			}
			printf("\nvrai nbOccur=%lf\n",nbOccur); 
			if ((nbOccur/nbLignes)>=0.8) {
				code='*';
				if ((nbOccur/nbLignes)==1)
					code=tableau[l][c];
			}
		}
		
		printf("\n%c\n",code);
		
	}
	
}


int main() {
	printf("\nVous pouvez indiquer le nom du fichier d'alignement de séquence ci-dessous.\n\nAttention: le fichier doit contenir un maximum de 30 séquences d'au plus 10000 caractères chacune\n\nnom du fichier: ");
	char align[40];
	scanf("%s",align);
	FILE * seqCons=fopen("consensus.txt","w");
	seqConsensus(align, seqCons);
	return 0;
}
