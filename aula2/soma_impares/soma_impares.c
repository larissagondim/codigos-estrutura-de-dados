#include <stdio.h>
#include "soma_impares.h"

int soma_impares(int n) {
    int somatorio = 0, i = 1;
    while(n--) {
	somatorio += i;
        i++;
    }
    return somatorio;
}
