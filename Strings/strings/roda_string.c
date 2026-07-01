/* Nome do arquivo: 'roda_string.c'                                                                                                                                                                                                                   
 * Autor: Larissa Gondim
 * Data: 16/05/2026
 * Descrição: Desloca os caracteres da string em 1 posição para a direita (o último vai para o início da função)
 * Versão: 1.0
 */

// includes (apenas o padrão)
#include <stdio.h>
#include <string.h>

// macros
#define TAM 21 // tamanho da string

// protótipo de funções auxiliares
// 'roda_string'
/// @brief função que desloca os caracteres da string em 1 posição para a direita
/// @param *str string que será modificada
/// @return nada pois é void
void roda_string(char *str);

// ---------- MAIN ----------
int main(void) {
    // aloca espaço na memória para a string, a recebe e mostra como estava antes das alterações
    char string[TAM];
    if (scanf("%20[^\n]", string) != 1) 
        return 1;
    printf("\nString antes: %s", string);

    // modifica e mostra como a string ficou após as alterações
    roda_string(string);
    printf("\nString depois: %s", string);

    return 0;
}

// corpo das funções auxiliares
/*                                                                                                                                                                                                                 
 * Esse código faz o seguinte:
 * - Salva o último caractere da string antes da modificação
 * - Percorre a string e a cada iteração, desloca um caractere para a direita
 * - Após todo o processo (que vai até o penúltimo caractere para evitar overflow), atribui o último caractere original ao primeiro caractere
 */
void roda_string(char *str) {
    int tam = (int)strlen(str);
    
    // vê se está vazia
    if (tam <= 1) 
        return;
    
    // salva o ÚLTIMO caractere antes da mutação do vetor
    char ultimo_original = str[tam - 1];
    
    // deslocamento físico para a DIREITA 
    for (int i = tam - 1; i > 0; i--) 
        str[i] = str[i - 1];
    str[0] = ultimo_original;
}