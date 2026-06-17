/* Nome do arquivo: balanceada.c
 * Autoria: Larissa Gondim
 * Data: 16/06/2026
 * Descrição: função que verifica se uma expressão com {}, [] e () está balanceada
 * Versão: 1.0
 */

#include "pilha.h"

int balanceada(char* expressao) {
    // cria a pilha vazia para guardar as aberturas
    Pilha* p = cria_pilha();
    
    // percorre caractere por caractere da expressÃo
    for(int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];
        
        // se for uma abertura, empilha
        if(c == '(' || c == '[' || c == '{') 
            push(p, c);  
        
        // se for um fechamento, verifica
        else if(c == ')' || c == ']' || c == '}') {

            // se tiver vazia, fechou sem ter aberto
            if(pilha_vazia(p)) {
                libera_pilha(&p);
                return 0;
            }
            
            // remove topo para verificar
            int topo;
            pop(p, &topo);
            
            // se o topo corresponder ao fechamento (se o atual ('c') corresponde ao fechamento)
            // exemplo: se c = '(' entÃo topo = ')', pois deve haver correspondÊncia
            // caso contrario, eh falso, xau pilha
            if((c == ')' && topo != '(') ||
               (c == ']' && topo != '[') ||
               (c == '}' && topo != '{')) {
                libera_pilha(&p);
                return 0;
            }
        }
    }
    
    // verifica se sobrou algo
    // se tiver vazia, balanceada!
    // caso contrÁrio, desbalanceada
    int resultado = pilha_vazia(p);
    libera_pilha(&p);
    return resultado;
}

int main() {
    printf("%d\n", balanceada("{{(())}}"));  
    printf("%d\n", balanceada("{{()}}"));    
    printf("%d\n", balanceada("{{0}}"));     
    printf("%d\n", balanceada("({[]})"));    
    printf("%d\n", balanceada("({[}])"));    
    return 0;
}