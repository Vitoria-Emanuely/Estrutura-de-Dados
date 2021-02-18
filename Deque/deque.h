#include <stdio.h>
#include <stdlib.h>

/* TAD: Nó */
struct no{
	int info; /* Informação guardada no Nó */
	struct no *ant;	/* Ponteiro para o elemento anterior da lista */
	struct no *prox; /* Ponteiro para o próximo elemento da lista */
};

/* Tipo exportado */
typedef struct no No;

/* TAD: Deque */
struct deque{ /* Informação guardada no Deque */
	No *ini; /* Ponteiro para o primeiro elemento da lista */
	No *fim; /* Ponteiro para o último elemento da lista */
};

/* Tipo exportado */
typedef struct deque Deque;

/* Funções exportadas */

//Função cria: Cria uma lista vazia, sem nenhum elemento
Deque* cria(void);

//Função insereIni: Insere um novo elemento no início da lista
Deque* insereIni(Deque *d, int v);

//Função insereFim: Insere um novo elemento no final da lista
Deque* insereFim(Deque *d, int v);

//Função imprime: Imprime todos os valores dos elementos armazenados na lista
void imprime(Deque *d);

//Função vazia: Verifica se a lista está vazia ou não
int vazia(Deque *d);

//Função eliminaIni: Remove o primeiro elemento da lista
int eliminaIni(Deque *d);

//Função eliminaFim: Remove o último elemento da lista
int eliminaFim(Deque *d);

//Função libera: Libera os elementos alocados um por um, destruindo a lista
void libera(Deque *d);
