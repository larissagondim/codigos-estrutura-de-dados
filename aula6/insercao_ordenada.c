/* Nome do arquivo: insercao_ordenada.c
 * Autoria: Larissa Gondim
 * Data: 15/05/2026
 * Descrição: código que realiza operações genéricas em listas ordenadas
 * Versão: 1.0
 * */

 // includes necessários (apenas os padrão)
#include <stdio.h>
#include <stdlib.h>

// macros
#define TAM 10 // define tamanho do vetor que acompanha lista

// estruturas
// LISTA (lo = lista ordenada)
typedef struct {
    int v[TAM];
    int ctr;
} lo;

// funções auxiliares
int insere(lo *l, int elemento);

// ---------- MAIN ----------
int main(void) {
    int elemento;
    lo l = {{2, 5, 10, 23, 34, 53, 67, 78, 99}, 9};

    // usuário determina qual elemento será inserido
    printf("\nInsira o elemento: ");
    scanf("%d", &elemento);

    // inserindo elemento com função auxiliar
    if (!insere(&l, elemento)) {
        printf("\nErro: Nao foi possivel inserir. Lista cheia.\n");
        return 1;
    }

    printf("\nElemento inserido com sucesso!");
    // finalizando o código
    return 0;
}

// corpo das funções auxiliares
int insere(lo *l, int elemento) {
    int i, j;
    // verificando se não está cheia para evitar overflow
    if(l->ctr >= TAM) 
        return 0; 

    // buscando o índice para realizar inserção
    for(i = 0; i < l->ctr; i++) {
        if(l->v[i] > elemento) 
            break;
    }

    // deslocando os elementos após o índice para a direita para que o novo elemento seja inserido
    for(j = l->ctr; j > i; j--) 
        l->v[j] = l->v[j-1];

    
    // inserindo o elemento no índice desejado
    l->v[i] = elemento;
    l->ctr++;

    return 1;
}