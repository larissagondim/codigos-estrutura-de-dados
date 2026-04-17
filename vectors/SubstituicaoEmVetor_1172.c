// Faça um programa que leia um vetor X[10]. Substitua a seguir, todos os valores nulos e negativos do vetor X por 1. Em seguida mostre o vetor X.
// Entrada: 10 valores inteiros, sendo positivos ou negativos
// Saída: Para cada posição do vetor, escreva "X[i] = x", onde i é a posição do vetor e x é o valor armazenado naquela posição.
#include <stdio.h>

int main(void) {
    int X[10], a;
    for(int i=0; i < (sizeof(X)/sizeof(X[0])); i++) {
        scanf("%d", &a);
        if(!(a > 0)) X[i] = 1;
        else X[i] = a;
        printf("X[%d] = %d\n", i, X[i]);
    }
    return 0;
}