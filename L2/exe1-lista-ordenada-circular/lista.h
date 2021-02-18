#include <stdio.h>
#include <stdlib.h>

/* TAD: Lista */
struct lista{
	int info; /* Informação guardada na lista */
	struct lista *prox;	/* Ponteiro para o próximo elemento da lista */
};

/* Tipo exportado */
typedef struct lista Lista;

/* Funções exportadas */

//Função inicializa: Cria uma lista vazia, sem nenhum elemento
Lista* inicializa(void);

//Função insereInicio: Insere um novo elemento (nó) no início da lista
Lista* insereInicio (Lista *l, int i);

//Função imprime: Imprime todos os valores dos elementos armazenados na lista
void imprime(Lista *l);

//Função vazia: Verifica se a lista está vazia ou não
int vazia(Lista *l);

//Função busca: Verifica se o elemento requisitado está presente na lista
Lista* busca(Lista *l, int v);

//Função elimina: Remove o elemento requisitado da lista
Lista* elimina(Lista *l, int v);

//Função libera: Libera os elementos alocados um por um, destruindo a lista
void libera(Lista *l);
