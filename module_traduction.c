#include "utils.h"
#include "module_traduction.h"

//Fonctions pour determiner quel AAs se trouvent à une position donnée. Seuls les nucléotides AUCG sont traités ici.
int n_A(char *seq, int i)
{
    if (seq[i] == 'A')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int n_C(char *seq, int i)
{
    if (seq[i] == 'C')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int n_G(char *seq, int i)
{
    if (seq[i] == 'G')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int n_U(char *seq, int i)
{
    if (seq[i] == 'U')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Programme de traduction : de la séquence ARN vers la séquence protéique
void traduction(const char *path_output, char *sequence)
{
    int i = 0;           //compteur au sein de séquence[]
    int j = 0;           //compteur au sein de traduit[]
    char traduit[10000]; // permet de stocker les AAs avant la sauvegarde
    int t;               //determine la longueur des de sequence pour la boucle while

    t = strlen(sequence);

    for (i = 0; i < t; i += 3)
    {
        printf("Position: %d\n", i); //Ce printf permet de vérifier à quelle position de la séquence nous nous trouvons (voir rapport, Difficultés rencontrées)
        //triplets commencant par AA
        if (n_A(sequence, i) == 1 && n_A(sequence, i + 1) == 1 && n_U(sequence, i + 2) == 1)
        {
            traduit[j] = 'N';
            j++;
        }
        else if (n_A(sequence, i) == 1 && n_A(sequence, i + 1) == 1 && n_C(sequence, i + 2) == 1)
        {
            traduit[j] = 'N';
            j++;
        }
        else if (n_A(sequence, i) == 1 && n_A(sequence, i + 1) == 1 && n_A(sequence, i + 2) == 1)
        {
            traduit[j] = 'K';
            j++;
        }
        else if (n_A(sequence, i) == 1 && n_A(sequence, i + 1) == 1 && n_G(sequence, i + 2) == 1)
        {
            traduit[j] = 'K';
            j++;
        }
        //triplets commencant par AC
        else if (n_A(sequence, i) == 1 && n_C(sequence, i + 1) == 1 && n_U(sequence, i + 2) == 1)
        {
            traduit[j] = 'T';
            j++;
        }
        else if (n_A(sequence, i) == 1 && n_C(sequence, i + 1) == 1 && n_C(sequence, i + 2) == 1)
        {
            traduit[j] = 'T';
            j++;
        }
        else if (n_A(sequence, i) == 1 && n_C(sequence, i + 1) == 1 && n_A(sequence, i + 2) == 1)
        {
            traduit[j] = 'T';
            j++;
        }
        else if (n_A(sequence, i) == 1 && n_C(sequence, i + 1) == 1 && n_G(sequence, i + 2) == 1)
        {
            traduit[j] = 'T';
            j++;
        }
        //triplets commencant par AG
        else if (n_A(sequence, i) == 1 && n_G(sequence, i + 1) == 1 && n_U(sequence, i + 2) == 1)
        {
            traduit[j] = 'S';
            j++;
        }
        else if (n_A(sequence, i) == 1 && n_G(sequence, i + 1) == 1 && n_C(sequence, i + 2) == 1)
        {
            traduit[j] = 'S';
            j++;
        }
        else if (n_A(sequence, i) == 1 && n_G(sequence, i + 1) == 1 && n_A(sequence, i + 2) == 1)
        {
            traduit[j] = 'S';
            j++;
        }
        else if (n_A(sequence, i) == 1 && n_G(sequence, i + 1) == 1 && n_G(sequence, i + 2) == 1)
        {
            traduit[j] = 'S';
            j++;
        }
        //triplets commencant par AU
        else if (n_A(sequence, i) == 1 && n_U(sequence, i + 1) == 1 && n_U(sequence, i + 2) == 1)
        {
            traduit[j] = 'I';
            j++;
        }
        else if (n_A(sequence, i) == 1 && n_U(sequence, i + 1) == 1 && n_C(sequence, i + 2) == 1)
        {
            traduit[j] = 'I';
            j++;
        }
        else if (n_A(sequence, i) == 1 && n_U(sequence, i + 1) == 1 && n_A(sequence, i + 2) == 1)
        {
            traduit[j] = 'I';
            j++;
        }
        else if (n_A(sequence, i) == 1 && n_U(sequence, i + 1) == 1 && n_G(sequence, i + 2) == 1)
        {
            traduit[j] = 'M';
            j++;
        }

        //triplets commencant par CA
        else if (n_C(sequence, i) == 1 && n_A(sequence, i + 1) == 1 && n_U(sequence, i + 2) == 1)
        {
            traduit[j] = 'H';
            j++;
        }
        else if (n_C(sequence, i) == 1 && n_A(sequence, i + 1) == 1 && n_C(sequence, i + 2) == 1)
        {
            traduit[j] = 'H';
            j++;
        }
        else if (n_C(sequence, i) == 1 && n_A(sequence, i + 1) == 1 && n_A(sequence, i + 2) == 1)
        {
            traduit[j] = 'Q';
            j++;
        }
        else if (n_C(sequence, i) == 1 && n_A(sequence, i + 1) == 1 && n_G(sequence, i + 2) == 1)
        {
            traduit[j] = 'Q';
            j++;
        }
        //triplets commencant par CC
        else if (n_C(sequence, i) == 1 && n_C(sequence, i + 1) == 1 && n_U(sequence, i + 2) == 1)
        {
            traduit[j] = 'P';
            j++;
        }
        else if (n_C(sequence, i) == 1 && n_C(sequence, i + 1) == 1 && n_C(sequence, i + 2) == 1)
        {
            traduit[j] = 'P';
            j++;
        }
        else if (n_C(sequence, i) == 1 && n_C(sequence, i + 1) == 1 && n_A(sequence, i + 2) == 1)
        {
            traduit[j] = 'P';
            j++;
        }
        else if (n_C(sequence, i) == 1 && n_C(sequence, i + 1) == 1 && n_G(sequence, i + 2) == 1)
        {
            traduit[j] = 'P';
            j++;
        }
        //triplets commencant par CG
        else if (n_C(sequence, i) == 1 && n_G(sequence, i + 1) == 1 && n_U(sequence, i + 2) == 1)
        {
            traduit[j] = 'R';
            j++;
        }
        else if (n_C(sequence, i) == 1 && n_G(sequence, i + 1) == 1 && n_C(sequence, i + 2) == 1)
        {
            traduit[j] = 'R';
            j++;
        }
        else if (n_C(sequence, i) == 1 && n_G(sequence, i + 1) == 1 && n_A(sequence, i + 2) == 1)
        {
            traduit[j] = 'R';
            j++;
        }
        else if (n_C(sequence, i) == 1 && n_G(sequence, i + 1) == 1 && n_G(sequence, i + 2) == 1)
        {
            traduit[j] = 'R';
            j++;
        }
        //triplets commencant par CU
        else if (n_C(sequence, i) == 1 && n_U(sequence, i + 1) == 1 && n_U(sequence, i + 2) == 1)
        {
            traduit[j] = 'L';
            j++;
        }
        else if (n_C(sequence, i) == 1 && n_U(sequence, i + 1) == 1 && n_C(sequence, i + 2) == 1)
        {
            traduit[j] = 'L';
            j++;
        }
        else if (n_C(sequence, i) == 1 && n_U(sequence, i + 1) == 1 && n_A(sequence, i + 2) == 1)
        {
            traduit[j] = 'L';
            j++;
        }
        else if (n_C(sequence, i) == 1 && n_U(sequence, i + 1) == 1 && n_G(sequence, i + 2) == 1)
        {
            traduit[j] = 'L';
            j++;
        }

        //triplets commencant par GA
        else if (n_G(sequence, i) == 1 && n_A(sequence, i + 1) == 1 && n_U(sequence, i + 2) == 1)
        {
            traduit[j] = 'D';
            j++;
        }
        else if (n_G(sequence, i) == 1 && n_A(sequence, i + 1) == 1 && n_C(sequence, i + 2) == 1)
        {
            traduit[j] = 'D';
            j++;
        }
        else if (n_G(sequence, i) == 1 && n_A(sequence, i + 1) == 1 && n_A(sequence, i + 2) == 1)
        {
            traduit[j] = 'E';
            j++;
        }
        else if (n_G(sequence, i) == 1 && n_A(sequence, i + 1) == 1 && n_G(sequence, i + 2) == 1)
        {
            traduit[j] = 'E';
            j++;
        }
        //triplets commencant par GC
        else if (n_G(sequence, i) == 1 && n_C(sequence, i + 1) == 1 && n_U(sequence, i + 2) == 1)
        {
            traduit[j] = 'A';
            j++;
        }
        else if (n_G(sequence, i) == 1 && n_C(sequence, i + 1) == 1 && n_C(sequence, i + 2) == 1)
        {
            traduit[j] = 'A';
            j++;
        }
        else if (n_G(sequence, i) == 1 && n_C(sequence, i + 1) == 1 && n_A(sequence, i + 2) == 1)
        {
            traduit[j] = 'A';
            j++;
        }
        else if (n_G(sequence, i) == 1 && n_C(sequence, i + 1) == 1 && n_G(sequence, i + 2) == 1)
        {
            traduit[j] = 'A';
            j++;
        }
        //triplets commencant par GG
        else if (n_G(sequence, i) == 1 && n_G(sequence, i + 1) == 1 && n_U(sequence, i + 2) == 1)
        {
            traduit[j] = 'G';
            j++;
        }
        else if (n_G(sequence, i) == 1 && n_G(sequence, i + 1) == 1 && n_C(sequence, i + 2) == 1)
        {
            traduit[j] = 'G';
            j++;
        }
        else if (n_G(sequence, i) == 1 && n_G(sequence, i + 1) == 1 && n_A(sequence, i + 2) == 1)
        {
            traduit[j] = 'G';
            j++;
        }
        else if (n_G(sequence, i) == 1 && n_G(sequence, i + 1) == 1 && n_G(sequence, i + 2) == 1)
        {
            traduit[j] = 'G';
            j++;
        }
        //triplets commencant par GU
        else if (n_G(sequence, i) == 1 && n_U(sequence, i + 1) == 1 && n_U(sequence, i + 2) == 1)
        {
            traduit[j] = 'V';
            j++;
        }
        else if (n_G(sequence, i) == 1 && n_U(sequence, i + 1) == 1 && n_C(sequence, i + 2) == 1)
        {
            traduit[j] = 'V';
            j++;
        }
        else if (n_G(sequence, i) == 1 && n_U(sequence, i + 1) == 1 && n_A(sequence, i + 2) == 1)
        {
            traduit[j] = 'V';
            j++;
        }
        else if (n_G(sequence, i) == 1 && n_U(sequence, i + 1) == 1 && n_G(sequence, i + 2) == 1)
        {
            traduit[j] = 'V';
            j++;
        }

        //triplets commencant par UA
        else if (n_U(sequence, i) == 1 && n_A(sequence, i + 1) == 1 && n_U(sequence, i + 2) == 1)
        {
            traduit[j] = 'Y';
            j++;
        }
        else if (n_U(sequence, i) == 1 && n_A(sequence, i + 1) == 1 && n_C(sequence, i + 2) == 1)
        {
            traduit[j] = 'Y';
            j++;
        }
        else if (n_U(sequence, i) == 1 && n_A(sequence, i + 1) == 1 && n_A(sequence, i + 2) == 1)
        {
            traduit[j] = '*';
            j++;
        }
        else if (n_U(sequence, i) == 1 && n_A(sequence, i + 1) == 1 && n_G(sequence, i + 2) == 1)
        {
            traduit[j] = '*';
            j++;
        }
        //triplets commencant par AC
        else if (n_U(sequence, i) == 1 && n_C(sequence, i + 1) == 1 && n_U(sequence, i + 2) == 1)
        {
            traduit[j] = 'S';
            j++;
        }
        else if (n_U(sequence, i) == 1 && n_C(sequence, i + 1) == 1 && n_C(sequence, i + 2) == 1)
        {
            traduit[j] = 'S';
            j++;
        }
        else if (n_U(sequence, i) == 1 && n_C(sequence, i + 1) == 1 && n_A(sequence, i + 2) == 1)
        {
            traduit[j] = 'S';
            j++;
        }
        else if (n_U(sequence, i) == 1 && n_C(sequence, i + 1) == 1 && n_G(sequence, i + 2) == 1)
        {
            traduit[j] = 'S';
            j++;
        }
        //triplets commencant par UG
        else if (n_U(sequence, i) == 1 && n_G(sequence, i + 1) == 1 && n_U(sequence, i + 2) == 1)
        {
            traduit[j] = 'C';
            j++;
        }
        else if (n_U(sequence, i) == 1 && n_G(sequence, i + 1) == 1 && n_C(sequence, i + 2) == 1)
        {
            traduit[j] = 'C';
            j++;
        }
        else if (n_U(sequence, i) == 1 && n_G(sequence, i + 1) == 1 && n_A(sequence, i + 2) == 1)
        {
            traduit[j] = '*';
            j++;
        }
        else if (n_U(sequence, i) == 1 && n_G(sequence, i + 1) == 1 && n_G(sequence, i + 2) == 1)
        {
            traduit[j] = 'W';
            j++;
        }
        //triplets commencant par UU
        else if (n_U(sequence, i) == 1 && n_U(sequence, i + 1) == 1 && n_U(sequence, i + 2) == 1)
        {
            traduit[j] = 'F';
            j++;
        }
        else if (n_U(sequence, i) == 1 && n_U(sequence, i + 1) == 1 && n_C(sequence, i + 2) == 1)
        {
            traduit[j] = 'F';
            j++;
        }
        else if (n_U(sequence, i) == 1 && n_U(sequence, i + 1) == 1 && n_A(sequence, i + 2) == 1)
        {
            traduit[j] = 'L';
            j++;
        }
        else
        {
            traduit[j] = 'M';
            j++;
        }
    }

    //sauvegarde de la séquence
    printf("Votre sequence a bien été traduite, elle est désormais enregistrée ici : %s \n", path_output);
    save_sequence(path_output, traduit);
}

void module_traduction()
{
    printf("\033[34;01mBienvenue dans le module 3: Traduction d'une séquence codante en séquence protéique\033[00m\n\n");
    //variables
    char path_input[256];
    char sequence[10000];

    printf("A partir de quel fichier souhaitez-vous extraire la séquence (Attention: elle doit être au format simplifié)? \n ");
    /* ex qui marche(Linux): /home/noemie/Desktop/projetc/orf46.txt */
    scanf("%s", path_input);
    extract_sequence(path_input, sequence);

    char path_output[256];
    printf("Dans quel fichier souhaitez-vous enregistrer votre sequence traduite? \n");
    scanf("%s", path_output);

    traduction(path_output, sequence);
}
