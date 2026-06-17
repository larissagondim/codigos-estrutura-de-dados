## Listas circulares

Algumas aplicações exigem que as informações sejam dispostas de maneira cíclica, isto é, não existe, definitivamente, um início ou fim para a informação. Um exemplo disso seriam jogos de tabuleiro de turno, nos quais a lista de jogadores continua "rodando" até que todas as rodadas tenham sido concluídas, ou seja, existe um final lógico na disposição dos dados.

A estrutura de dados que representa essa disposição consiste na `lista circular`, que é uma variação da `lista simplesmente encadeada`. A diferença fundamental é que o último elemento da `lista circular` aponta para o primeiro, formando um círculo.

O último elemento, diferentemente da lista tradicional, não aponta para **NULL**, mas sim de volta para o primeiro elemento da lista, fechando o ciclo. E é por causa desse rigor que não faz sentido falar em **"primeiro elemento"** ou **"último elemento"**. Para cada elemento, podemos apenas dizer que ele "vem antes" ou "vem depois" de outro elemento. 

### Estrutura interna

As listas circulares têm duas principais variações:

* Lista circular simplesmente encadeada, na qual cada nó possui apenas um ponteiro para o próximo elemento;
* Lista circular duplamente encadeada, na qual cada nó possui ponteiros para o próximo e para o anterior elemento; 

### Implementação em C

A estrutura de uma lista circular é praticamente idêntica a de uma lista simplesmente encadeada, com a diferença de que o ponteiro para o próximo elemento do último nó aponta para o primeiro nó da lista, ao invés de apontar para NULL. Podemos escrever da seguinte maneira:

```c
struct no_circular {
    int dado;
    struct no_circular *prox;
};

typedef struct no_circular Circular;
```

As funções de manipulação são bastante semelhantes às de lista simplesmente encadeada, com a diferença consistindo nos ponteiros, que, ao invés de apontarem para **NULL**, apontam para o primeiro elemento da lista. São elas:

- Inserção no início: o nó passa a ser o primeiro elemento da lista e seu ponteiro **prox** deve ser atualizado para apontar para o antigo primeiro elemento;
- Inserção no final: o nó passa a ser o último elemento da lista e seu ponteiro **prox** deve ser atualizado para apontar para o primeiro elemento;
- Remoção no início: o **primeiro elemento** é removido e seu ponteiro **prox** deve ser atualizado para apontar para o antigo segundo elemento;
- Remoção no final: o **último elemento** é removido e seu ponteiro **prox** deve ser atualizado para apontar para o penúltimo elemento;