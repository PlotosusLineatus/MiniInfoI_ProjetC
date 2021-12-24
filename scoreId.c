#include <stdio.h>
#include <string.h>


double scoreId(char seq1[], char seq2[]) {
	/*Cette fonction renvoie le score d'identité entre deux séquences, donc le pourcentage d'acides aminés ou de nucléotides présents à la même place dans les deux séquences
Attention : les séquences doivent être de même taille car obtenues par alignement multiple*/
	if (strlen(seq1)!=strlen(seq2)) { //dans le cas où les séquences n'ont pas la même taille
		printf("ERREUR \nles séquences doivent être de même taille.\n");
		return(-1); //on arrête tout : il faut recommencer avec de bonnes séquences
	}
	double nbId=0; //nombre de résidus identiques
	for (int i=0;i<strlen(seq1);i++) {
		if(seq1[i]==seq2[i])
			nbId+=1; //une identité trouvée
	}
	double scoreIdentite=(nbId/strlen(seq1)); //on calcule le pourcentage d'identité
	return scoreIdentite;
}

int main() {
	char seq1[]="AGHIAJHDATFADR";
	char seq2[]="AOD0ODZUAT";
	char seq3[]="IDEUZO--AFFADG";
	
	double score=scoreId(seq1,seq3);
	if (score==-1) //si les séquences mises en paramètre ne sont pas de même taille
		return 1; //on arrête tout : il faut recommencer avec de bonnes séquences
	printf("les séquences ont un score de %lf\n",score);
	
	double score1=scoreId(seq1,seq2);
	if (score1==-1)
		return 1;
	printf("les séquences ont un score de %lf\n",score1);
	return 0;
}
