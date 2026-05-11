/* Nome do arquivo: lista.c
 * Autoria: Larissa Gondim
 * Data: 11/05/2026
 * Descrição: funções que realizam operações com lista
 * Versão: 1.0
 * */
// includes (nesse caso, só o padrão)
#include <stdio.h>
// MACROS
#define TAM 10

// tipo estruturado que representa lista
typedef struct lista {
    int v[TAM];
    int ctr;
} ll;

// protótipo de funções auxiliares
/**
 * 'ehcheia'
 * @brief função que verifica se a lista está cheia ou não
 * @param v: lista em análise
 * @return 1 caso esteja cheia, 0 caso contrário 
 */
int ehcheia(ll v);

/**
 * 'ehvazia'
 * @brief função que verifica se a lista está vazia ou não
 * @param v: lista em análise
 * @return 1 caso esteja vazia, 0 caso contrário 
 */
int ehvazia(ll v);

/**
 * 'esvazia'
 * @brief função que esvazia elementos da lista ao igualar control a -1
 * @param v: lista em análise
 * @return por ser void, não possui retorno
 */
void esvazia(ll *v);

/**
 * 'insere'
 * @brief função que insere elemento na lista
 * @param v: lista em análise
 * @return por ser void, não possui retorno, apenas modifica
 */
void insere(ll *v, int elemento);

/**
 * 'mostra'
 * @brief função que printa lista
 * @param v: lista em análise
 * @return por ser void, não possui retorno
 */
void mostra(ll *v);

// ---------- MAIN ----------

int main(void) {
    int elementos;
    ll l;
    l.ctr = -1;   
    if(ehvazia(l)) 
        printf("A lista está vazia! \nÉ possível preenchê-la");

    printf("Quantos elementos deseja inserir? ");
    scanf("%d", &elementos);
    
    for(int i = 0; i < elementos; i++) {
        int elemento;
        scanf("%d", &elemento);
        insere(&l, elemento);
    }

    mostra(&l);

    return 0;
}

int ehcheia(ll v) {
    if(v.ctr == (TAM - 1)) return 1;
    else return 0;
}

int ehvazia(ll v) {
    if(v.ctr == -1) return 1;
    else return 0;
}

void esvazia(ll *v) {
    v -> ctr = -1;
}

void insere(ll *v, int elemento) {
    if(!ehcheia(*v)) {
        v->ctr++;
        v->v[v->ctr] = elemento;
    }
}
void mostra(ll *v) {
    printf("A lista criada foi: [");

    for(int i = 0; i <= v->ctr; i++) {
        if(i == v->ctr)
            printf("%d", v->v[i]);
        else
            printf("%d, ", v->v[i]);
    }

    printf("]\n");
}
