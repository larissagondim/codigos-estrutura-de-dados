## Filas

Filas são estruturas de dados do tipo `lista` (_ou seja, um subconjunto de listas_) com restrições rigorosas de acesso aos elementos da seguinte forma:

- O primeiro elemento inserido é o primeiro a ser removido;
- Apenas o elemento da frente (início) pode ser acessado diretamente;
- Novos elementos são sempre inseridos no final (traseira);

Essas restrições se referem ao tipo de acesso da fila, que segue o modelo `FIFO (First in, first out)`, que é, basicamente, primeiro a entrar, primeiro a sair.

Uma analogia para que haja um melhor entendimento do conceito de fila é pensar numa fila de banco ou de supermercado. Caso você queira entrar na fila, deve-se posicionar, obrigatoriamente, no final da fila; da mesma forma, quando é sua vez de ser atendido, a pessoa que está há mais tempo na fila (a da frente) é a primeira a sair.

Não é possível buscar um elemento do meio da fila sem antes **desenfileirar**, isto é, remover os elementos localizados na frente até encontrar o desejado.

Em suma, a fila tem as seguintes características que tornam possível sua identificação:

- É linear;
- É ordenada (por ordem de chegada);
- Não pode consultar elementos do meio diretamente;
- Só vemos o início (frente) e o final (traseira);
- Inserimos no final e retiramos do início;
- O tamanho só é conhecido totalmente se percorrermos a estrutura;

Quando temos **frente** e **traseira**, podemos dizer que a E.D. se trata de uma **fila**, ou seja, uma estrutura com dois ponteiros de controle (início e fim).

### Implementação em C

A estrutura de uma fila pode ser implementada de duas formas principais: com vetor (estática) ou com lista encadeada (dinâmica). Em C, podemos escrever da seguinte maneira:

#### Implementação com vetor (estática)

```c
#define MAX 100

struct fila {
    int v[MAX];
    int inicio;
    int fim;
    int tamanho;  // opcional: conta quantos elementos há na fila
};
typedef struct fila Fila;
```

#### Implementação com lista encadeada (dinâmica)

```c
typedef struct Node {
    int dado;
    struct Node *prox;
} Node;

struct fila {
    Node *inicio;
    Node *fim;
    int tamanho;  // opcional
};
typedef struct fila Fila;
```

### Operações de fila

- **Enqueue (enfileirar)**: operação que insere um novo elemento no final (traseira) da fila;
- **Dequeue (desenfileirar)**: operação que retira e retorna o elemento localizado no início (frente) da fila;
- **Ver frente**: permite ver qual é o elemento do início sem necessariamente retirá-lo da fila;
- **Ver se está vazia**: retorna verdadeiro caso a fila não possua nenhum elemento;
- **Liberar**: limpa a estrutura, removendo todos os elementos da memória;

É mais eficiente realizar as operações de inserção no final e remoção no início quando usamos uma **lista encadeada com ponteiro para o fim**, pois, ao realizar as operações no início ou fim diretamente (graças aos ponteiros `inicio` e `fim`), evitamos percorrer a estrutura de dados, realizando operações em **O(1)** em vez de **O(n)**.

### Comparação: Pilha vs Fila

| Característica | Pilha (Stack) | Fila (Queue) |
|----------------|---------------|---------------|
| **Modelo de acesso** | LIFO (Last In, First Out) | FIFO (First In, First Out) |
| **Inserção** | No topo | No final (traseira) |
| **Remoção** | Do topo | Do início (frente) |
| **Ponteiros de controle** | `topo` (e base implícita) | `inicio` e `fim` |
| **Analogia** | Pilha de pratos | Fila de banco |

### Exemplo completo em C (fila com lista encadeada)

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dado;
    struct Node *prox;
} Node;

typedef struct {
    Node *inicio;
    Node *fim;
    int tamanho;
} Fila;

void inicializar(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

void enqueue(Fila *f, int valor) {
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->dado = valor;
    novo->prox = NULL;
    
    if (f->fim == NULL) {
        // Fila vazia: inicio e fim apontam para o novo
        f->inicio = novo;
        f->fim = novo;
    } else {
        // Fila não vazia: insere no fim
        f->fim->prox = novo;
        f->fim = novo;
    }
    f->tamanho++;
}

int dequeue(Fila *f) {
    if (f->inicio == NULL) {
        printf("Fila vazia!\n");
        return -1;
    }
    
    Node *removido = f->inicio;
    int valor = removido->dado;
    f->inicio = removido->prox;
    
    if (f->inicio == NULL) {
        f->fim = NULL;  // fila ficou vazia
    }
    
    free(removido);
    f->tamanho--;
    return valor;
}

int frente(Fila *f) {
    if (f->inicio == NULL) {
        printf("Fila vazia!\n");
        return -1;
    }
    return f->inicio->dado;
}

int vazia(Fila *f) {
    return f->inicio == NULL;
}

void liberar(Fila *f) {
    while (!vazia(f)) {
        dequeue(f);
    }
}

int main() {
    Fila f;
    inicializar(&f);
    
    enqueue(&f, 10);
    enqueue(&f, 20);
    enqueue(&f, 30);
    
    printf("Frente: %d\n", frente(&f));     // 10
    printf("Desenfileirar: %d\n", dequeue(&f));  // 10
    printf("Frente: %d\n", frente(&f));     // 20
    printf("Tamanho: %d\n", f.tamanho);     // 2
    
    liberar(&f);
    
    return 0;
}
```

### Cuidados importantes

| Cuidado | Explicação |
|---------|------------|
| **Fila vazia** | Sempre verifique se `inicio == NULL` antes de acessar `dequeue()` ou `frente()` |
| **Vetor circular** | Em implementações com vetor, use lógica circular para aproveitar espaços vazios |
| **Atualizar `fim`** | Após `dequeue()`, se a fila ficar vazia, `fim` também deve ser `NULL` |
| **Vazamento de memória** | Na implementação com lista, sempre libere os nós removidos |

### Fila circular com vetor (otimização)

Para evitar o desperdício de espaço em implementações com vetor, usa-se uma **fila circular**:

```c
#define MAX 5

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} FilaCircular;

void enqueueCircular(FilaCircular *f, int valor) {
    if (f->tamanho == MAX) {
        printf("Fila cheia!\n");
        return;
    }
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;  // movimento circular
    f->tamanho++;
}

int dequeueCircular(FilaCircular *f) {
    if (f->tamanho == 0) {
        printf("Fila vazia!\n");
        return -1;
    }
    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;  // movimento circular
    f->tamanho--;
    return valor;
}
```

Em resumo, **filas** são estruturas ideais para situações onde a ordem de chegada deve ser respeitada, como sistemas de atendimento, buffers de dados em streaming, impressão de documentos em rede e escalonamento de processos em sistemas operacionais.