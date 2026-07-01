/* Nome do arquivo: calculadora_pos_fixada.c
 * Autoria: Larissa Gondim
 * Data: 08/06/2026
 * Descrição: calculadora pós fixada com funções de pilha
 * Versão: 1.0
 */

#include "pilha.h"
#include <string.h>
#include <ctype.h>

#define TAM 100

int main(void) {
    char expressao[TAM];
    Pilha *pilha_resultados = cria_pilha();

    if(!pilha_resultados) {
        printf("\nErro ao alocar memória para pilha.");
        return 1;
    }

    int op1, op2, resultado;

    while (scanf("%s", expressao) == 1) {
        if (expressao[0] == '=') break;  // '=' termina
        if (isdigit(expressao[0]) || (expressao[0] == '-' && isdigit(expressao[1])))
            push(pilha_resultados, atoi(expressao));
        else {
            if(pilha_vazia(pilha_resultados)) {
                printf("\nExpressão sem operandos.");
                libera_pilha(&pilha_resultados);
                return 1;
            }
            pop(pilha_resultados, &op1);

            if(pilha_vazia(pilha_resultados)) {
                printf("\nExpressão sem operandos.");
                libera_pilha(&pilha_resultados);
                return 1;
            }
            pop(pilha_resultados, &op2);

            switch(expressao[0]) {
                case '+':
                    resultado = op1 + op2;
                    break;
                case '-':
                    resultado = op2 - op1;
                    break;
                case '*':
                    resultado = op1 * op2;
                    break;
                case '/':
                    resultado = op2 / op1;
                    break;
                default:
                    printf("\nOperador inválido: %s", expressao);
                    libera_pilha(&pilha_resultados);
                    return 1;
            }
            push(pilha_resultados, resultado);
        }
    }

    if(pilha_vazia(pilha_resultados)) {
        printf("\nExpressão inválida.");
        libera_pilha(&pilha_resultados);
        return 1;
    }
    pop(pilha_resultados, &resultado);
    
    if(pilha_vazia(pilha_resultados)) {
        printf("\nResultado: %d\n", resultado);
        libera_pilha(&pilha_resultados);
        return 0; 
    }
    else {
        printf("\nExpressão inválida.");
        libera_pilha(&pilha_resultados);
        return 1;
    }
}  