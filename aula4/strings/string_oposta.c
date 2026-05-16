/* Nome do arquivo: 'string_oposta.c'                                                                                                                                                                                                                   
 * Autor: Larissa Gondim
 * Data: 16/05/2026
 * Descrição: Programa que substitui todas as letras por sua oposta no alfabeto (isto é, a<->z, b<->y)
 * Versão: 1.0
 */

// includes
#include <stdio.h>

// macros
#define TAM 21
// protótipo de funções auxiliares
void string_oposta(char *str);

// ---------- MAIN ----------
int main(void) {

    // determinando espaço na memória e lendo string
    char string[TAM];
    if (scanf("%20[^\n]", string) != 1) 
        return 1;

    // mostra string antes
    printf("\nString antes: %s", string);

    // aplica método e mostra string depois
    string_oposta(string);
    printf("\nString depois: %s", string);

    return 0;
}

// corpo de funções auxiliares:
/*                                                                                                                                                                                                                 
 * Esse código faz o seguinte:
 * Se for letra (seja maiúscula ou minúscula):
 * Para achar sua 'oposta' no alfabeto, pega a última letra e subtrai pela distância da letra desejada até a primeira letra
 */

void string_oposta(char *str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') 
            str[i] = 'Z' - (str[i] - 'A');
        else if(str[i] >= 'a' && str[i] <= 'z') 
            str[i] = 'z' - (str[i] - 'a');
    }
}