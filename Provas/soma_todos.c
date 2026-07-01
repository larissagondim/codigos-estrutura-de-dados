#include <stdio.h>

#define TAM 100

struct lista {
    int v[TAM];
    int ctr;
};

int soma_todos(struct lista* l) {
    if(l == NULL) return 0;

    int somatorio = 0;
    for(int i = 0; i < l -> ctr; i++) 
        somatorio += l -> v[i];
    
    return somatorio;
}