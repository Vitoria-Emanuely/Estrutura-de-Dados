#include <stdio.h>
#include <stdlib.h>

/* TAD: Arv */
struct arv{
	int info; /* Informa��o guardada no n�*/
	struct arv *esq; /* Ponteiro para o n� da sub-�rvore da esquerda */
	struct arv *dir; /* Ponteiro para o n� da sub-�rvore da direita */
};

/* Tipo exportado */
typedef struct arv Arv;

/* Fun��es exportadas */

//Fun��o inicializa: Cria uma �vore vazia, sem nenhum elemento
Arv* inicializa(void);

//Fun��o insere: Insere um elemento na �rvore
Arv* insere(Arv *a, int v);

//Fun��o imprime: Imprime todos os valores dos elementos armazenados na �rvore, in-ordem
void imprime(Arv *a);

//Fun��o busca: Busca o elemento requisitado na �rvore
Arv* busca(Arv *r, int v);

//Fun��o retira: Retira o elemento requisitado da �rvore
Arv* retira(Arv *r, int v);

//Fun��o libera: Libera os elementos alocados n� por n�, destruindo a �rvore
Arv* libera(Arv *a);

//Fun��o contaNos: Conta o n�mero de n�s da �rvore
int contaNos(Arv *r);

//Fun��o calculaAlt: Calcula a altura da �rvore
int calculaAlt(Arv *r);

//Fun��o contaFolhas: Conta o n�mero de folhas da �rvore
int contaFolhas(Arv *r);

//Fun��o contaMaior: Encontra o maior elemento da �rvore
int contaMaior(Arv *r);

//Fun��o igual: Verifica se duas �rvores bin�rios de busca s�o iguais
int igual(Arv *r, Arv *s);
