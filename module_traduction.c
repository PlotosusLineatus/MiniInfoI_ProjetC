#include "utils.h"
#include "module_traduction.h"

void traduction(const char* path_output, char* sequence){
    int i =0;
    int j=0;
    char trad[10000];

    while(sequence[i]!='\0'){

//triplets commençant par A
        if(sequence[i]=='A'){
            if(sequence[i+1]=='A'){
                if(sequence[i+2]=='U'){
                    trad[j]='N';
                    j++;
                }
                else if(sequence[i+2]=='C'){
                    trad[j]='N';
                    j++;
                }
                else if(sequence[i+2]=='A'){
                    trad[j]='K';
                    j++;
                }
                else {
                    trad[j]='K';
                    j++;
                }               
            }

            else if(sequence[i+1]=='C'){
                if(sequence[i+2]=='U'){
                    trad[j]='T';
                    j++;
                }
                else if(sequence[i+2]=='C'){
                    trad[j]='T';
                    j++;
                }
                else if(sequence[i+2]=='A'){
                    trad[j]='T';
                    j++;
                }
                else {
                    trad[j]='T';
                    j++;
                }               
            }

            else if(sequence[i+1]=='G'){
                if(sequence[i+2]=='U'){
                    trad[j]='S';
                    j++;
                }
                else if(sequence[i+2]=='C'){
                    trad[j]='S';
                    j++;
                }
                else if(sequence[i+2]=='A'){
                    trad[j]='R';
                    j++;
                }
                else {
                    trad[j]='R';
                    j++;
                }               
            }

            else {
                if(sequence[i+2]=='U'){
                    trad[j]='I';
                    j++;
                }
                else if(sequence[i+2]=='C'){
                    trad[j]='I';
                    j++;
                }
                else if(sequence[i+2]=='A'){
                    trad[j]='I';
                    j++;
                }
                else {
                    trad[j]='M';
                    j++;
                }               
            }                        
        }

//triplets commençant par C
        else if(sequence[i]=='C'){
            if(sequence[i+1]=='A'){
                if(sequence[i+2]=='U'){
                    trad[j]='H';
                    j++;
                }
                else if(sequence[i+2]=='C'){
                    trad[j]='H';
                    j++;
                }
                else if(sequence[i+2]=='A'){
                    trad[j]='Q';
                    j++;
                }
                else {
                    trad[j]='Q';
                    j++;
                }               
            }

            else if(sequence[i+1]=='C'){
                if(sequence[i+2]=='U'){
                    trad[j]='P';
                    j++;
                }
                else if(sequence[i+2]=='C'){
                    trad[j]='P';
                    j++;
                }
                else if(sequence[i+2]=='A'){
                    trad[j]='P';
                    j++;
                }
                else {
                    trad[j]='P';
                    j++;
                }               
            }

            else if(sequence[i+1]=='G'){
                if(sequence[i+2]=='U'){
                    trad[j]='R';
                    j++;
                }
                else if(sequence[i+2]=='C'){
                    trad[j]='R';
                    j++;
                }
                else if(sequence[i+2]=='A'){
                    trad[j]='R';
                    j++;
                }
                else {
                    trad[j]='R';
                    j++;
                }               
            }

            else {
                if(sequence[i+2]=='U'){
                    trad[j]='L';
                    j++;
                }
                else if(sequence[i+2]=='C'){
                    trad[j]='L';
                    j++;
                }
                else if(sequence[i+2]=='A'){
                    trad[j]='L';
                    j++;
                }
                else {
                    trad[j]='L';
                    j++;
                }               
            }                        
        }

//triplets commençant par G
        else if(sequence[i]=='G'){
            if(sequence[i+1]=='A'){
                if(sequence[i+2]=='U'){
                    trad[j]='D';
                    j++;
                }
                else if(sequence[i+2]=='C'){
                    trad[j]='D';
                    j++;
                }
                else if(sequence[i+2]=='A'){
                    trad[j]='E';
                    j++;
                }
                else {
                    trad[j]='E';
                    j++;
                }               
            }

            else if(sequence[i+1]=='C'){
                if(sequence[i+2]=='U'){
                    trad[j]='A';
                    j++;
                }
                else if(sequence[i+2]=='C'){
                    trad[j]='A';
                    j++;
                }
                else if(sequence[i+2]=='A'){
                    trad[j]='A';
                    j++;
                }
                else {
                    trad[j]='A';
                    j++;
                }               
            }

            else if(sequence[i+1]=='G'){
                if(sequence[i+2]=='U'){
                    trad[j]='G';
                    j++;
                }
                else if(sequence[i+2]=='C'){
                    trad[j]='G';
                    j++;
                }
                else if(sequence[i+2]=='A'){
                    trad[j]='G';
                    j++;
                }
                else {
                    trad[j]='G';
                    j++;
                }               
            }

            else {
                if(sequence[i+2]=='U'){
                    trad[j]='V';
                    j++;
                }
                else if(sequence[i+2]=='C'){
                    trad[j]='V';
                    j++;
                }
                else if(sequence[i+2]=='A'){
                    trad[j]='V';
                    j++;
                }
                else {
                    trad[j]='V';
                    j++;
                }               
            }                        
        }

//triplets commençant par U
        else {
            if(sequence[i+1]=='A'){
                if(sequence[i+2]=='U'){
                    trad[j]='Y';
                    j++;
                }
                else if(sequence[i+2]=='C'){
                    trad[j]='Y';
                    j++;
                }
                else if(sequence[i+2]=='A'){
                    trad[j]='*';
                    j++;
                }
                else {
                    trad[j]='*';
                    j++;
                }               
            }

            else if(sequence[i+1]=='C'){
                if(sequence[i+2]=='U'){
                    trad[j]='S';
                    j++;
                }
                else if(sequence[i+2]=='C'){
                    trad[j]='S';
                    j++;
                }
                else if(sequence[i+2]=='A'){
                    trad[j]='S';
                    j++;
                }
                else {
                    trad[j]='S';
                    j++;
                }               
            }

            else if(sequence[i+1]=='G'){
                if(sequence[i+2]=='U'){
                    trad[j]='C';
                    j++;
                }
                else if(sequence[i+2]=='C'){
                    trad[j]='C';
                    j++;
                }
                else if(sequence[i+2]=='A'){
                    trad[j]='*';
                    j++;
                }
                else {
                    trad[j]='W';
                    j++;
                }               
            }

            else {
                if(sequence[i+2]=='U'){
                    trad[j]='F';
                    j++;
                }
                else if(sequence[i+2]=='C'){
                    trad[j]='F';
                    j++;
                }
                else if(sequence[i+2]=='A'){
                    trad[j]='L';
                    j++;
                }
                else {
                    trad[j]='L';
                    j++;
                }               
            }                        
        }

        i=i+3;
    printf("%d : %c --> %c \n",i,sequence[i], trad[j]);
    }
//sauvegarde de la séquence
    printf("%s",trad);
    printf("Votre sequence a bien été traduite, elle est désormais enregistrée ici : %s \n", path_output );
    save_sequence(path_output, trad);

}

void module_traduction(char* sequence){
    char path_output[256];
    printf("Dans quel fichier souhaitez-vous enregistrer votre sequence traduite? \n");
    scanf("%s", path_output);
    
    traduction(path_output, sequence);
}

