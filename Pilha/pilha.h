#include <stdio.h>
#include <stdlib.h>

/* Tipo exportado */
typedef struct pilha Pilha;

/* Fun��es exportadas */

//Fun��o inicializa: Cria uma lista vazia, sem nenhum elemento, inicializando a pilha
Pilha* inicializa(void);

//Fun��o push: Insere um novo elemento (n�) no in�cio
Pilha* push(Pilha *p, int v);

//Fun��o imprime: Imprime todos os valores dos elementos armazenados na lista
void imprime(Pilha *p);

//Fun��o vazia: A pilha estar� vazia se a lista estiver vazia
int vazia(Pilha *p);

//Fun��o pop: Remove o elemento do in�cio
int pop(Pilha **p);

//Fun��o libera: Libera todos os elementos da lista, liberando a pilha
void libera(Pilha *p);
