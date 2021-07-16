#include <stdio.h>
#include <stdlib.h>

typedef struct no{ //Estrutura para cada lista de vértices
	int vertice;
	struct no *prox;
}tipo_no;

typedef struct grafo{
	int nVer;
	tipo_no *vetorLista; //Vetor da lista de adjacência de acordo com o número de vértices
}tipo_grafo;

tipo_grafo *criaGrafo(int n){ //Retorna ponteiro
	tipo_grafo *g = (tipo_grafo*) malloc(sizeof(tipo_grafo));
	int i;
	if (g){ //Caso o grafo seja criado
		g->nVer = n;
		g->vetorLista = (tipo_no*) malloc(n*sizeof(tipo_no));
		if (g->vetorLista){ //Caso o vetor seja alocado
			for (i = 0; i < n; i++)
				g->vetorLista[i].prox = NULL;
			return g;
		}
		return NULL;
	}
	return NULL;
}

void mostraGrafo(tipo_grafo *g){
	int i;
	printf("\nGrafo - Lista de Adjacencia\n");
	for (i = 0; i < g->nVer; i++){
		tipo_no *p = g->vetorLista[i].prox;
		printf("\n%d -> ", i);
		while (p){ //Enquanto p for diferente de NULL
			printf("%d -> ", p->vertice);
			p = p->prox;
		}
		printf("NULL\n");
	}
}

tipo_no *criaNo(int v){
	tipo_no *novoNo = (tipo_no*) malloc(sizeof(tipo_no));
	novoNo->vertice = v;
	novoNo->prox = NULL;
	
	return novoNo;
}

void addAresta(tipo_grafo *g, int origem, int destino){
	tipo_no *novoNo = criaNo(destino);
	novoNo->prox = g->vetorLista[origem].prox;
	g->vetorLista[origem].prox = novoNo;
	
	novoNo = criaNo(origem);
	novoNo->prox = g->vetorLista[destino].prox;
	g->vetorLista[destino].prox = novoNo;
}

tipo_grafo *destroiGrafo(tipo_grafo *g){
	int i;
	if (g){
		if (g->vetorLista){
			for (i = 0; i < g->nVer; i++){
				tipo_no *p = g->vetorLista[i].prox;
				while(p){
					tipo_no *t = p;
					p = p->prox;
					free(t);
				}
			}
			free(g->vetorLista);
		}
		free(g);
	}
	return NULL;
}


int main(void){
	tipo_grafo *g = criaGrafo(5);
	if (g == NULL)
		return -1;
	addAresta(g, 1, 2);
	addAresta(g, 1, 3);
	addAresta(g, 1, 0);
	mostraGrafo(g);
	g = destroiGrafo(g);
	return 0;
}
