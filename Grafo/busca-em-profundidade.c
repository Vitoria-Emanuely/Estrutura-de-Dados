#include <stdio.h>
#include <stdlib.h>

int tempo;

/* Lista de Adjac�ncia*/

typedef struct no{ //Estrutura para cada lista de v�rtices
	int vertice; //V�rtice guardado no n�
	int cor; //Cor guardada no n� (0 = Branco, 1 = Cinza, 2 = Preto)
	int d; //Primeiro carimbo de tempo (quando v�rtice � descoberto e � acinzentado)
	int f; //Segundo carimbo de tempo (quando a busca termina de examinar a lista de adjac�ncias e pinta o v�rtice de preto)
	int pi; //V�rtice predecessor (pai)
	struct no *prox; //Ponteiro para o pr�ximo elemento 
}tipo_no; //Tipo exportado

typedef struct grafo{ //Estrutura para o grafo
	int nVer; //N�mero total de v�rtices do grafo
	tipo_no *vetorLista; //Vetor da lista de adjac�ncia de acordo com o n�mero de v�rtices
}tipo_grafo; //Tipo exportado

tipo_grafo *criaGrafo(int n){ //Retorna ponteiro
	tipo_grafo *g = (tipo_grafo*) malloc(sizeof(tipo_grafo)); //Cria uma aloca��o din�mica para o novo elemento do tipo grafo
	int i; //Declara vari�vel i do tipo inteiro
	if (g){ //Caso o grafo seja criado
		g->nVer = n; //Atribui o ponteiro g que aponta para nVer o valor de n (valor total de v�rtices do grafo)
		g->vetorLista = (tipo_no*) malloc(n*sizeof(tipo_no)); //Cria uma aloca��o din�mica para o novo elemento 
		if (g->vetorLista){ //Caso o vetor seja alocado
			for (i = 0; i < n; i++) //Percorre o vetor
				g->vetorLista[i].prox = NULL; //Atribui ao ponteiro g que aponta para vetorLista na posi��o i de prox (prox de cada v�rtice) NULL
			return g; //Retorna o ponteiro
		}
		return NULL;
	}
	return NULL;
}

void mostraGrafo(tipo_grafo *g){
	int i; //Declara vari�vel i do tipo inteiro
	printf("\nGrafo - Lista de Adjacencia\n"); //Imprime na tela
	for (i = 0; i < g->nVer; i++){ //Percorre vetor
		tipo_no *p = g->vetorLista[i].prox; //Ponteiro p recebe o endere�o de prox do ponteiro g que aponta para vetorLista na posi��o i
		printf("\n%d -> ", i); //Imprime na tela
		while (p){ //Enquanto p for diferente de NULL
			printf("%d -> ", p->vertice); //Imprime na tela
			p = p->prox; //Ponteiro p recebe o pr�ximo endere�o (p que aponta para prox)
		}
		printf("NULL\n"); //Imprime na tela
	}
}

tipo_no *criaNo(int v){
	tipo_no *novoNo = (tipo_no*) malloc(sizeof(tipo_no)); //Cria uma aloca��o din�mica para o novo elemento do tipo n� de v�rtice
	novoNo->vertice = v; //Ponteiro novoNo que aponta para vertice recebe o valor de v
	//novoNo->cor = NULL;
	novoNo->prox = NULL; //Ponteiro novoNo que aponta para prox recebe NULL
	return novoNo; //Retorno o endere�o do n� criado
}

void addAresta(tipo_grafo *g, int origem, int destino){
	tipo_no *novoNo = criaNo(destino); //Cria uma aloca��o din�mica para o novo elemento do tipo n� de v�rtice
	novoNo->prox = g->vetorLista[origem].prox; //Ponteiro novoNo que aponta para prox recebe o conte�do prox do ponteiro g que aponta para vetorLista na posi��o origem
	g->vetorLista[origem].prox = novoNo; //Ponteiro g que aponta para vetorLista na posi��o origem em prox recebe o conte�do de novoNo
	novoNo = criaNo(origem); //Ponteiro novoNo recebe o retorno da fun��o criaNo passando a origem
	novoNo->prox = g->vetorLista[destino].prox; //Ponteiro novoNo que aponta para prox recebe o conte�do prox do ponteiro g que aponta para vetorLista na posi��o destino
	g->vetorLista[destino].prox = novoNo; //Ponteiro g que aponta para vetorLista na posi��o destino em prox recebe o conte�do de novoNo
}

void addArestaOri(tipo_grafo *g, int origem, int destino){
	tipo_no *novoNo = criaNo(destino); //Cria uma aloca��o din�mica para o novo elemento do tipo n� de v�rtice
	novoNo->prox = g->vetorLista[origem].prox; //Ponteiro novoNo que aponta para prox recebe o conte�do prox do ponteiro g que aponta para vetorLista na posi��o origem
	g->vetorLista[origem].prox = novoNo; //Ponteiro g que aponta para vetorLista na posi��o origem em prox recebe o conte�do de novoNo
}

tipo_grafo *destroiGrafo(tipo_grafo *g){
	int i; //Declara vari�vel i do tipo inteiro
	if (g){ //Caso o grafo exista
		if (g->vetorLista){ //Caso o vetor seja alocado
			for (i = 0; i < g->nVer; i++){ //Percorre o vetor
				tipo_no *p = g->vetorLista[i].prox; //Ponteiro p recebe o conte�do de prox do ponteiro g que aponta para vetorLista na posi��o i 
				while(p){ //Enquanto p n�o for NULL
					tipo_no *t = p; //Ponteiro auxiliar t recebe o conte�do de p
					p = p->prox; //Ponteiro p recebe o conte�do de p que aponta para prox
					free(t); //Libera a mem�ria apontada por t (atual), no caso, cada v�rtice
				}
			}
			free(g->vetorLista); //Libera o vetor
		}
		free(g); //Libera o grafo
	}
	return NULL; //Libera mem�ria
}

/* Fim Lista de Adjac�ncia */

/* Busca em Profundidade (DFS) */
/* Legenda: 
	- Branco = 0
	- Cinza = 1
	- Preto = 2 */
	
void buscaP_Visit(tipo_grafo *g, int i){
	g->vetorLista[i].cor = 1;
	tempo += 1;
	g->vetorLista[i].d = tempo;
	tipo_no *v;
	for (v = g->vetorLista[i].prox; v!= NULL; v = v->prox){
		if (g->vetorLista[v->vertice].cor == 0){
			g->vetorLista[v->vertice].pi = i;
			buscaP_Visit(g, v->vertice);
		}
	}
	g->vetorLista[i].cor = 2;
	tempo += 1;
	g->vetorLista[i].f = tempo;
}	

void buscaProfundidade(tipo_grafo *g){
	int i; //Declara a vari�vel i do tipo inteiro
	tipo_no *v; //Declara ponteiro v
	for (i = 0; i < g->nVer; i++){ //Percorre o vetor
		g->vetorLista[i].cor = 0; //Ponteiro g que aponta para vetorLista na posi��o i em cor recebe 0 (Branco)
		g->vetorLista[i].pi = -1;
	}
	tempo = 0;
	for (i = 0; i < g->nVer; i++){ //Percorre o vetor 
		if (g->vetorLista[i].cor == 0){ //Se ponteiro g que aponta para vetorLista na posi��o do ponteiro v que aponta para vertice em cor for igual a 0 (Branco)
			//g->vetorLista[i].pi = i;
			buscaP_Visit(g, i);
		}
	}	
}

void mostraBusca(tipo_grafo *g){
	int i; //Declara vari�vel i do tipo inteiro
	printf("============ Grafo ============\n"); //Imprime na tela
	for (i = 0; i < g->nVer; i++){ //Percorre o vetor
		printf("\tVertice: %d <==> Cor: %d\n", i, g->vetorLista[i].cor); //Imprime na tela
		printf("\tVertice: %d <==> d: %d\n", i, g->vetorLista[i].d); //Imprime na tela
		printf("\tVertice: %d <==> Pi: %d\n", i, g->vetorLista[i].pi); //Imprime na tela
		printf("\tVertice: %d <==> f: %d\n\n", i, g->vetorLista[i].f); //Imprime na tela
	}
	printf("================================\n"); //Imprime na tela
}

/* Fim Busca em Profundidade*/

/* Fun��o principal */
int main(void){
	tipo_grafo *g = criaGrafo(6);
	addArestaOri(g, 0, 3);
	addArestaOri(g, 0, 1);
	addArestaOri(g, 1, 2);
	addArestaOri(g, 2, 3);
	addArestaOri(g, 3, 1);
	addArestaOri(g, 4, 5);
	addArestaOri(g, 4, 2);	
	addArestaOri(g, 5, 5);

	if (g == NULL){ //Se o grafo estiver vazio
		return -1; //Encerra o programa
	}
	mostraGrafo(g);
	buscaProfundidade(g); //Fun��o que faz a busca em largura do grafo com origem x
	mostraBusca(g);
	g = destroiGrafo(g); //Destr�i o grafo liberando a mem�ria
	return 0; //Encerra o programa
}
