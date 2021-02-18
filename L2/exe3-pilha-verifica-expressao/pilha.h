#include <stdio.h>
#include <stdlib.h>

/* Tipo exportado */
typedef struct pilha Pilha;

/* Funções exportadas */

//Função inicializa: Cria uma lista vazia, sem nenhum elemento, inicializando a pilha
Pilha* inicializa(void);

//Função push: Insere um novo elemento (nó) no início
Pilha* push(Pilha *p, char v);

//Função imprime: Imprime todos os valores dos elementos armazenados na lista
void imprime(Pilha *p);

//Função vazia: A pilha estará vazia se a lista estiver vazia
int vazia(Pilha *p);

//Função pop: Remove o elemento do início
void pop(Pilha **p);

//Função libera: Libera todos os elementos da lista, liberando a pilha
void libera(Pilha *p);

//Função verifica: Verifica se os parênteses estão corretos
void verifica(char v[]);
