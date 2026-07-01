

#include <stdio.h>

#define TAM 11

typedef struct {
    int v[TAM];
    int ctr;
} ll;

int main(void) {
    ll l = {{3, 5, 8, 9, 15, 17, 21, 34, 60, 99}, 10};
    int i, j, elemento = 18;

    if(l.ctr == TAM) {
        printf("\nLista cheia");
        return 1;
    }

    for(i = 0; i < l.ctr; i++) {
        if(l.v[i] > elemento) 
            break;
    }

    for(j = l.ctr; j > i; j--)
        l.v[j] = l.v[j-1];

    l.v[i] = elemento;
    l.ctr++;
}