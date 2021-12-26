#include "utils.h"
#include "module_transcription.h"

//Main test pour le module_transcription

int main(int argc, char *argv[]){
    
        char path_input[256];
        char sequence[10000];

        printf("A partir de quel fichier souhaitez-vous extraire la séquence (Attention: elle doit être au format simplifié)? \n "); 
        /* ex qui marche(Linux): /home/noemie/Desktop/projetc/orf46.txt */
        scanf("%s", path_input);
        extract_sequence(path_input, sequence);


        module_transcription (sequence);

    return 0;
}