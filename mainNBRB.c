#include "utils.h"
#include "module_SequenceCodante.h"
#include "module_transcription.h"
#include "module_traduction.h"
#include "module_ScoreIdentite.h"
#include "module_SimilariteSequences.h"
#include "module_Consensus.h"

void menu(){
    //Variables du menu
    int module;
    int booleen=0;
    int reponse;

    printf("\033[35;01m1:\033[00m\t Recherche de la séquence codante de taille maximale\n");
    printf("\033[35;01m2:\033[00m\t Transcription d'une séquence ADN en séquence ARN\n");
    printf("\033[35;01m3:\033[00m\t Traduction d'une séquence codante en séquence protéique\n");
    printf("\033[35;01m4:\033[00m\t Calcul du score d'identité entre deux séquences de même longueur\n");
    printf("\033[35;01m5:\033[00m\t Calcul du score de similarité de polarité entre deux séquences de même longueur\n");
    printf("\033[35;01m6:\033[00m\t Recherche de la séquence consensus à partir d'un alignement multiple\n");
    printf("\nDans quel module souhaitez-vous aller? Veuillez taper son chiffre.\n");
    scanf("%d",&module);
    while(booleen==0){
        if(module==1){
            module_SequenceCodante();
            printf("Merci d'avoir utilisé le module de recherche de séquence, souhaitez-vous passer à un autre module? \033[31;01m1 pour continuer, 2 pour quitter\033[00m\n");
            scanf("%d",&reponse);
            if (reponse==1){
                menu();
            }
            else{
                printf("Merci d'avoir utilisé mon programme! A très vite \033[31;01m<3\033[00m\n");
                exit(0);
            }
        }
        else if(module==2){
            module_transcription();
            printf("Merci d'avoir utilisé le module de transcription d'une séquence, souhaitez-vous passer à un autre module? \033[31;01m1 pour continuer, 2 pour quitter\033[00m\n");
            scanf("%d",&reponse);
            if (reponse==1){
                menu();
            }
            else{
                printf("Merci d'avoir utilisé mon programme! A très vite \033[31;01m<3\033[00m\n");
                exit(0);
            }
        }
        else if(module==3){
            module_traduction();
            printf("Merci d'avoir utilisé le module de traduction de séquence, souhaitez-vous passer à un autre module? \033[31;01m1 pour continuer, 2 pour quitter\033[00m\n");
            scanf("%d",&reponse);
            if (reponse==1){
                menu();
            }
            else{
                printf("Merci d'avoir utilisé mon programme! A très vite \033[31;01m<3\033[00m\n");
                exit(0);
            }
        }
        else if(module==4){
            module_ScoreIdentite();
            printf("\nMerci d'avoir utilisé le module de calcul de score d'identité, souhaitez-vous passer à un autre module? \033[31;01m1 pour continuer, 2 pour quitter\033[00m\n");
            scanf("%d",&reponse);
            if (reponse==1){
                menu();
            }
            else{
                printf("Merci d'avoir utilisé mon programme! A très vite \033[31;01m<3\033[00m\n");
                exit(0);
            }
        }
        else if(module==5){
            module_ScoreSimilaritePolarite();
            printf("\nMerci d'avoir utilisé le module de calcul de similarité de polarité, souhaitez-vous passer à un autre module? \033[31;01m1 pour continuer, 2 pour quitter\033[00m\n");
            scanf("%d",&reponse);
            if (reponse==1){
                menu();
            }
            else{
                printf("Merci d'avoir utilisé mon programme! A très vite \033[31;01m<3\033[00m\n");
                exit(0);
            }
        }
        else if(module==6){
            module_Consensus();
            printf("\nMerci d'avoir utilisé le module de séquence consensus, souhaitez-vous passer à un autre module? \033[31;01m1 pour continuer, 2 pour quitter\033[00m\n");
            scanf("%d",&reponse);
            if (reponse==1){
                menu();
            }
            else{
                printf("Merci d'avoir utilisé mon programme! A très vite \033[31;01m<3\033[00m\n");
                exit(0);
            }
        }
        else{
            printf("Vous avez du faire une erreur, seuls les chiffres \033[33;01m1, 2 et 3\033[00m sont autorisés, veuillez recommencer :)\n");
            scanf("%d", &module);
        }
    }
}


int main(int argc, char *argv[]){

	//Variables du main
    char reponse;
    
    printf("Bienvenue sur l'application d'analyse de séquences\n");
    printf("\nAvez-vous dans ce dossier votre(vos) fichier(s) contenant la(les) séquence(s) au format fasta \033[31;01msimplifié\033[00m?\n");
    printf("Veuillez taper Y une fois que c'est prêt :) \n");
    scanf("%c",&reponse);
    while(reponse!='Y'){
    	printf("\nPas encore prêt? Ce n'est pas grave, nous vous attendons ! ;)\nTapez \033[33;01mY\033[00m quand vous êtes prêt !\n");
    	scanf("%s",&reponse);
    }
    printf("Super! Voici les différents modules : \n");
    menu();
}

	
