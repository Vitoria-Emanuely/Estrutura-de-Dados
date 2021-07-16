#include <stdio.h>
#include <stdlib.h>

/* TAD: Arv */
struct arv{
	int info; /* Informação guardada no nó*/
	struct arv *esq; /* Ponteiro para o nó da sub-árvore da esquerda */
	struct arv *dir; /* Ponteiro para o nó da sub-árvore da direita */
};

/* Tipo exportado */
typedef struct arv Arv;

/* Funções exportadas */

//Função inicializa: Cria uma ávore vazia, sem nenhum elemento
Arv* inicializa(void);

//Função insere: Insere um elemento na árvore
Arv* insere(Arv *a, int v);

//Função imprime: Imprime todos os valores dos elementos armazenados na árvore, in-ordem
void imprime(Arv *a);

//Função busca: Busca o elemento requisitado na árvore
Arv* busca(Arv *r, int v);

//Função retira: Retira o elemento requisitado da árvore
Arv* retira(Arv *r, int v);

//Função libera: Libera os elementos alocados nó por nó, destruindo a árvore
Arv* libera(Arv *a);

//Função contaNos: Conta o número de nós da árvore
int contaNos(Arv *r);

//Função calculaAlt: Calcula a altura da árvore
int calculaAlt(Arv *r);

//Função contaFolhas: Conta o número de folhas da árvore
int contaFolhas(Arv *r);

//Função contaMaior: Encontra o maior elemento da árvore
int contaMaior(Arv *r);

//Função igual: Verifica se duas árvores binários de busca são iguais
int igual(Arv *r, Arv *s);
