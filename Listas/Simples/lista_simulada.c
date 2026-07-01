/*
Esse código não é de minha autoria e diz respeito a um exemplo de sala de aula.
Foi pedido para simulá-lo e encontrar seu erro.

O código está errado porque o laço começa em i = 0 e vai copiando
o próximo elemento para a posição atual:

    lista.vetor[i] = lista.vetor[i+1];

Isso faz com que TODOS os elementos sejam deslocados para a esquerda,
apagando o primeiro valor da lista, mesmo sem escolher qual elemento
deveria ser removido.

Além disso, quando i chega na última posição válida (i = 4),
o código tenta acessar:

    lista.vetor[5]

mas o vetor possui índices apenas de 0 até 4.
Esse acesso é inválido e causa comportamento indefinido.
*/

#include <stdio.h>

typedef struct {
    int vetor[5];
    int n;
} l;

int main(void) {
    int i;
    l lista = {{2, 3, 5, 6, 7}, 5};
    for(i = 0; i < lista.n; i++)
        lista.vetor[i] = lista.vetor[i+1];
        
    lista.n = lista.n-1;
    for(i = 0; i < lista.n; i++)
        printf("%d ", lista.vetor[i]);
    return 0;
}