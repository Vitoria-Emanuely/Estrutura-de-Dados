#include <stdio.h>
#include <stdlib.h>

/* TAD: ListaDup */
struct listaDup{
	int info; /* Informação guardada na lista */
	struct listaDup *ant;	/* Ponteiro para o elemento anterior da lista */
	struct listaDup *prox;	/* Ponteiro para o próximo elemento da lista */

};

/* Tipo exportado */
typedef struct listaDup ListaDupla;

/* Funções exportadas */

//Função inicializa: Cria uma lista vazia, sem nenhum elemento
ListaDupla* inicializa(void);

//Função insere: Insere um novo elemento ordenado (nó) de acordo com a ordem crescente na lista
ListaDupla* insereOrd(ListaDupla *l, int i);

//Função imprimePU: Imprime todos os valores dos elementos armazenados na lista do primeiro ao último
void imprime(ListaDupla *l);

//Função vazia: Verifica se a lista está vazia ou não
int vazia(ListaDupla *l);

//Função busca: Verifica se o elemento requisitado está presente na lista
ListaDupla* busca(ListaDupla *l, int v);

//Função libera: Libera os elementos alocados um por um, destruindo a lista
void libera(ListaDupla *l);

//Função separa: Separa a lista em duas listas
ListaDupla* separa(ListaDupla *l, int n);
