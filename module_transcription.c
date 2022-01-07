#include "utils.h"
#include "module_transcription.h"

//Transcription: Remplace la séquence ADN en séquence ARN
void transcription(const char *path_output, char *sequence)
{

    int compte; //permet de vérifier que la séquence codante est bien divisible par trois
    compte = strlen(sequence) + 1;
    if (compte % 3 != 0)
    {
        printf("La séquence n'est pas divisible par trois, recommencez\n");
        module_transcription();
    }

    //Verification que la séquence commence bien par un codon d'initiation
    if (sequence[0] != 'A')
    {
        printf("La sequence ne commence pas par un codon d'initiation, recommencez \n");
        module_transcription();
    }
    else if (sequence[1] != 'T')
    {
        printf("La sequence ne commence pas par un codon d'initiation, recommencez \n");
        module_transcription();
    }
    else if (sequence[2] != 'G')
    {
        printf("La sequence ne commence pas par un codon d'initiation, recommencez \n");
        module_transcription();
    }

    //transcription
    char transcrit[10000];
    int i = 0;

    while (sequence[i] != '\0')
    {
        if (sequence[i] == 'T')
        {
            transcrit[i] = 'U';
            i++;
        }
        else
        {
            transcrit[i] = sequence[i];
            i++;
        }
    }

    //sauvegarde de la séquence

    printf("Votre sequence a bien été traduite, elle est désormais enregistrée ici : %s \n", path_output);
    save_sequence(path_output, transcrit);
}

//deroulement du module transciption
void module_transcription()
{
    printf("\033[34;01mBienvenue dans le module 2: Transcription d'une séquence ADN en séquence ARN\033[00m\n\n");

    //variables
    char path_input[256];
    char sequence[10000];

    printf("A partir de quel fichier souhaitez-vous extraire la séquence (Attention: elle doit être au format simplifié)? \n ");
    scanf("%s", path_input);
    extract_sequence(path_input, sequence);

    char path_output[256];
    printf("Dans quel fichier souhaitez-vous enregistrer votre sequence transcite? \n");
    scanf("%s", path_output);

    transcription(path_output, sequence);
}
