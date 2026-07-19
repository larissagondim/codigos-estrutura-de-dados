
#### O que é Recursividade?

Recursividade ocorre quando uma função chama a si mesma. Toda função recursiva deve seguir uma estrutura básica composta por duas partes:

- **Caso recursivo:** a parte em que a função chama a si mesma para resolver uma porção menor do problema.
- **Caso base (ou condição de parada):** estabelece quando a função deve parar de chamar a si mesma.

Se não houver uma condição de parada, a função recursiva será executada infinitamente (causando o estouro da pilha de memória, conhecido como *Stack Overflow*). 

**Exemplo sem condição de parada:**

```c
void funcao() {
    printf("Essa é uma função recursiva.\n");
    funcao(); // chamada da própria função dentro da função
    printf("Fim da função (isso nunca será impresso).\n");
}
````

Nesse caso, a função vai entrar em loop infinito, uma vez que sempre chamará a si mesma. Agora, veja um exemplo clássico de função recursiva que tem condição de parada correta:

**Exemplo com condição de parada (Fibonacci):**


int fibonacci(int n) {
    if(n <= 0) return 0; // caso base para n = 0
    if(n == 1) return 1; // caso base para n = 1
    
    return fibonacci(n - 1) + fibonacci(n - 2); // chamada recursiva
}


Nesta implementação recursiva de Fibonacci, existem duas condições de parada (casos base):

- Quando `n <= 0`
    
- Quando `n == 1`

Se não houvesse essas condições, a função chamaria a si mesma infinitamente. Como existem as condições, ela para e começa a retornar os valores quando `n` chega nesses limites.

### Quando usar recursividade?

- Quando o problema possui uma **estrutura recursiva**, isto é, uma instância do problema contém uma instância menor do mesmo problema (como o cálculo de um fatorial, onde `n! = n * (n-1)!`) e essa menor instância pode ser resolvida diretamente.
    
- Quando a solução iterativa (usando laços de repetição como `for` ou `while`) for muito complexa, deixando o código difícil de ler e manter (como em varreduras de árvores e grafos).
    

### Quando não usar?

Quando você estiver lidando com sistemas onde a performance de execução e a memória são críticos. Apesar de ser uma técnica elegante e gerar códigos limpos, as funções recursivas são geralmente mais lentas que as soluções iterativas. Cada chamada recursiva exige movimentação de dados na pilha de execução do sistema (_Call Stack_), o que tem um custo computacional (overhead) muito mais alto.
