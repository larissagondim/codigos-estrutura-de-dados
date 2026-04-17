// Faça um programa que leia um vetor N[20]. Troque a seguir, o primeiro elemento com o último, o segundo elemento com o penúltimo, etc., até trocar o 10º com o 11º. Mostre o vetor modificado.
// Entrada: A entrada contém 20 valores inteiros, positivos ou negativos.
// Para cada posição do vetor N, escreva "N[i] = Y", onde i é a posição do vetor e Y é o valor armazenado naquela posição.
#include <stdio.h>

int main(void) {
    int N[20], y, tam = sizeof(N)/sizeof(N[0]);
    for(int i=0; i < tam; i++) {
        scanf("%d", &y);
        N[tam-i-1] = y;
    }
    for(int i=0; i < tam; i++) printf("N[%d] = %d\n", i, N[i]);
    return 0;   
}