#include "utils.h"

void ChercheSeq(){
//Cette fonction cherche le plus grand fragment de séquence commencant par un codon start et finissant par un codon stop

//Variables
    int i=0; //compteur de la sequence
    int j=0; //compteur de l'ORF
    int nbAA=0; //compte le nombre d'Acide Aminés (pour récupérer la plus grande séquence)
    int nbAA2=0; //permet de comparer la taille des ORFs
    char Orf[10000]; //stocke la sequence codante
    int start=0; //note à quel [i] la séquence codante commence
    int stop=0; //note à quel [i] la séquence se termine, sert de booleen egalement

//Recherche dans le brin sens

    //Boucle
    while(sequence[i]!='\0'){

    //Recherche de séquence codante    
        while(stop==0){
        //Recherche du codon start    
            if (sequence[i] =='A'){
                if (sequence[i+1]=='T'){
                    if (sequence[i+2]=='G'){
                        start=i;
                        nbAA++;
                        i+3;
                    }
                }
            }
            else{
                i++;
            }
        //Recherche du codon stop
            if (sequence[i]=='T'){
                if(sequence[i+1]=='A'){
                    if (sequence[i+2]=='A'||'G'){
                        stop=i;
                        nbAA++;
                    }
                }
                else if (sequence [i+1]=='G'){
                    if (sequence[i+2]=='A'){
                        stop=i;
                        nbAA++;
                    }
                }
            }
            else{
                i+3;
                nbAA++;
            }
        }
    //Verification de la taille de l'ORF et inscription de la séquence
        if (nbAA>nbAA2){
            for(i=start;i=stop;i++){
                Orf[j]=sequence[i];
                j++;
            }
            j=0;
        }

    //retour à la recherche d'Orf
        nbAA2=nbAA;
        nbAA=0;
        i=stop+1;
        stop=0;
    }

//Dans le brin antisens

    //inversion de la chaine
    int k,n; //compteurs
    char nucleo //stocke le nucleotide afin de ne parcourir que la moitié de la chaine
    n=strlen(sequence)

    for(k=0;k<n/2;k++){
        nucleo=sequence[k];
        sequence[k]=sequence[n-k-1]; //-1 car on ne veut pas que le \0 change de place!
        sequence[n-k-1]=nucleo;
    }
    //Rendre la chaine complementaire
    while (i!=\0){
        if (sequence[i]=='A'){
            sequence[i]='T';
            i++;
        }
        else if (sequence[i]=='T'){
            sequence[i]='A';
            i++;
        }
        else if (sequence[i]=='C'){
            sequence[i]='G';
            i++;
        }
        else if (sequence[i]=='G'){
            sequence[i]='C';
            i++;
    }
    }
//Remise des compteurs à 0
    i=0;
    j=0;

//Boucle
while(sequence[i]!='\0'){

    //Recherche de séquence codante    
        while(stop==0){
        //Recherche du codon start    
            if (sequence[i] =='A'){
                if (sequence[i+1]=='T'){
                    if (sequence[i+2]=='G'){
                        start=i;
                        nbAA++;
                        i+3;
                    }
                }
            }
            else{
                i++;
            }
        //Recherche du codon stop
            if (sequence[i]=='T'){
                if(sequence[i+1]=='A'){
                    if (sequence[i+2]=='A'||'G'){
                        stop=i;
                        nbAA++;
                    }
                }
                else if (sequence [i+1]=='G'){
                    if (sequence[i+2]=='A'){
                        stop=i;
                        nbAA++;
                    }
                }
            }
            else{
                i+3;
                nbAA++;
            }
        }
    //Verification de la taille de l'ORF et inscription de la séquence
        if (nbAA>nbAA2){
            for(i=start;i=stop;i++){
                Orf[j]=sequence[i];
                j++;
            }
            j=0;
        }

    //retour à la recherche d'Orf
        nbAA2=nbAA;
        nbAA=0;
        i=stop+1;
        stop=0;
    }
}
