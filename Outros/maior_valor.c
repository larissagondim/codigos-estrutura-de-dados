/* Nome do arquivo: maior_valor.c
 * Autoria: Larissa Gondim
 * Data: 18/05/2026
 * Descrição: função que tem como retorno o maior valor de uma lista implementada com um vetor de 100 posições
 * Versão: 1.0
 */

// includes (apenas os padrão)
#include <stdio.h>

// macros
#define TAM 100

// ESTRUTURAS:
// 'll'
// representa a estrutura comum de lista que será utilizada na lista circular
// v: vetor de 100 posições da lista
// ctr: controle lógico do tamanho da lista
typedef struct {
    int v[TAM];
    int ctr;
} ll;

// protótipo de funções auxiliares
// 'eh_cheia'
/// @brief função que verifica se a lista está cheia
/// @param *l ponteiro para a lista que será analisada
/// @return 1 caso esteja cheia, 0 caso contrário
int eh_cheia(ll *l);

// 'eh_vazia'
/// @brief função que verifica se a lista está vazia
/// @param *l ponteiro para a lista que será analisada
/// @return 1 caso esteja vazia, 0 caso contrário
int eh_vazia(ll *l);

// 'imprime'
/// @brief função que imprime todos os elementos da lista circular na ordem lógica
/// @param *l ponteiro para a lista circular que será exibida
/// @return nada pois é void
void imprime(ll *l);

// 'maior'
/// @brief função que retorna o maior elemento de uma lista de 100 elementos
/// @param *l ponteiro para a lista que será analisada
/// @return o maior número da lista
int maior(ll *l);

// 'preenche'
/// @brief função que preenche lista sem restrições
/// @param *l ponteiro para a lista que será analisada
/// @return nada pois é void
void preenche(ll *l);

// ---------- MAIN ----------
int main(void) {
    ll *lista;

    if(eh_cheia(lista)) {
        printf("\nA lista está cheia, não é possível preencher.");
        return 1;
    }

    preenche(lista);

    printf("\nLista em análise: ");
    imprime(lista);

    int maior_elemento = maior(lista);

    printf("\nMaior elemento: '%d'", maior_elemento);

    return 0;
}

// corpo de funções auxiliares

int eh_cheia(ll *l) {
    if(l->ctr == TAM)
        return 1;
    return 0;
}

int eh_vazia(ll *l) {
    if(l->ctr == -1)
        return 1;
    return 0;
}

void imprime(ll *l) {
    int i;
    printf("\n[");
    for(i = 0; i < TAM-1; i++)
        printf("%d, ", l->v[i]);
    printf("%d]\n", l->v[i]);
}

int maior(ll *l) {
    int i, maior_elemento = l->v[0];
    for(i = 0; i < TAM; i++) {
        if(l->v[i] > maior_elemento) 
            maior_elemento = l->v[i];
    }
    return maior_elemento;
}

void preenche(ll *l) {
    for(int i = 0; i < TAM; i++) {
        printf("\nInsira o %d⁰ elemento: ", (i+1));
        scanf("%d", &l->v[i]);
    }
}