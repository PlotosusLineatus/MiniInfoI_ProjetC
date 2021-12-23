#include "utils.h"

void traduction(const char* path_output, char* sequence){

//Mise en place des compteurs et inititation de la séquence traduite
    int i=0;
    int j=0;
    traduit[10000];

//Traduction
    while(sequence[i]!='\0'){
        if (sequence[i]!= 'A'||'U'||'G'||'C'){
            printf("Attention, il ne s'agit pas d'une sequence ARN, traduction impossible! :( \n");
        }

        //Triplet de nucléotides commencant par A
        if(sequence[i]=='A'){
            i++;
            if(sequence[i]=='G'){
                i++;
                if(sequence[i]=='A'||'G'){
                    traduit[j]='R';
                    j++;
                    i++;
                }
                else{
                    traduit[j]='S';
                    j++;
                    i++;
                }
            }

            else if(sequence[i]=='U'){
                i++;
                if(sequence[i]=='A'||'C'||'U'){
                    traduit[j]='I';
                    j++;
                    i++;
                }
                else{
                    traduit[j]='M';
                    j++;
                    i++;
                }            
            }

            else if(sequence[i]=='A'){
                i++;
                if(sequence[i]=='A'||'G'){
                    traduit[j]='K';
                    j++;
                    i++;
                }
                else{
                    traduit[j]='N';
                    j++;
                    i++;
                }            
            }

            else{
                traduit[j]='T';
                j++;
                i+2;
            }            
        }

        //Triplet de nucléotides commencant par C
        else if(sequence[i]=='C'){
            i++;
            if(sequence[i]=='G'){
                traduit[j]='R';
                j++;
                i+2;
            }

            else if(sequence[i]=='U'){
                traduit[j]='L';
                j++;
                i+2;
            }

            else if(sequence[i]=='A'){
                i++;
                if(sequence[i]=='U'||'C'){
                    traduit[j]='H';
                    j++;
                    i++;
                }
                else{
                    traduit[j]='Q';
                    j++;
                    i++;
                }            
            }

            else{
                traduit[j]='P';
                j++;
                i+2;
            }            
        }    

        //Triplet de nucléotides commencant par G
        else if(sequence[i]=='G'){
            i++;
            if(sequence[i]=='G'){
                traduit[j]='G';
                j++;
                i+2;
            }

            else if(sequence[i]=='U'){
                traduit[j]='V';
                j++;
                i+2;
            }

            else if(sequence[i]=='A'){
                i++;
                if(sequence[i]=='U'||'C'){
                    traduit[j]='D';
                    j++;
                    i++;
                }
                else{
                    traduit[j]='E';
                    j++;
                    i++;
                }            
            }

            else{
                traduit[j]='A';
                j++;
                i+2;
            }            
        }

        //Triplet de nucléotides commencant par U
        else{
            i++;
            if(sequence[i]=='G'){
                i++;
                if(sequence[i]=='U'||'C'){
                    traduit[j]='C';
                    j++;
                    i++;
                }
                else if (sequence[i]=='G'){
                    traduit[j]='W';
                    j++;
                    i++;
                }
                else{
                    traduit[j]='*';
                    j++;
                    i++;
                }            
            }

            else if(sequence[i]=='U'){
                i++;
                if(sequence[i]=='G'||'A'){
                    traduit[j]='L';
                    j++;
                    i++;
                }
                else{
                    traduit[j]='F';
                    j++;
                    i++;
                }            
            }           

            else if(sequence[i]=='A'){
                i++;
                if(sequence[i]=='U'||'C'){
                    traduit[j]='Y';
                    j++;
                    i++;
                }
                else{
                    traduit[j]='*';
                    j++;
                    i++;
                }            
            }

            else{
                traduit[j]='S';
                j++;
                i+2;
            }            
        }

    }
}