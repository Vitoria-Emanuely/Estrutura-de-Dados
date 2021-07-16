#include <stdio.h>
#include <stdlib.h>

int tempo;

/* Lista de Adjacência*/

typedef struct no{ //Estrutura para cada lista de vértices
	int vertice; //Vértice guardado no nó
	int cor; //Cor guardada no nó (0 = Branco, 1 = Cinza, 2 = Preto)
	int d; //Primeiro carimbo de tempo (quando vértice é descoberto e é acinzentado)
	int f; //Segundo carimbo de tempo (quando a busca termina de examinar a lista de adjacências e pinta o vértice de preto)
	int pi; //Vértice predecessor (pai)
	struct no *prox; //Ponteiro para o próximo elemento 
}tipo_no; //Tipo exportado

typedef struct grafo{ //Estrutura para o grafo
	int nVer; //Número total de vértices do grafo
	tipo_no *vetorLista; //Vetor da lista de adjacência de acordo com o número de vértices
}tipo_grafo; //Tipo exportado

tipo_grafo *criaGrafo(int n){ //Retorna ponteiro
	tipo_grafo *g = (tipo_grafo*) malloc(sizeof(tipo_grafo)); //Cria uma alocação dinâmica para o novo elemento do tipo grafo
	int i; //Declara variável i do tipo inteiro
	if (g){ //Caso o grafo seja criado
		g->nVer = n; //Atribui o ponteiro g que aponta para nVer o valor de n (valor total de vértices do grafo)
		g->vetorLista = (tipo_no*) malloc(n*sizeof(tipo_no)); //Cria uma alocação dinâmica para o novo elemento 
		if (g->vetorLista){ //Caso o vetor seja alocado
			for (i = 0; i < n; i++) //Percorre o vetor
				g->vetorLista[i].prox = NULL; //Atribui ao ponteiro g que aponta para vetorLista na posição i de prox (prox de cada vértice) NULL
			return g; //Retorna o ponteiro
		}
		return NULL;
	}
	return NULL;
}

void mostraGrafo(tipo_grafo *g){
	int i; //Declara variável i do tipo inteiro
	printf("\nGrafo - Lista de Adjacencia\n"); //Imprime na tela
	for (i = 0; i < g->nVer; i++){ //Percorre vetor
		tipo_no *p = g->vetorLista[i].prox; //Ponteiro p recebe o endereço de prox do ponteiro g que aponta para vetorLista na posição i
		printf("\n%d -> ", i); //Imprime na tela
		while (p){ //Enquanto p for diferente de NULL
			printf("%d -> ", p->vertice); //Imprime na tela
			p = p->prox; //Ponteiro p recebe o próximo endereço (p que aponta para prox)
		}
		printf("NULL\n"); //Imprime na tela
	}
}

tipo_no *criaNo(int v){
	tipo_no *novoNo = (tipo_no*) malloc(sizeof(tipo_no)); //Cria uma alocação dinâmica para o novo elemento do tipo nó de vértice
	novoNo->vertice = v; //Ponteiro novoNo que aponta para vertice recebe o valor de v
	//novoNo->cor = NULL;
	novoNo->prox = NULL; //Ponteiro novoNo que aponta para prox recebe NULL
	return novoNo; //Retorno o endereço do nó criado
}

void addAresta(tipo_grafo *g, int origem, int destino){
	tipo_no *novoNo = criaNo(destino); //Cria uma alocação dinâmica para o novo elemento do tipo nó de vértice
	novoNo->prox = g->vetorLista[origem].prox; //Ponteiro novoNo que aponta para prox recebe o conteúdo prox do ponteiro g que aponta para vetorLista na posição origem
	g->vetorLista[origem].prox = novoNo; //Ponteiro g que aponta para vetorLista na posição origem em prox recebe o conteúdo de novoNo
	novoNo = criaNo(origem); //Ponteiro novoNo recebe o retorno da função criaNo passando a origem
	novoNo->prox = g->vetorLista[destino].prox; //Ponteiro novoNo que aponta para prox recebe o conteúdo prox do ponteiro g que aponta para vetorLista na posição destino
	g->vetorLista[destino].prox = novoNo; //Ponteiro g que aponta para vetorLista na posição destino em prox recebe o conteúdo de novoNo
}

void addArestaOri(tipo_grafo *g, int origem, int destino){
	tipo_no *novoNo = criaNo(destino); //Cria uma alocação dinâmica para o novo elemento do tipo nó de vértice
	novoNo->prox = g->vetorLista[origem].prox; //Ponteiro novoNo que aponta para prox recebe o conteúdo prox do ponteiro g que aponta para vetorLista na posição origem
	g->vetorLista[origem].prox = novoNo; //Ponteiro g que aponta para vetorLista na posição origem em prox recebe o conteúdo de novoNo
}

tipo_grafo *destroiGrafo(tipo_grafo *g){
	int i; //Declara variável i do tipo inteiro
	if (g){ //Caso o grafo exista
		if (g->vetorLista){ //Caso o vetor seja alocado
			for (i = 0; i < g->nVer; i++){ //Percorre o vetor
				tipo_no *p = g->vetorLista[i].prox; //Ponteiro p recebe o conteúdo de prox do ponteiro g que aponta para vetorLista na posição i 
				while(p){ //Enquanto p não for NULL
					tipo_no *t = p; //Ponteiro auxiliar t recebe o conteúdo de p
					p = p->prox; //Ponteiro p recebe o conteúdo de p que aponta para prox
					free(t); //Libera a memória apontada por t (atual), no caso, cada vértice
				}
			}
			free(g->vetorLista); //Libera o vetor
		}
		free(g); //Libera o grafo
	}
	return NULL; //Libera memória
}

/* Fim Lista de Adjacência */

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
	int i; //Declara a variável i do tipo inteiro
	tipo_no *v; //Declara ponteiro v
	for (i = 0; i < g->nVer; i++){ //Percorre o vetor
		g->vetorLista[i].cor = 0; //Ponteiro g que aponta para vetorLista na posição i em cor recebe 0 (Branco)
		g->vetorLista[i].pi = -1;
	}
	tempo = 0;
	for (i = 0; i < g->nVer; i++){ //Percorre o vetor 
		if (g->vetorLista[i].cor == 0){ //Se ponteiro g que aponta para vetorLista na posição do ponteiro v que aponta para vertice em cor for igual a 0 (Branco)
			//g->vetorLista[i].pi = i;
			buscaP_Visit(g, i);
		}
	}	
}

void mostraBusca(tipo_grafo *g){
	int i; //Declara variável i do tipo inteiro
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

/* Função principal */
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
	buscaProfundidade(g); //Função que faz a busca em largura do grafo com origem x
	mostraBusca(g);
	g = destroiGrafo(g); //Destrói o grafo liberando a memória
	return 0; //Encerra o programa
}
