#include "utils.h"


void transcription(const char* path_output, char* sequence){

    int compte; //permet de vérifier que la séquence codante est bien divisible par trois
    compte = strlen(sequence);
    if (compte % 3 !=0){
        printf("La séquence n'est pas divisible par trois, recommencez\n");
    }

    //Verification que la séquence commence bien par un codon d'initiation
    if (sequence[0] != 'A'){
        printf("La sequence ne commence pas par un codon d'initiation, recommencez \n");
    }
    else if (sequence[1] != 'T'){
        printf("La sequence ne commence pas par un codon d'initiation, recommencez \n");
    }
        else if (sequence[2] != 'G'){
             printf("La sequence ne commence pas par un codon d'initiation, recommencez \n");
        }
    
    //transcription
    char transcrit[5000];
    int i=0;

    while (sequence[i] != '\0'){
        if(sequence[i] == 'A' || 'C' || 'G'){
        transcrit[i]=sequence[i];
        i++;
        }
        else{
            transcrit[i]='U';
            i++;
        }
    } 

    //sauvegarde de la séquence
    printf("Votre sequence a bien été traduite, elle est désormais enregistrée ici : %s \n", path_output );
    save_sequence(path_output, transcrit);
    }

//deroule du module transciption
void module_transcription(){
    char path_output[256];
    printf("Dans quel fichier (déjà existant) souhaitez-vous enregistrer votre sequence transcite? \n");
    scanf("%s", path_output);
    
    char sequence[]="ATGAATTAAATGGTAATGGCC"; 
    /* pour tester, a retirer plus tard */
    transcription(path_output, sequence);
}
    