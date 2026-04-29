#include <stdio.h>
#include <ctype.h>
#include "tabela_ASCII.h"

void mostrar_tabela_ascii(void) {
    printf("TABELA ASCII: \n");
    printf("----------------------\n");
    printf("DEC | CHAR | HEX | BIN\n");
    printf("----------------------\n");
    unsigned char i;
    for (i = 0; i < 254; i++) {
        if (isprint(i)) printf("%3d | %4c | %#2x | %b\n", i, i, i, i);
        else printf("%3d |      | %#2x | %b\n", i, i, i);
    }
    printf("%3d | %4c | %#2x | %b\n", i, i, i, i);
}