/* Nome do arquivo: arvore_binaria.c
 * Autoria: Larissa Gondim
 * Data: 20/07/2026
 * Descrição: implementação das funções de árvore
 * Versão: 1.0
 */

#include "arvore_binaria.h"

// corpo das funções
// 'cria_arvore'
void cria_arvore(tArvBin *T) {
    *T = NULL;
}

// 'eh_vazia'
int eh_vazia(tArvBin T) {
    return (T == NULL);
}

// 'busca_arv'
tArvBin busca_arv(tArvBin T, int dado) {
    // cria uma árvore para armazenar onde foi encontrado o dado
    tArvBin achou;

    // verifica se a árvore está vazia
    if(T == NULL) return NULL;

    // elemento encontrado na raíz
    if(T->conteudo == dado) return T;

    // aplica recursividade
    // procura nos nós à esquerda da árvore
    achou = busca(T->esq, dado);

    // se não achou na esquerda, procura à direita
    if(achou == NULL) achou = busca(T->dir, dado);

    // retorna o nó intermediário
    return achou;
}

int insere_raiz(tArvBin *T, int dado) {
    // árvore não está vazia portanto a inserção não pode ser realizada
    if(T != NULL) return 0; 

    // cria o novo nó para colocá-lo na raíz e verifica se alocação deu certo
    tNo *novoNo = malloc(sizeof(tNo));
    if(novoNo == NULL) return 0;

    // preenche os valores do nó
    novoNo->conteudo = dado;
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    // substitui na raíz da árvore
    *T = novoNo;

    return 1;
}

int insere_direita(tArvBin T, int vPai, int vFilho) {

    tNo *f, *p, *novoNo;
    //Verifica se o elemento já não existe
    f = busca(T, vFilho);

    if (f != NULL) return 0; // dado já existe

    // busca o pai e verifica se possui filho direito
    p = busca(T, vPai);
    if (p == NULL) return 0; // pai não encontrado
    if (p->dir != NULL) return 0; // filho dir já existe

    novoNo = malloc(sizeof(tNo));

    if (novoNo == NULL) return (0); // mem. insuf.

    novoNo->conteudo = vFilho;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    p->dir = novoNo;

    return 1;
}

// 'insere_esquerda'
int insere_esquerda(tArvBin T, int vPai, int vFilho) {

    tNo *f, *p, *novoNo;
    //Verifica se o elemento já não existe
    f = busca(T, vFilho);

    if (f != NULL) return 0; // dado já existe

    // busca o pai e verifica se possui filho direito
    p = busca(T, vPai);
    if (p == NULL) return 0; // pai não encontrado
    if (p->esq != NULL) return 0; // filho esq já existe

    novoNo = malloc(sizeof(tNo));

    if (novoNo == NULL) return (0); // mem. insuf.

    novoNo->conteudo = vFilho;
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    p->esq = novoNo;

    return 1;
}

// funções de caminhamento

// 'exibe_preordem'
void exibe_preordem(tArvBin T) {
    // verifica se a árvore está vazia
    if(T == NULL) return;

    // exibe a raíz
    printf("%d  ", T->conteudo);

    // exibe as sub árvores à esquerda
    if(T->esq != NULL) exibe_preordem(T->esq);

    // exibe as sub árvores à direita
    if(T->dir != NULL) exibe_preordem(T->dir);
}

// 'exibe_posordem'
void exibe_posordem(tArvBin T) {
    // verifica se a árvore está vazia
    if(T == NULL) return;

    // exibe as sub árvores à esquerda
    if(T->esq == NULL) exibe_posordem(T->esq);

    // exibe as sub árvores à direita
    if(T->dir == NULL) exibe_posordem(T->dir);
    
    // exibe a raíz
    printf("%d  ", T->conteudo);
}

void exibe_inordem(tArvBin T) {
    // verifica se a árvore está vazia
    if(T == NULL) return;
    
    // exibe as sub árvores à esquerda
    if(T->esq == NULL) exibe_inordem(T->esq);

    // exibe a raíz
    printf("%d  ", T->conteudo);

    // exibe as sub árvores à direita
    if(T->dir == NULL) exibe_posordem(T->dir);
}