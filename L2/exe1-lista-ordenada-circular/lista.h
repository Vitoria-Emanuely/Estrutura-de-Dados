#include <stdio.h>
#include <stdlib.h>

/* TAD: Lista */
struct lista{
	int info; /* Informa��o guardada na lista */
	struct lista *prox;	/* Ponteiro para o pr�ximo elemento da lista */
};

/* Tipo exportado */
typedef struct lista Lista;

/* Fun��es exportadas */

//Fun��o inicializa: Cria uma lista vazia, sem nenhum elemento
Lista* inicializa(void);

//Fun��o insereInicio: Insere um novo elemento (n�) no in�cio da lista
Lista* insereInicio (Lista *l, int i);

//Fun��o imprime: Imprime todos os valores dos elementos armazenados na lista
void imprime(Lista *l);

//Fun��o vazia: Verifica se a lista est� vazia ou n�o
int vazia(Lista *l);

//Fun��o busca: Verifica se o elemento requisitado est� presente na lista
Lista* busca(Lista *l, int v);

//Fun��o elimina: Remove o elemento requisitado da lista
Lista* elimina(Lista *l, int v);

//Fun��o libera: Libera os elementos alocados um por um, destruindo a lista
void libera(Lista *l);
