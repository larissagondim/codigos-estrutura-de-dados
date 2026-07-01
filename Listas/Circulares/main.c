/* Nome do arquivo: main.c
 * Autoria: Larissa Gondim
 * Data: 17/05/2026
 * Descrição: menu principal para manipulação da lista circular
 * Versão: 1.0
 */

#include "lista_circular.h"

// ---------- MAIN ----------
int main(void) {

    // VARIÁVEIS
    // lista: tipo estruturado que cria lista
    // opcao: opção para menu interativo
    // num: valor que será inserido na lista
    // pos: posição que o valor será inserido em caso de inserção no meio
    lc lista;
    char opcao;
    int num;
    int pos;

    // esvazia lista caso esteja cheia
    esvazia_lista(&lista);

    do {
        printf("\n===== LISTA CIRCULAR =====\n");
        printf("1 - Inserir no início\n");
        printf("2 - Inserir no final\n");
        printf("3 - Inserir no meio\n");
        printf("4 - Imprimir lista\n");
        printf("0 - Sair\n");

        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        switch(opcao) {
            case '1':
                printf("\nLista antes da inserção:\n");
                imprimir(&lista);

                printf("\nDigite o número: ");
                scanf("%d", &num);

                insercao_no_inicio(&lista, num);

                printf("\nLista depois da inserção:\n");
                imprimir(&lista);

                break;

            case '2':
                printf("\nLista antes da inserção:\n");
                imprimir(&lista);

                printf("\nDigite o número: ");
                scanf("%d", &num);

                insercao_no_final(&lista, num);

                printf("\nLista depois da inserção:\n");
                imprimir(&lista);

                break;

            case '3':
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

            case '4':
                printf("\nEstado atual da lista:\n");
                imprimir(&lista);

                break;

            case '0':
                printf("\nEncerrando programa...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }
    } while(opcao != '0');

    return 0;
}