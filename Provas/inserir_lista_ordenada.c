/* Nome do arquivo: inserir_lista_ordenada.c                                                                                                                                                                                                                  
 * Autoria: Larissa Gondim
 * Data: 14/05/2026
 * Descrição: Programa que insere número 18 em lista ordenada
 * Versão: 1.1
 */

// includes necessários
#include <stdio.h>

// macros
#define TAM 11

// structs
typedef struct lista {
    int v[TAM];
    int ctr;
} ll;

// protótipo de funções auxiliares
void mostrar_lista(ll v, int ctr);

// ---------- MAIN ----------
// irei por output no terminal para fins de simulação
int main(void) {
    ll l = {{3, 5, 8, 9, 15, 17, 21, 34, 60, 99}, 10};
    int i, j, elemento = 18;

    // verificando se não vai ocorrer overflow
    if(l.ctr >= TAM) {
        printf("\nHouve overflow! Não cabem mais elementos na lista.");
        return 1;
    }
    // mostrando lista antes das mudanças
    mostrar_lista(l, l.ctr);
    
    // buscando o índice de inserção
    for(i = 0; i < l.ctr; i++) {
        if(l.v[i] > elemento)
            break;
    }
    // mostrando o índice
    printf("\nO número '%d' estará localizado no índice '%d'!\n", elemento, i);

    // shiftando os números após o índice para a direita
    for(j = l.ctr; j > i; j--) 
        l.v[j] = l.v[j-1];
    
    // mostrando lista após o shift:
    printf("\nLista após o shifting dos elementos para a esquerda: \n");
    mostrar_lista(l, l.ctr + 1);

    // inserindo o número 18 e atualizando ctr
    l.v[i] = elemento;
    l.ctr++;

    // mostrando a lista após as alterações
    printf("\nLista após a inserção: \n");
    mostrar_lista(l, l.ctr);

    return 0;
}

// corpo de funções auxiliares
void mostrar_lista(ll v, int ctr) {
    int i;
    printf("\nLista: {");
    for (i = 0; i < ctr-1; i++) {
        printf("%d, ", v.v[i]);
    }
    printf("%d}\n", v.v[i]);
}