## Pilhas

Pilhas são estruturas de dados do tipo `lista` (_ou seja, um subconjunto de listas_) com restrições de acesso aos elmentos da seguinte forma:

- Apenas o último elemento inserido pode ser removido;
- Apenas o último elemento inserido pode ser acessado;

Essas restrições se referem ao tipo de acesso da pilha, que segue o modelo `LIFO (Last in, first out)`, que é, basicamente, último a entrar, primeiro a sair. 

Uma analogia para que haja um melhor entendimento do conceito de pilha é pensar numa pilha de pratos. Caso você queira adicionar um prato novo, deve-se colocar, obrigatoriamente, o novo prato do topo; da mesma forma, se precisar de um novo prato, você precisa buscar, novamente, o prato localizado do topo.

Não é possível buscar um elemento do meio da pilha sem antes **desempilhar**, isto é, retirar os elementos localizados no topo até encontrar o desejado. 

Em suma, a pilha tem as seguintes características que tornam possível sua identificação:

- É linear;
- Não é ordenada;
- Não pode consultar;
- Só vamos descobrir o tamanho dela quando removermos todos os elementos;
- Só vemos o topo;
- Só retiramos ou inserimos do topo;

Quando temos o **topo**, podemos dizer que a E.D. se trata de uma **pilha**, ou seja, uma estrutura com topo e base.

### Implementação em C

A estrutura de uma pilha é composta, basicamente, pelo topo e pela base. Em C, podemos escrever da seguinte maneira:

```c
struct pilha {
    int v[MAX];
    int topo;
};
typedef struct pilha Pilha;
```
### Operações de pilha

- **Push (empilhar)**: operação que insere um novo elemento no topo da pilha;
- **Pop (desempilhar)**: operação que retira e retorna o elemento localizado no topo da pilha;
- **Ver topo**: permite ver qual é o elemento do topo sem necessariamente retirá-lo da pilha;
- **Ver se está vazia**: retorna verdadeiro caso a pilha não possua nenhum elemento;
- **Liberar**: limpa a estrutura, removendo todos os elementos  da memória;

É mais eficiente realizar as operações no início, ou seja, no topo, pois, ao realizar as operações no fim, surge a necessidade de percorrer à estrutura de dados até que se chegue ao fim, realizando _n_ operações.
