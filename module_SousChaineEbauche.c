#include "utils.h"

char polariteSequence(char seq[600]) {
/*cette fonction renvoie la séquence protéique donnée en paramèter sous forme de séquence avec les codes des polarités des acides aminés : 1 pour les hydrophobes, 0 pour les hydrophiles, - pour les gaps*/
	char seqPol[strlen(seq)]; //séquence avec polarités
	int i=0; //variable d'incrémentation
	for (i=0;i<strlen(seq);i++) {
		if(seq[i]=='-')
			seqPol[i]='-';
		else if(seq[i]=='C')
			seqPol[i]='0';
		else if(seq[i]=='A')
			seqPol[i]='1';
		else if(seq[i]=='S')
			seqPol[i]='0';
		else if(seq[i]=='V')
			seqPol[i]='1';
		else if(seq[i]=='T')
			seqPol[i]='0';
		else if(seq[i]=='L')
			seqPol[i]='1';
		else if(seq[i]=='Y')
			seqPol[i]='0';
		else if(seq[i]=='I')
			seqPol[i]='1';
		else if(seq[i]=='N')
			seqPol[i]='0';
		else if(seq[i]=='P')
			seqPol[i]='1';
		else if(seq[i]=='Q')
			seqPol[i]='0';
		else if(seq[i]=='F')
			seqPol[i]='1';
		else if(seq[i]=='D')
			seqPol[i]='0';
		else if(seq[i]=='W')
			seqPol[i]='1';
		else if(seq[i]=='E')
			seqPol[i]='0';
		else if(seq[i]=='M')
			seqPol[i]='1';
		else if(seq[i]=='K')
			seqPol[i]='0';
		else if(seq[i]=='G')
			seqPol[i]='1';
		else if(seq[i]=='R')
			seqPol[i]='0';
		else if(seq[i]=='H')
			seqPol[i]='0';
	}
	return seqPol;
