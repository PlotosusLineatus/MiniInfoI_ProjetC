#include "utils.h"

//Main test pour utils, il va surement falloir augmenter la taille de la chaine de caractere sequence

int main(int argc, char *argv[]){
        
        char path_output[256];
        char path_input[256];
        char sequence[500];

        printf("A partir de quel fichier souhaitez-vous extraire la séquence (Attention: elle doit être au format simplifié)? \n "); 
        /* ex qui marche(Linux): /home/noemie/Desktop/projetc/utile/sequencetest.txt */
        scanf("%s", path_input);
        extract_sequence(path_input, sequence);

        printf("Dans quel fichier (déjà existant) voulez-vous sauvegarder votre séquence? \n"); /*Attention, sous windows, mettre deux \\*/
        /* ex qui marche(Linux): /home/noemie/Desktop/projetc/utile/sequenceF.txt     */
        scanf("%s", path_output);
        save_sequence(path_output, sequence);
}