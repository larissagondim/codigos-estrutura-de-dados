## Listas heterogêneas

As estruturas heterogêneas são um recurso do C que permite armazenar diferentes tipos de dados em uma única estrutura, o que é importante para conseguir tratar um grupo de diferentes valores como uma única variável. Elas seguem o seguinte formato:

```c
struct <identificador> {
    <tipo_dado> <identificador>;
} <variável>;
```

Um exemplo prático é a função `scanf`: ela lê diferentes tipos (int, float, char) usando especificadores de formato (%d, %f, %c). De forma análoga, para armazenar dados de tipos distintos em uma lista encadeada, cada nó deve conter um identificador de tipo e um ponteiro genérico (_void *_). O ponteiro aponta para uma região de memória alocada dinamicamente (ex.: `malloc(sizeof(int))`), onde o dado real está guardado.

### Estrutura interna

Para que essa E.D. funcione de maneira segura, seu nó deve ser composto, estritamente, por 3 campos:
- Um identificador de tipo para indicar explicitamente que tipo de informação aquele nó armazena;
- Um ponteiro genérico (_void *_) que aponta para o endereço de memória no qual o dado está alocado;
- Um ponteiro para o próximo elemento da lista para manter o encadeamento;

### Manipulação das informações

É da responsabilidade do programador informar o tipo guardado por trás do ponteiro genérico, isto é, fazer a verificação e a conversão (_casting_) correta. Em termos de implementação, seria interessante utilizar um `switch-case` focando no identificador do tipo. Como por exemplo: se o identificador disser que é um inteiro, o `void *` deve ser convertido para `int *` para que consiga realizar acesso aos campos.

### Implementação em C

Para implementar uma lista heterogênea, a estrutura do nó deve ser a seguinte. O programador pode utilizar o que melhor se adequar a sua realidade, ou seja, definir o identificador de tipo como um `#define` ou como uma variável inteira. Aqui vai um exemplo:

```c
/*
#define INT_TIPO 1
#define FLOAT_TIPO 2
#define CHAR_TIPO 3
*/

typedef struct node_heterogeneo {
  unsigned char identificador_tipo;
  void *dado;
  struct node_heterogeneo *prox;
} NodeHeterogeneo;
```

Onde:

* `identificador_tipo`: é um inteiro que indica o tipo de dado armazenado no nó;
* `dado`: é um ponteiro genérico que aponta para o endereço de memória no qual o dado está alocado;
* `prox`: é um ponteiro para o próximo elemento da lista.