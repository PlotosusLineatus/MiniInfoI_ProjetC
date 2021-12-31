#ifndef HEADER_MODULE_SEQUENCECODANTE_H 
#define HEADER_MODULE_SEQUENCECODANTE_H 

    //La structure utilisée
    typedef struct Orf{
    int start; //position du codon start 
    int stop; //position du codon stop
    int longueur; //en nb d'AA
    }Orf;

    //Les fonctions demandées pour module_traduction
    void module_SequenceCodante(char* sequence);
    void inversionChaine(char* sequence);
    void Complementaire(char* sequence);
    char EcritureSequence(char* sequence, int debut, int fin);
    void ChercheSeq(const char* path_output, char* sequence);

#endif