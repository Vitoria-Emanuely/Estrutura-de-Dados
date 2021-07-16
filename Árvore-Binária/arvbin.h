#include <stdio.h>
#include <stdlib.h>

/* TAD: Arv */
struct arv{
	char info; /* Informa��o guardada no n�*/
	struct arv *esq; /* Ponteiro para o n� da sub-�rvore da esquerda */
	struct arv *dir; /* Ponteiro para o n� da sub-�rvore da direita */
};

/* Tipo exportado */
typedef struct arv Arv;

/* Fun��es exportadas */

//Fun��o inicializa: Cria uma �vore vazia, sem nenhum elemento
Arv* inicializa(void);

//Fun��o cria: Cria um n� raiz dada a informa��o e suas duas sub-�rvores, esquerda e direita
Arv* cria(char c, Arv *sae, Arv *sad);

//Fun��o vazia: Verifica se a �rvore est� vazia ou n�o
int vazia(Arv *a);

//Fun��o imprimePreOrdem: Imprime todos os valores dos elementos armazenados na �rvore
void imprimePreOrdem(Arv *a);

//Fun��o imprimePosOrdem: Imprime todos os valores dos elementos armazenados na �rvore
void imprimePosOrdem(Arv *a);

//Fun��o imprimeInOrdem: Imprime todos os valores dos elementos armazenados na �rvore
void imprimeInOrdem(Arv *a);

//Fun��o libera: Libera os elementos alocados n� por n�, destruindo a �rvore
Arv* libera(Arv *a);

//Fun��o busca: Verifica se o elemento requisitado est� presente na �rvore
int busca(Arv *a, char c);
	
	
