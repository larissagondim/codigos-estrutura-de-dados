/* Nome do arquivo: 'shift_string.c'                                                                                                                                                                                                                   
 * Autor: Larissa Gondim
 * Data: 16/05/2026
 * Descrição: Programa que substitui todas as letras por suas sucessoras no alfabeto
 * Observações: a letra 'z' deve ser substituída pela letra 'a' (mesma coisa com 'Z' e 'A')
 * Versão: 1.0
 */

// includes (apenas o padrão)
#include <stdio.h>

// macros
#define TAM_BUFFER 21
// protótipo de funções auxiliares:
// 'shift_string'
/// @brief função que substitui todas as letras por suas sucessoras no alfabeto. A letra 'z' deve ser substituída pela letra 'a' (mesma coisa com 'Z' e 'A')
/// @param *str string que será modificada
/// @return nada pois é void
void shift_string(char *str);

// ---------- MAIN ----------
int main(void) {

    char string[TAM_BUFFER];
    
    // lê a string e mostra como ela era antes do deslocamento
    printf("\nInsira a string: ");
    if (scanf("%20[^\n]", string) != 1) 
        return 1;
    
    printf("\nString antes: %s", string);

    // modifica a string e mostra como ficou
    shift_string(string);
    printf("\nString depois: %s", string);

    return 0;
}

// corpo das funções auxiliares

void shift_string(char *str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            if(str[i] == 'Z')
                str[i] = 'A';
            else 
                str[i] += 1;
        }
        else if(str[i] >= 'a' && str[i] <= 'z') {
            if(str[i] == 'z')
                str[i] = 'a';
            else 
                str[i] += 1;
        }
    }
}