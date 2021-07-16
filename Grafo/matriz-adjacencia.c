#include <stdio.h>
#include <stdlib.h>

typedef struct grafo{
	int numV; //Número de vértices
	int **matriz_adj; //Matriz de forma dinâmica (para não ter problema com tamanho). É um vetor de endereço de vetores
	
}tipo_grafo;

tipo_grafo* criaGrafo(int nVer){
	int i, j;
	tipo_grafo *G = malloc(sizeof(tipo_grafo)); //Aloca dinamicamente
	G->numV = nVer; //Passa para numV o número de vértices
	G->matriz_adj = (int **) malloc(nVer*sizeof(int *)); //Aloca um vetor de endereços
	
	for (i = 0; i < nVer; i++)
		G->matriz_adj[i] = (int *) malloc(nVer*sizeof(int));
	
	for (i = 0; i < nVer; i++){
		for (j = 0; j < nVer; j++)
			G->matriz_adj[i][j] = 0;
	}
	return G; 
}

void mostraGrafo(tipo_grafo *G){
	int i, j;
	printf("\n Matriz de Adjacencia do grafo\n\n   ");
	for (i = 0; i < G->numV; i++)
		printf("%d ", i);
	printf("\n\n");
	
	for (i = 0; i < G->numV; i++){
		printf("%d ", i);	
		for (j = 0; j < G->numV; j++)
			printf(" %d", G->matriz_adj[i][j]);
	printf("\n");
	}
}

void addAresta(tipo_grafo *G, int origem, int destino, int peso){
	G->matriz_adj[origem][destino] = peso;
	G->matriz_adj[destino][origem] = peso;
}

void removeAresta(tipo_grafo *G, int origem, int destino){
	G->matriz_adj[origem][destino] = 0;
	G->matriz_adj[destino][origem] = 0;
}

tipo_grafo* liberaGrafo(tipo_grafo *G){
	if (G){ //Verifica se G existe
		int i;
		for (i = 0; i < G->numV; i++) //Percorre todas as estruturas
			free(G->matriz_adj[i]); //Libera uma por uma
		free(G->matriz_adj); //Libera a matriz de vetores
		free(G); //Libera o grafo
	}
	return NULL; //Liberar G para ser reutilizado
}

int main(){
	tipo_grafo *G = criaGrafo(4); //Cria o grafo
	addAresta(G, 1, 2, 1);
	addAresta(G, 3, 1, 1);
	removeAresta(G, 2, 1);
	mostraGrafo(G);
	G = liberaGrafo(G);
	return 0;
}
