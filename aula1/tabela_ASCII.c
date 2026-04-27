/*******************************************************
 * Nome do Arquivo: tabela_ASCII.c
 * Descrição: esse código é responsável por mostrar a tabela ASCII diretamente no terminal a partir de uma única variável (nesse caso, uma variável local 'i')
 * Autor: Larissa Gondim
 * Data de Criação: 27/04/2026
 *******************************************************/

#include <stdio.h>
#include <ctype.h>

int main(void) {
    printf("TABELA ASCII: \n");
    printf("----------------------\n");
    printf("DEC | CHAR | HEX | BIN\n");
    printf("----------------------\n");
    for(unsigned char i = 0; i < 255; i++) {
        if(isprint(i)) printf("%3d | %4c | %#2x | %b\n", i, i, i, i);
        else printf("%3d |      | %#2x | %b\n", i, i, i);
    }
}