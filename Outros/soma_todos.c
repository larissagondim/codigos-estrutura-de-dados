/* Nome do arquivo: soma_todos.c
 * Autoria: Larissa Gondim
 * Data: 18/05/2026
 * Descrição: função que tem como retorno a soma dos valores de uma lista implementada com um vetor de 100 posições
 * Versão: 1.0
 */

// includes (apenas os padrão)
#include <stdio.h>

// macros
#define TAM 100

// ESTRUTURAS

typedef struct {
    int v[TAM];
    int ctr;
} ll;

// protótipo de funções auxiliares

// 'imprime'
/// @brief função que imprime todos os elementos da lista circular na ordem lógica
/// @param *l ponteiro para a lista circular que será exibida
/// @return nada pois é void
void imprime(ll *l);

// 'preenche'
/// @brief função que preenche lista sem restrições
/// @param *l ponteiro para a lista que será analisada
/// @return nada pois é void
void preenche(ll *l);

// 'soma_todos'
/// @brief função que tem como retorno a soma de todos os valores de uma lista implementada com um vetor de 100 posições
/// @param *l ponteiro para a lista que será analisada
/// @return somatório de todos os elementos da lista
int soma_todos(ll *l);

// ---------- MAIN ----------
int main(void) {
    ll *lista;

    preenche(lista);

    printf("\nLista em análise: ");
    imprime(lista);

    int somatorio = soma_todos(lista);

    printf("\nSoma dos elementos: '%d'", somatorio);

    return 0;
}

// corpo de funções auxiliares:

void imprime(ll *l) {
    int i;
    printf("\n[");
    for(i = 0; i < TAM-1; i++)
        printf("%2d, ", l->v[i]);
    printf("%2d]\n", l->v[i]);
}

void preenche(ll *l) {
    for(int i = 0; i < TAM; i++) {
        printf("\nInsira o %d⁰ elemento: ", (i+1));
        scanf("%d", &l->v[i]);
    }
}

int soma_todos(ll *l) {
    int i, soma = 0;
    for(i = 0; i < TAM; i++)
        soma += l->v[i];
}