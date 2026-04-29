#include <stdio.h>
#include "eh_primo.h"
int eh_primo(int n);

int main(void) {
    int n;
    scanf("%d", &n);
    printf("O número %d ", n);
    printf("%s\n ", (primo(n)) ? "é primo" : "não é primo");
    return 0;
}