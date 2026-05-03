#include <stdio.h>
// protótipo de funções 
int eh_primo(int n);
// ---------------- MAIN ----------------
// 'num': número a ser avaliado
int main(void) {
    int num;
    printf("Insira um número qualquer para ser avaliado: ");
    scanf("%d", &num);
    printf("\nO número %d ", num);
    printf("%s ", (eh_primo(num)) ? "é primo" : "não é primo");
    return 0;
}
/*@brief função que tem 2 valores de retorno a depender se o número é ou não primo
 *@param n número a ser avaliado
 *@return 1 se for primo,  0 se não for primo
 */
int eh_primo(int n) {
    if(n <= 1 || (n > 2 && n%2 == 0)) return 0;
    if(n == 2) return 1;
    for(int i = 3; i * i <= n; i+=2) {
        if(n % i == 0) {
	    return 0;
	    break;
	}
    }
    return 1;
}
