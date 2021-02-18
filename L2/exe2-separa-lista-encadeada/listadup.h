#include <stdio.h>
#include <stdlib.h>

/* TAD: ListaDup */
struct listaDup{
	int info; /* Informa��o guardada na lista */
	struct listaDup *ant;	/* Ponteiro para o elemento anterior da lista */
	struct listaDup *prox;	/* Ponteiro para o pr�ximo elemento da lista */

};

/* Tipo exportado */
typedef struct listaDup ListaDupla;

/* Fun��es exportadas */

//Fun��o inicializa: Cria uma lista vazia, sem nenhum elemento
ListaDupla* inicializa(void);

//Fun��o insere: Insere um novo elemento ordenado (n�) de acordo com a ordem crescente na lista
ListaDupla* insereOrd(ListaDupla *l, int i);

//Fun��o imprimePU: Imprime todos os valores dos elementos armazenados na lista do primeiro ao �ltimo
void imprime(ListaDupla *l);

//Fun��o vazia: Verifica se a lista est� vazia ou n�o
int vazia(ListaDupla *l);

//Fun��o busca: Verifica se o elemento requisitado est� presente na lista
ListaDupla* busca(ListaDupla *l, int v);

//Fun��o libera: Libera os elementos alocados um por um, destruindo a lista
void libera(ListaDupla *l);

//Fun��o separa: Separa a lista em duas listas
ListaDupla* separa(ListaDupla *l, int n);
