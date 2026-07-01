## Prova 2 - Estrutura de Dados

#### **1) Explique quais são as principais operações que devem ser implementadas em filas.**

Uma `fila (queue)` segue o princípio **FIFO (First in First out)**, isto é, o primeiro a entrar é o primeiro a sair, independentemente de ser implementada com lista ou vetor. As principais operações que devem ser implementadas para essa estrutura consistem em:

- **Criar/Inicializar**: aloca a estrutura da fia e a inicializa como vazia;
- **Inserir/enfileirar (enqueue)**: adiciona um elemento no **final** da lista;
- **Remover/desenfileirar (dequeue)**: remove o elemento e retorna o elemento do início da lista; 
- **Front/espiar (peek)**: retorna o elemento do início da fila sem removê-lo;
- **IsEmpty**: verifica se a fila não contém nenhum elemento, retornando verdadeiro ou falso;
- **Size/tamanho**: retorna o número de elementos da lista;

#### **2) Explique como é possível implementar uma fila utilizando lista encadeada simples**

Para que uma fila seja implementada com listas encadeadas, devem se utilizar **dois principais ponteiros**:

- head: aponta para o primeiro nó (cabeça da fila);
- tail: aponta para o último nó (cauda da fila);

As duas principais operações ocorrem da seguinte maneira:

- `Para a inserção (enqueue)`: sempre ocorre **no final da lista**. Como temos o ponteiro `fim`, não precisamos percorrer a lista inteira. Basta criar o novo nó, fazer com que o atual último elemento da lista, se não estiver vazia, aponte para ele (`fim->prox novo`) e, por fim, atualizar o ponteiro `fim`para apontar para esse novo nó;

- `Para a remoção (dequeue)`: sempre ocorre **no início da lista**. Basta fazer com que o ponteiro `inicio` avance para o sucessor do nó retirado (`inicio = inicio->prox`) e depois usar **free()** no nó removido. Caso a remoção deixe a lista vazia, é preciso atualizar ambos os ponteiros como null;