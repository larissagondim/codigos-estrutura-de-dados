/* Nome do arquivo: lista_circular.c
 * Autoria: Larissa Gondim
 * Data: 17/05/2026
 * Descrição: operações básicas com listas circulares com menu interativo e simulado
 * Versão: 1.0
 * */

// includes (apenas os padrão)
#include <stdio.h>
#include <stdlib.h>

// macros
#define TAM 10

// ESTRUTURAS: 

// 'lc'
// representa a estrutura comum de lista que será utilizada na lista circular
// inicio: ponteiro para o início da lista
// fim: ponteiro para o final da lista
// ctr: controle lógico do tamanho da lista
typedef struct {
    int ctri;
    int ctrf;
    int v[TAM];
} lc;

// PROTÓTIPO DE FUNÇÕES AUXILIARES

// 'esvazia_lista'
/// @brief função que inicializa/esvazia a lista circular, definindo os índices de início e fim como -1
/// @param *lista ponteiro para a lista circular que será inicializada
/// @return nada pois é void
void esvazia_lista(lc *lista);

// 'imprimir'
/// @brief função que imprime todos os elementos da lista circular na ordem lógica
/// @param *lista ponteiro para a lista circular que será exibida
/// @return nada pois é void
void imprimir(lc *lista);

// 'insercao_no_inicio'
/// @brief função que insere um novo elemento no início da lista circular
/// @param *lista ponteiro para a lista circular
/// @param num valor que será inserido
/// @return nada pois é void
void insercao_no_inicio(lc *lista, int num);

// 'insercao_no_final'
/// @brief função que insere um novo elemento no final da lista circular
/// @param *lista ponteiro para a lista circular
/// @param num valor que será inserido
/// @return nada pois é void
void insercao_no_final(lc *lista, int num);

// 'insercao_no_meio'
/// @brief função que insere um novo elemento em uma posição específica da lista circular
/// @param *lista ponteiro para a lista circular
/// @param pos posição lógica onde o elemento será inserido
/// @param num valor que será inserido
/// @return nada pois é void
void insercao_no_meio(lc *lista, int pos, int num);

// 'lista_cheia'
/// @brief função que verifica se a lista circular está cheia
/// @param *lista ponteiro para a lista circular
/// @return 1 caso a lista esteja cheia e 0 caso contrário
int lista_cheia(lc *lista);

// 'lista_vazia'
/// @brief função que verifica se a lista circular está vazia
/// @param *lista ponteiro para a lista circular
/// @return 1 caso a lista esteja vazia e 0 caso contrário
int lista_vazia(lc *lista);



// ---------- MAIN ----------
int main(void) {

    lc lista;
    int opcao;
    int num;
    int pos;

    esvazia_lista(&lista);

    do {
        printf("\n===== LISTA CIRCULAR =====\n");
        printf("1 - Inserir no início\n");
        printf("2 - Inserir no final\n");
        printf("3 - Inserir no meio\n");
        printf("4 - Imprimir lista\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nLista antes da inserção:\n");
                imprimir(&lista);

                printf("\nDigite o número: ");
                scanf("%d", &num);

                insercao_no_inicio(&lista, num);

                printf("\nLista depois da inserção:\n");
                imprimir(&lista);

                break;
            case 2:
                printf("\nLista antes da inserção:\n");
                imprimir(&lista);

                printf("\nDigite o número: ");
                scanf("%d", &num);

                insercao_no_final(&lista, num);

                printf("\nLista depois da inserção:\n");
                imprimir(&lista);

                break;
            case 3:
                printf("\nLista antes da inserção:\n");
                imprimir(&lista);

                printf("\nDigite a posição: ");
                scanf("%d", &pos);

                printf("Digite o número: ");
                scanf("%d", &num);

                insercao_no_meio(&lista, pos, num);

                printf("\nLista depois da inserção:\n");
                imprimir(&lista);

                break;
            case 4:
                printf("\nEstado atual da lista:\n");
                imprimir(&lista);

                break;

            case 0:
                printf("\nEncerrando programa...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }

    } while(opcao != 0);

    return 0;
}

// corpo de funções auxiliares
void esvazia_lista(lc *lista) {
    lista->ctri = -1;
    lista->ctrf = -1;
}

void imprimir(lc *lista) {

    if (lista_vazia(lista)) {
        printf("\nLista vazia!");
        return;
    }

    int i = lista->ctri;
    while (1) {
        printf("%d ", lista->v[i]);
        if (i == lista->ctrf)
            break;
        i = (i + 1) % TAM;
    }
    printf("\n");
}

void insercao_no_inicio(lc *lista, int num) {
    // verifica se está cheia
    if (lista_cheia(lista)) {
        printf("\nLista cheia!");
        return;
    }

    // primeira inserção
    if (lista_vazia(lista)) {
        lista->ctri = 0;
        lista->ctrf = 0;
    }
    else 
        lista->ctri = (lista->ctri - 1 + TAM) % TAM;
    lista->v[lista->ctri] = num;
}

void insercao_no_final(lc *lista, int num) {
    // verifica se está cheia
    if (lista_cheia(lista)) {
        printf("Lista cheia!\n");
        return;
    }

    // primeira inserção
    if (lista->ctri == -1) {
        lista->ctri = 0;
        lista->ctrf = 0;
    }
    else {
        // avança circularmente o final
        lista->ctrf = (lista->ctrf + 1) % TAM;
    }

    lista->v[lista->ctrf] = num;
}

void insercao_no_meio(lc *lista, int pos, int num) {
    // verifica lista cheia
    if (lista_cheia(lista)) {
        printf("Lista cheia!\n");
        return;
    }

    // lista vazia
    if (lista_vazia(lista)) {
        lista->ctri = 0;
        lista->ctrf = 0;
        lista->v[0] = num;
        return;
    }

    // calcula tamanho atual
    int tamanho = (lista->ctrf - lista->ctri + TAM) % TAM + 1;

    // posição inválida
    if (pos < 0 || pos > tamanho) {
        printf("Posição inválida!\n");
        return;
    }

    // inserção no final
    if (pos == tamanho) {
        insercao_no_final(lista, num);
        return;
    }

    // avança o final
    lista->ctrf = (lista->ctrf + 1) % TAM;

    // desloca elementos para direita
    for (int i = tamanho; i > pos; i--) {
        int atual = (lista->ctri + i) % TAM;
        int anterior = (lista->ctri + i - 1) % TAM;
        lista->v[atual] = lista->v[anterior];
    }

    // insere novo elemento
    int indice = (lista->ctri + pos) % TAM;
    lista->v[indice] = num;
}

int lista_vazia(lc *lista) {
    return (lista->ctri == -1);
}

int lista_cheia(lc *lista) {
    return ((lista->ctrf+1) % TAM == lista->ctri);
}
