/* Nome do arquivo: 'minusculo.c'                                                                                                                                                                                                                   
 * Autor: Larissa Gondim
 * Data: 16/05/2026
 * Descrição: Programa que recebe uma string como parâmetro e converte caracteres maiúsculos para minúsculos
 * Versão: 1.0
 */

// includes (apenas o padrão)
#include <stdio.h>

// protótipo de funções auxiliares

// 'minusculo'
/// @brief função que altera a ocorrência de caracteres maiúsculos para minúsculos
/// @param *str string que será modificada
/// @return nada pois é void
void minusculo(char *str);

// ---------- MAIN ----------
int main(void) {
    char string[21];

    printf("\nInsira a string que se deseja manipular: ");
    scanf("%20[^\n]", string);

    printf("\nString antes: %s", string);

    // aplica método
    minusculo(string);

    printf("\nString depois: %s", string);

    return 0;
}

// corpo das funções auxiliares
void minusculo(char *str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += ('a' - 'A');
    }
}