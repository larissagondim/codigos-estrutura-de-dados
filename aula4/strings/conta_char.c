/* Nome do arquivo: 'conta_vogal.c'                                                                                                                                                                                                                   
 * Autor: Larissa Gondim
 * Data: 16/05/2026
 * Descrição: Programa que conta a ocorrência de um char numa cadeia de caracteres
 * Versão: 1.0
 */

#include <stdio.h>

// protótipo de funções auxiliares
/* 'conta_char'
* @brief função que conta a ocorrência de um caractere numa string
* @param *str string que se deseja analisar
* @param c char que se deseja verificar ocorrências
* @return quantas vezes esse caractere apareceu
*/
int conta_char(const char* str, char c);

// ---------- MAIN ----------
int main(void) {
    char string[81], letra;
    int n_char;

    printf("\nInsira qual string você deseja analisar: ");
    // o formatador %80[^\n] lê uma sequência de 80 caracteres até que o usuário tecle enter
    scanf(" %80[^\n]", string);

    printf("\nInsira qual char você deseja contabilizar ocorrência: ");
    scanf(" %c", &letra);

    n_char = conta_char(string, letra);

    printf("\nA letra '%c' aparece %d vezes na string '%s'", letra, n_char, string);
    return 0;
}

// corpo das funções auxiliares
int conta_char(const char* str, char c) {
    int contador = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == c)
            contador++;
    }
    return contador;
}