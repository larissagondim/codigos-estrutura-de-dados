#include <stdio.h>
#include "leibniz.h"

int main(void) {
    int n;
    printf("Insira o valor de expressões da aproximação: ");
    scanf("%d", &n);
    double pi = leibniz(n);
    printf("%.4lf\n", pi);

}
