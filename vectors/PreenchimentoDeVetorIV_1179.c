// Neste problema você deverá ler 15 valores colocá-los em 2 vetores conforme estes valores forem pares ou ímpares. Só que o tamanho de cada um dos dois vetores é de 5 posições. Então, cada vez que um dos dois vetores encher, você deverá imprimir todo o vetor e utilizá-lo novamente para os próximos números que forem lidos. Terminada a leitura, deve-se imprimir o conteúdo que restou em cada um dos dois vetores, imprimindo primeiro os valores do vetor impar. Cada vetor pode ser preenchido tantas vezes quantas for necessário.
// Entrada: A entrada contém 15 números inteiros.
// Saída: Imprima a saída conforme o exemplo abaixo.
#include <stdio.h>
int main() {
    int par[5], impar[5], i, a, p=0, imp=0;
    int length = sizeof(par) / sizeof(par[0]);
    for(i=0; i<15; i++) {
        scanf("%d", &a);
        if(a%2==0) {
            par[p++] = a;
            if(p==5) {
                for(int j=0; j<length; j++) printf("par[%d] = %d\n", j, par[j]);
                p = 0;
            }
        }
        else {
            impar[imp++] = a;
            if(imp == 5) {
                for(int j=0; j<length; j++) printf("impar[%d] = %d\n", j, impar[j]);
                imp = 0;
            }
        }

    }
    for(i=0; i < imp; i++) printf("impar[%d] = %d\n", i, impar[i]);
    for(i=0; i < p; i++) printf("par[%d] = %d\n", i, par[i]);

    return 0;
}
