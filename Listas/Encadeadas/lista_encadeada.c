/* Nome do arquivo: lista_encadeada.c
 * Autoria: Larissa Gondim
 * Data: 03/06/2026
 * Descrição: código que guarda o corpo das funções de manipulação de listas encadeadas
 * Versão: 1.0
 * */

 // includes necessários (apenas os padrão)
#include "lista_encadeada.h"

// corpo de funções auxiliares

// PASSO A PASSO:
// primeiramente, aloca espaço na memória para o nó (sai da função caso a requisição não funcione)
// adiciona o valor do parâmetro no nó
// zera os ponteiros pra que o nó não guarde lixo de memória
// retorna o nó recém-criado
No *cria_no(int info) {
    No *n = (No*)malloc(sizeof(No));
    if(!n)
        return;
    n->info = info;
    n->prox = NULL;
    n->ante = NULL;
    return n;
}

// PASSO A PASSO
// primeiramente, aloca dinamicamente espaço na memória para a lista (caso a requisição não funcione, sai da função)
// zera os ponteiro para lista não guarde lixo de memória
// retorna a lista recém criada
Lista cria_lista(void) {
    Lista *l = (Lista*)malloc(sizeof(Lista));
    
    if(!l) 
        return;
    
    l->inicio = NULL;
    l->fim = NULL;
    
    return l;
}

// PASSO A PASSO
// primeiramente, cria um novo nó com a função auxiliar "cria_no" (retorna 0 caso a alocação não tenha sido sucessiva)
// preenche o campo 'info' do novo nó com a informação recebida no parâmetro
// preenche o ponteiro anterior com 'null', uma vez que o novo nó se tornará o primeiro
// preenche o ponteiro prox com o valor que era, anteriormente, o inicial da lista
// se a lista não estiver vazia, o ponteiro anterior do antigo primeiro recebe o novo nó
// caso contrário, o ponteiro 'fim' recebe o novo nó
// finalmente, o ponteiro 'início' recebe o novo nó 
// retorna 1 pra indicar sucesso
int insere_inicio(Lista *ll, int valor) {
    No *novo = cria_no(valor);
    if(!novo)
        return 0;
    
    novo->info = valor;
    novo->ante = NULL;
    novo->prox = ll->inicio;
    
    if(!(ll->inicio))
        ll->fim = novo;
    else 
        ll->inicio->ante = novo;
    
    l->inicio = novo;

    return 1;
}

// PASSO A PASSO
// primeiramente, cria um novo nó com a função auxiliar "cria_no" (retorna 0 caso a alocação não tenha sido sucessiva)
// preenche o campo 'info' do novo nó com a informação recebida no parâmetro
// preenche o ponteiro prox com 'null', uma vez que o novo nó se tornará o primeiro
// se a lista estiver vazia, o novo nó vira o início e também o fim (lista unitária)
// caso contrário, cria um nó temporário que recebe o primeiro elemento da lista
// enquanto o ponteiro prox do nó temporário não for nulo, ele anda até o fim da lista
// quando chega no fim da lista, o ponteiro prox recebe o novo nó
// retorna 1 ao chegar no fim da função para indicar sucesso
int insere_fim(Lista *ll, int valor) {
    No *novo = cria_no(valor);
    if(!novo) 
        return 0;
    novo->info = valor;
    novo->prox = NULL;

    if(!(ll->inicio)) 
        ll->inicio = novo;
    else {
        No *temp = ll->inicio;
        while (!(temp->prox)) 
            temp = temp->prox;
        temp->prox = novo;
    }
    
    return 1;
}