#include <stdio.h>
#include <stdlib.h>

/* TAD: Arv */
struct arv{
	char info; /* Informação guardada no nó*/
	struct arv *esq; /* Ponteiro para o nó da sub-árvore da esquerda */
	struct arv *dir; /* Ponteiro para o nó da sub-árvore da direita */
};

/* Tipo exportado */
typedef struct arv Arv;

/* Funções exportadas */

//Função inicializa: Cria uma ávore vazia, sem nenhum elemento
Arv* inicializa(void);

//Função cria: Cria um nó raiz dada a informação e suas duas sub-árvores, esquerda e direita
Arv* cria(char c, Arv *sae, Arv *sad);

//Função vazia: Verifica se a árvore está vazia ou não
int vazia(Arv *a);

//Função imprimePreOrdem: Imprime todos os valores dos elementos armazenados na árvore
void imprimePreOrdem(Arv *a);

//Função imprimePosOrdem: Imprime todos os valores dos elementos armazenados na árvore
void imprimePosOrdem(Arv *a);

//Função imprimeInOrdem: Imprime todos os valores dos elementos armazenados na árvore
void imprimeInOrdem(Arv *a);

//Função libera: Libera os elementos alocados nó por nó, destruindo a árvore
Arv* libera(Arv *a);

//Função busca: Verifica se o elemento requisitado está presente na árvore
int busca(Arv *a, char c);
	
	
