/* Nome do arquivo: mescla_sem_duplicatas.c
 * Autoria: Larissa Gondim
 * Data: 18/05/2026
 * Descrição: função que recebe duas listas ordenadas L1 e L2 e as junta numa lista L3, de maneira ordenada e sem duplicatas
 * Versão: 1.0
 */

// includes (apenas os padrão)
#include <stdio.h>

// macros
#define TAM 5 

// ESTRUTURAS
// 'ListaB'
// representa a estrutura comum de lista que será utilizada na implementação
// 'scores': vetor de 100 elementos que servirá de lista
// 'ctr': variável de controle lógico do tamanho da lista
struct ListaB {
    int scores[TAM * 2];
    int ctr;
};

// protótipo de funções auxiliares
// 'imprimir'
/// @brief função que imprime todos os elementos da lista circular na ordem lógica
/// @param *lista ponteiro para a lista circular que será exibida
/// @return nada pois é void
void imprime(struct ListaB *L);

// 'mescla_sem_duplicatas'
/// @brief função que recebe duas listas ordenadas L1 e L2 e as junta numa lista L3, de maneira ordenada e sem duplicatas
/// @param *L1: primeira lista
/// @param *L2: segunda lista
/// @param *L3: lista de destino
/// @return nada pois é void
void mescla_sem_duplicatas(struct ListaB *L1, struct ListaB *L2, struct ListaB *L3);

// 'ordena'
/// @brief função que ordena elementos de uma lista
/// @param *L: lista que será ordenada
/// @return nada pois é void
void ordena(struct ListaB *L);

// 'preenche'
/// @brief função que preenche lista por completo
/// @param *L: lista que será preenchida
/// @return nada pois é void
void preenche(struct ListaB *L);

// ---------- MAIN ----------
int main(void) {
    struct ListaB L1, L2, L3;

    printf("\nPreenchendo a primeira lista: ");
    preenche(&L1);

    printf("\nPreenchendo a segunda lista: ");
    preenche(&L2);

    ordena(&L1);
    printf("\nPrimeira lista: ");
    imprime(&L1);

    ordena(&L2);
    printf("\nSegunda lista: ");
    imprime(&L2);

    mescla_sem_duplicatas(&L1, &L2, &L3);

    printf("\nLista mesclada:\n");
    imprime(&L3);

    return 0;
}

// corpo de funções auxiliares

void imprime(struct ListaB *L) {
    int i;
    printf("[ ");
    for(i = 0; i < L->ctr-1; i++) 
        printf("%2d, ", L->scores[i]);
    printf("%2d]\n", L->scores[i]);
}

void mescla_sem_duplicatas(struct ListaB *L1, struct ListaB *L2, struct ListaB *L3) {
    int i, j;
    int existe;

    L3->ctr = 0;

    // copia elementos de L1
    for(i = 0; i < L1->ctr; i++) {
        L3->scores[L3->ctr++] = L1->scores[i];
    }

    // adiciona elementos de L2 apenas se não existirem
    for(i = 0; i < L2->ctr; i++) {
        existe = 0;
        for(j = 0; j < L3->ctr; j++) {
            if(L2->scores[i] == L3->scores[j]) {
                existe = 1;
                break;
            }
        }
        if(!existe) 
            L3->scores[L3->ctr++] = L2->scores[i];
    }
    ordena(L3);
}
void ordena(struct ListaB *L) {
    int i, j, temp;
    for(i = 0; i < L->ctr - 1; i++) {
        for(j = i + 1; j < L->ctr; j++) {
            if(L->scores[i] > L->scores[j]) {
                temp = L->scores[i];
                L->scores[i] = L->scores[j];
                L->scores[j] = temp;
            }
        }
    }
}

void preenche(struct ListaB *L) {
    L->ctr = TAM;
    for(int i = 0; i < L->ctr; i++) {
        printf("\nInsira o %d⁰ elemento: ", (i+1));
        scanf("%d", &L->scores[i]);
    }
}