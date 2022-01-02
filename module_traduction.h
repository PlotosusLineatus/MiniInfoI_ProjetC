#ifndef HEADER_MODULE_TRADUCTION_H 
#define HEADER_MODULE_TRADUCTION_H 


    //Les fonctions demandées pour module_traduction
    int n_A(char* seq, int i);
    int n_U(char* seq, int i);
    int n_G(char* seq, int i);
    int n_C(char* seq, int i);

    void module_traduction();

    void traduction(const char* path_output, char* sequence);

#endif