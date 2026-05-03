#include <stdio.h>
#include "eh_primo.h"

int primo(int n) {
    if(n <= 1 || (n > 2 && n % 2 == 0)) return 0;
    if(n == 2) return 1;
    else {
        for(int i = 3; i * i <= n; i+=2) {
            if(n % i == 0) {
                return 0;
                break;
            }
        }
        return 1;
    }
}
