#include "utils.h"

int main() {
	char seq1[]="AGFAIDNDTDZYDIZD";
	char seq2[]="OZIATDFZIZDIJD";
	double identiteSeq=scoreId(seq1,seq2);
	printf("les séquences ont un score d'indentité de %lf\n",identiteSeq);
	return 0;
}
