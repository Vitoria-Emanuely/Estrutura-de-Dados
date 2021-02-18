#include <stdio.h>
#include <stdlib.h>

/* TAD: N� */
struct no{
	int info; /* Informa��o guardada no N� */
	struct no *ant;	/* Ponteiro para o elemento anterior da lista */
	struct no *prox; /* Ponteiro para o pr�ximo elemento da lista */
};

/* Tipo exportado */
typedef struct no No;

/* TAD: Deque */
struct deque{ /* Informa��o guardada no Deque */
	No *ini; /* Ponteiro para o primeiro elemento da lista */
	No *fim; /* Ponteiro para o �ltimo elemento da lista */
};

/* Tipo exportado */
typedef struct deque Deque;

/* Fun��es exportadas */

//Fun��o cria: Cria uma lista vazia, sem nenhum elemento
Deque* cria(void);

//Fun��o insereIni: Insere um novo elemento no in�cio da lista
Deque* insereIni(Deque *d, int v);

//Fun��o insereFim: Insere um novo elemento no final da lista
Deque* insereFim(Deque *d, int v);

//Fun��o imprime: Imprime todos os valores dos elementos armazenados na lista
void imprime(Deque *d);

//Fun��o vazia: Verifica se a lista est� vazia ou n�o
int vazia(Deque *d);

//Fun��o eliminaIni: Remove o primeiro elemento da lista
int eliminaIni(Deque *d);

//Fun��o eliminaFim: Remove o �ltimo elemento da lista
int eliminaFim(Deque *d);

//Fun��o libera: Libera os elementos alocados um por um, destruindo a lista
void libera(Deque *d);
