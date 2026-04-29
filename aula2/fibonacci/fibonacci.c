#include <stdio.h>
#include "fibonacci.h"

int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;

    int a = 1, b = 1, proximo = 0;

    for (int i = 3; i <= n; i++) {
        proximo = a + b;
        a = b;
        b = proximo;
    }

    return b;
}