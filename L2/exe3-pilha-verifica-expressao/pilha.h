#include <stdio.h>
#include <stdlib.h>

/* Tipo exportado */
typedef struct pilha Pilha;

/* Fun��es exportadas */

//Fun��o inicializa: Cria uma lista vazia, sem nenhum elemento, inicializando a pilha
Pilha* inicializa(void);

//Fun��o push: Insere um novo elemento (n�) no in�cio
Pilha* push(Pilha *p, char v);

//Fun��o imprime: Imprime todos os valores dos elementos armazenados na lista
void imprime(Pilha *p);

//Fun��o vazia: A pilha estar� vazia se a lista estiver vazia
int vazia(Pilha *p);

//Fun��o pop: Remove o elemento do in�cio
void pop(Pilha **p);

//Fun��o libera: Libera todos os elementos da lista, liberando a pilha
void libera(Pilha *p);

//Fun��o verifica: Verifica se os par�nteses est�o corretos
void verifica(char v[]);
