/* Nome do arquivo: hanoi.c
 * Autoria: Larissa Gondim
 * Data: 30/06/2026
 * Descrição: implementação da torre de Hanoi com pilhas
 * Versão: 1.0
 */

// INCLUDES
// padrão + string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MACROS
// MAX: define tamanho da pilha
#define MAX 20

// ESTRUTURAS

// 'pilha'
// representa a estrutura comum de pilha que será utilizada nas implementações
// topo: elemento localizado no topo da pilha
// vetor[MAX]: elementos da pilha
typedef struct {
    int vetor[MAX];
    int topo;
    char nome[20];
} Pilha;

// Corpo de funções auxiliares

Pilha *cria_pilha(const char *nome) {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    if (!pilha) return NULL;
    pilha->topo = -1;
    strncpy(pilha->nome, nome, 19);
    return pilha;
}

void libera_pilha(Pilha **pilha) {
    if (pilha && *pilha) {
        free(*pilha);
        *pilha = NULL;
    }
}

int pilha_cheia(Pilha *pilha) {
    if (!pilha) return -1;
    return (pilha->topo == MAX - 1);
}

int pilha_vazia(Pilha *pilha) {
    if (!pilha) return -1;
    return (pilha->topo == -1);
}

int push(Pilha *pilha, int elemento) {
    if (!pilha || pilha_cheia(pilha)) return 0;
    pilha->vetor[++(pilha->topo)] = elemento;
    return 1;
}

int pop(Pilha *pilha, int *elemento) {
    if (!pilha || pilha_vazia(pilha) || elemento == NULL) return 0;
    *elemento = pilha->vetor[(pilha->topo)--];
    return 1;
}

void hanoi(int n, Pilha *origem, Pilha *destino, Pilha *auxiliar) {
    if (n == 1) {
        int disco;
        pop(origem, &disco);
        push(destino, disco);
        printf("Move disco %d de %s para %s\n", disco, origem->nome, destino->nome);
        return;
    }
    
    hanoi(n - 1, origem, auxiliar, destino);
    
    int disco;
    pop(origem, &disco);
    push(destino, disco);
    printf("Move disco %d de %s para %s\n", disco, origem->nome, destino->nome);
    
    hanoi(n - 1, auxiliar, destino, origem);
}

// main

int main() {
    int n;

    printf("Digite o numero de discos para a torre de Hanoi: ");
    if (scanf("%d", &n) != 1 || n > MAX || n < 1) {
        printf("Numero de discos invalido (min 1, max %d).\n", MAX);
        return 1;
    }

    Pilha *p1 = cria_pilha("Haste Inicial");
    Pilha *p2 = cria_pilha("Haste Auxiliar");
    Pilha *p3 = cria_pilha("Haste Final");

    // Preenche a haste inicial (do maior para o menor)
    for (int i = n; i >= 1; i--) 
        push(p1, i);
    
    printf("\nIniciando Movimentos\n");
    hanoi(n, p1, p3, p2);
    printf("Concluido\n");

    libera_pilha(&p1);
    libera_pilha(&p2);
    libera_pilha(&p3);

    return 0;
}