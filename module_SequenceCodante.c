#include "utils.h"
#include "module_SequenceCodante.h"

void inversionChaine(char* sequence){
    int k,n; //compteurs
    char nucleo; //stocke le nucleotide afin de ne parcourir que la moitié de la chaine

    n=strlen(sequence);

    for(k=0;k<n/2;k++){
        nucleo=sequence[k];
        sequence[k]=sequence[n-k-1]; //-1 car on ne veut pas que le \0 change de place!
        sequence[n-k-1]=nucleo;
    }
    printf("La sequence a ete inversee.\n");
}
void Complementaire(char* sequence){
    int i,n;

    n= strlen(sequence);

    for (i=0;i<n;i++){
        if (sequence[i]=='A'){
            sequence[i]='T';
        }
        else if (sequence[i]=='T'){
            sequence[i]='A';
        }
        else if (sequence[i]=='C'){
            sequence[i]='G';
        }
        else{
            sequence[i]='C';
        }
    }
    printf("La séquence est maintenant rendue complémentaire.\n");    
}

char* EcritureSequence(char* sequence, int debut, int fin){
    char SequenceOrf[10000];
    int i,j; //stocke la sequence codante
    for(i=debut; i=fin; i++){
    SequenceOrf[j]=sequence[i];
    j++;
    }
    printf("La séquence a été stockée \n");
    return(SequenceOrf);
}

void SauvegardePlusGrande(char* sequence1, char* sequence2, const char* path_output){
    if(strlen(sequence1)>strlen(sequence2)){
    save_sequence(path_output,sequence1);
}
else{
    save_sequence(path_output,sequence2);
}

}

void ChercheSeq(const char* path_output,char *sequence){

//Initialisation des variables
    int i=0; //compteur de la sequence d'interêt
    int j=0; //compteur de l'ORF (pour la sauvegarde)
    int k=0; //compteur de l'ORF (pour la recherche du codon stop)
    int numero=0; //compteur pour le tableau de structure
    int end=0; //booleen pour sortir de la recherche de codon stop
    char sens[10000]; //stocke la plus grande Orf dans le sens
    char antisens[10000]; //stocke la plus grande Orf dans l'antisens
    struct Orf PlusGrandeOrf = {0,0,0}; // stocke la plus grande Orf
    struct Orf NumeroOrf[100]={0};
    int t;

t=strlen(sequence);

//Dans le brin sens

for(i=0;i<t;i++){
    //Recherche codon start
    if(sequence[i]=='A' && sequence[i+1]=='T' && sequence[i+2]=='G'){
        printf("Un codon start a été trouvé en position %d. \n", i);
        k=i;
        numero++;
        NumeroOrf[numero].start=i;
        NumeroOrf[numero].longueur=1;
        end=0;

        while (end==0 && k<t){
            //Recherche codon stop
                if (sequence[k]=='T'&& sequence[k+1]=='A' && sequence[k+2]=='G'){
                    NumeroOrf[numero].stop=k+3;
                    NumeroOrf[numero].longueur++;
                    if(NumeroOrf[numero].longueur>PlusGrandeOrf.longueur){
                        PlusGrandeOrf.start=i;
                        PlusGrandeOrf.stop=k+3;
                        PlusGrandeOrf.longueur = NumeroOrf[numero].longueur;
                    }
                    printf("Fin de l'Orf numero %d, avec longueur de %d \n", numero, NumeroOrf[numero].longueur);
                    end=1;
                }
                else if (sequence[k]=='T' && sequence[k+1]=='A' && sequence[k+2]=='A'){
                    NumeroOrf[numero].stop=k;
                    NumeroOrf[numero].longueur++;
                    if(NumeroOrf[numero].longueur>PlusGrandeOrf.longueur){
                        PlusGrandeOrf.start=i;
                        PlusGrandeOrf.stop=k+3;
                        PlusGrandeOrf.longueur = NumeroOrf[numero].longueur;
                    }
                    printf("Fin de l'Orf numero %d, avec longueur de %d\n", numero, NumeroOrf[numero].longueur);                    
                    end=1;
                }
                else if (sequence[k]=='T' && sequence[k+1]=='G' && sequence[k+2]=='A'){
                    NumeroOrf[numero].stop=k;
                    NumeroOrf[numero].longueur++;
                    if(NumeroOrf[numero].longueur>PlusGrandeOrf.longueur){
                        PlusGrandeOrf.start=i;
                        PlusGrandeOrf.stop=k+3;
                        PlusGrandeOrf.longueur = NumeroOrf[numero].longueur;
                    }
                    printf("Fin de l'Orf numero %d, avec longueur de %d\n", numero, NumeroOrf[numero].longueur);                    
                    end=1;
                }
                else{
                    k=k+3;
                    NumeroOrf[numero].longueur++;
                }
        }
    }
}
printf("La recherche de sequence codante dans le brin sens est terminee.\n");
sens=EcritureSequence(sequence,PlusGrandeOrf.start,PlusGrandeOrf.stop);

inversionChaine(sequence);
Complementaire(sequence);

printf("La chaine a ete inversée, la recherche dans le brin antisens va commencer. \n");
//Reinitialisation des parametres
i=0;
numero=0;
PlusGrandeOrf={0,0,0};
NumeroOrf[100]={0};

for(i=0;i<t;i++){
    //Recherche codon start
    if(sequence[i]=='A' && sequence[i+1]=='T' && sequence[i+2]=='G'){
        printf("Un codon start a été trouvé en position %d. \n", i);
        k=i;
        numero++;
        NumeroOrf[numero].start=i;
        NumeroOrf[numero].longueur=1;
        end=0;

        while (end==0 && k<t){
            //Recherche codon stop
                if (sequence[k]=='T'&& sequence[k+1]=='A' && sequence[k+2]=='G'){
                    NumeroOrf[numero].stop=k+3;
                    NumeroOrf[numero].longueur++;
                    if(NumeroOrf[numero].longueur>PlusGrandeOrf.longueur){
                        PlusGrandeOrf.start=i;
                        PlusGrandeOrf.stop=k+3;
                        PlusGrandeOrf.longueur = NumeroOrf[numero].longueur;
                    }
                    printf("Fin de l'Orf numero %d, avec longueur de %d\n", numero, NumeroOrf[numero].longueur);
                    end=1;
                }
                else if (sequence[k]=='T' && sequence[k+1]=='A' && sequence[k+2]=='A'){
                    NumeroOrf[numero].stop=k;
                    NumeroOrf[numero].longueur++;
                    if(NumeroOrf[numero].longueur>PlusGrandeOrf.longueur){
                        PlusGrandeOrf.start=i;
                        PlusGrandeOrf.stop=k+3;
                        PlusGrandeOrf.longueur = NumeroOrf[numero].longueur;
                    }
                    printf("Fin de l'Orf numero %d, avec longueur de %d\n", numero, NumeroOrf[numero].longueur);                    
                    end=1;
                }
                else if (sequence[k]=='T' && sequence[k+1]=='G' && sequence[k+2]=='A'){
                    NumeroOrf[numero].stop=k;
                    NumeroOrf[numero].longueur++;
                    if(NumeroOrf[numero].longueur>PlusGrandeOrf.longueur){
                        PlusGrandeOrf.start=i;
                        PlusGrandeOrf.stop=k+3;
                        PlusGrandeOrf.longueur = NumeroOrf[numero].longueur;
                    }
                    printf("Fin de l'Orf numero %d, avec longueur de %d\n", numero, NumeroOrf[numero].longueur);                    
                    end=1;
                }
                else{
                    k=k+3;
                    NumeroOrf[numero].longueur++;
                }
        }
    }
}
printf("La recherche de sequence codante dans le brin antisens est terminee.\n");
antisens=EcritureSequence(sequence,PlusGrandeOrf.start,PlusGrandeOrf.stop);
printf("%d Orfs ont été trouvées, la plus grande contient %d Acides Aminés, commence en position %d et se termine en position %d.\n", numero, PlusGrandeOrf.longueur, PlusGrandeOrf.start, PlusGrandeOrf.stop);

SauvegardePlusGrande(sens, antisens, path_output);
printf("Votre plus grande Orf a bien été sauvegardée, elle est désormais enregistrée ici : %s \n", path_output);

}

void module_SequenceCodante(char* sequence){
    char path_output[256];
    printf("Dans quel fichier souhaitez-vous enregistrer votre plus grand ORF? \n");
    scanf("%s", path_output);
    
    ChercheSeq(path_output, sequence);
}