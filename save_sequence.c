#include <stdio.h>
#include <stdlib.h>

void save_sequence(char* sequence){
/* Cette procedure sauvegarde la sequence donnee afin de faciliter la lecture */

FILE* fp= fopen("sequenceF.txt", "w");
    if(!fp){
            printf("l'ouverture a echoue. \n");
            exit(EXIT_FAILURE);
    }
    int i=0;
    int compteurCaractere =0 ; /*permet de faire les retours a la ligne tous les 80 caracteres*/
    while(sequence[i]!='\0'){
            if (compteurCaractere==80){
                    fprintf(fp,"\n");
                    compteurCaractere = 0;
                    i++;
            }
            else{
                    fprintf(fp,"%c",sequence[i]);
                    compteurCaractere++;
                    i++;
            }
    }
fclose(fp);
}

int main(int argc, char *argv[]){
        char prot1[] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBB";
        save_sequence(prot1);
}