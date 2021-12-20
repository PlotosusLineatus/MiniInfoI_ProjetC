#include <stdio.h>
#include <stdlib.h>

void save_sequence(const char* path_output, char* sequence){
/* Cette procedure sauvegarde la sequence donnee afin de faciliter la lecture */

FILE* fp= fopen(path_output, "w");
    if(!fp){
            printf("L'ouverture a echoue. \n");
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
        char path_output[256];
        printf("Dans quel fichier (déjà existant) voulez-vous sauvegarder votre séquence? \n"); /*Attention, sous windows, mettre deux \\*/
        scanf("%s", path_output);
        save_sequence(path_output, prot1);
}