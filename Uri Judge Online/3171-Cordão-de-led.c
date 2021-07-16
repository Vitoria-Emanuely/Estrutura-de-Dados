/* Programa que verifica se todos os segmentos do cordão de led foram unidos, imprimindo completo caso positivo e incompleto caso negativo. Utiliza as estruturas de Fila e Grafo (Busca em Largura) */

#include <stdio.h>
#include <stdlib.h>

/* Fila */

typedef struct noF{
	int info; //Informação guardada no Nó
	struct noF *prox; //Ponteiro para o próximo elemento da fila
}noFila; //Tipo exportado

typedef struct fila{ // Informação guardada na Fila 
	noFila *ini; // Ponteiro para o primeiro elemento da lista 
	noFila *fim; // Ponteiro para o último elemento da lista 
}tipo_fila; //Tipo exportado

tipo_fila* criaFila(void){
	tipo_fila *f = (tipo_fila*)malloc(sizeof(tipo_fila)); //Cria uma alocação dinâmica para o novo elemento
	f->ini = f->fim = NULL; //Ini e fim recebem NULL
	return f;
}

int vazia(tipo_fila *f){
	return (f->ini == NULL); //Se for TRUE (1) está vazia, senão, FALSE (0)
}

tipo_fila* insereFila(tipo_fila* f, int v){
	noFila *novo = (noFila*)malloc(sizeof(noFila)); //Cria uma alocação dinâmica para o novo elemento
	novo->info = v; //Atribui o ponteiro novo que aponta para info o valor de v
	novo->prox = NULL; //Atribui o ponteiro novo que aponta para prox NULL
	if (f->fim != NULL){ //Verifica se a fila não estava vazia
		f->fim->prox = novo; //Atribui f ponteiro d que aponta para fim que aponta para prox o conteúdo do ponteiro novo. Ou seja, em f no próximo do fim recebe o endereço do novo elemento
	}
	f->fim = novo; //Atribui o ponteiro f que aponta para fim o conteúdodo ponteiro novo. Assim em f no fim será o elemento adicionado
	if (vazia(f)) //Se estiver vazia
		f->ini = f->fim; //Atribui o ponteiro f que aponta para ini o conteúdo de f que aponta para fim (ambos terão o mesmo conteúdo)	
	return f;			
}

/* Versão com lista (apenas para verificar como está indo) */
void imprimeFila(tipo_fila *f){
	noFila *q; //Ponteiro auxiliar para percorrer a fila
	for (q = f->ini; q != NULL; q = q->prox) //Ponteiro q inicia com o apontamento do ponteiro f->ini, onde até não chegar no final da fila (NULL), ponteiro q recebe o conteúdo de prox (aponta para o próximo elemento da fila) 
		printf("info: %d \n", q->info); //Imprime na tela
	if (vazia(f)) //Se estiver vazia
		printf("Lista vazia \n"); //Imprime na tela
	printf("\n"); //Imprime na tela
}

int retiraFila(tipo_fila *f){
	int v; //Cria variável v do tipo inteiro
	if (vazia(f)){ //Verifica se a fila está vazia
		printf("Fila vazia \n"); //Imprime na tela
		exit(1); //Aborta o programa
	}
	v = f->ini->info; //v recebe o elemento a ser removido (info que está no início da lista) 
	noFila *p = f->ini->prox; //Ponteiro p recebe o endereço de prox do início do elemento a ser removido 
	free(f->ini); //Libera o endereço de f que aponta para ini
	f->ini = p; //f que aponta para ini (início) recebe o conteúdo de p
	if (vazia(f)) //Se a fila ficou vazia
		f->fim = NULL; //f que aponta para o fim recebe NULL
	return v; //Retorna o elemento eliminado
}

tipo_fila* liberaFila(tipo_fila *f){
	noFila *q = f->ini; //Cria o ponteiro q que inicia apontando para o começo da fila (f)
	while (q != NULL){ //Percorre toda a fila
		noFila *t = q->prox; //Guarda o endereço do próximo elemento no ponteiro t
		free(q); //Libera a memória apontada por q (atual)
		q = t; //q recebe o endereço do próximo elemento (t)
	}
	free(f); //Libera a fila
	return NULL; //Libera memória
}

/* Fim da Fila */

/* Lista de Adjacência*/

typedef struct no{ //Estrutura para cada lista de vértices
	int vertice; //Vértice guardado no nó
	int cor; //Cor guardada no nó (0 = Branco, 1 = Cinza, 2 = Preto)
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
	//novoNo->cor = NULL; //Ponteiro novoNo que aponta para cor recebe NULL
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

/* Busca em Largura */
/* Legenda: 
	- Branco = 0
	- Cinza = 1
	- Preto = 2 */

void buscaLargura(tipo_grafo *g, int origem){
	int i, u; //Declara as variáveis i, u do tipo inteiro
	tipo_no *v; //Declara ponteiro v
	for (i = 0; i < g->nVer; i++){ //Percorre o vetor
		if (i != origem){ //Se i for diferente do valor da origem
			g->vetorLista[i].cor = 0; //Ponteiro g que aponta para vetorLista na posição i em cor recebe 0 (Branco)
		}
	}
	tipo_no *t = &(g->vetorLista[origem]); //Declara ponteiro t que recebe o endereço de memória do ponteiro g que aponta para vetorLista na posição origem
	t->cor = 1; //Ponteiro t que aponta para cor recebe 1 (Cinza)
	tipo_fila *f = criaFila(); //Cria um ponteiro que aponta para o primeiro endereço da fila e inicializa a fila vazia
	insereFila(f, origem); //Chama a função insereFila passando f e origem
	while (!vazia(f)){ //Enquanto a fila não estiver vazia
		u = retiraFila(f); //Variável u recebe o retorno da função retiraFila passando f
		for (v = g->vetorLista[u].prox; v != NULL; v = v->prox){ //Percorre o vetor na posição u em prox
			if (g->vetorLista[v->vertice].cor == 0){ //Se ponteiro g que aponta para vetorLista na posição do ponteiro v que aponta para vertice em cor for igual a 0 (Branco)
				g->vetorLista[v->vertice].cor = 1; //Ponteiro g que aponta para vetorLista na posição do ponteiro v que aponta para vertice em cor recebe  (Cinza)
				insereFila(f, v->vertice); //Chama função insereFila passando f e ponteiro v que aponta para vértice
			}
		}
		g->vetorLista[u].cor = 2; //Ponteiro g que aponta para vetorLista na posição u em cor recebe 2 (Preto)
	}
	liberaFila(f); //Chama função liberaFila passando f
}

void mostraBusca(tipo_grafo *g){
	int i; //Declara variável i do tipo inteiro
	printf("============ Grafo ============\n"); //Imprime na tela
	for (i = 0; i < g->nVer; i++){ //Percorre o vetor
		printf("\tVertice: %d <==> Cor: %d\n", i, g->vetorLista[i].cor); //Imprime na tela
	}
	printf("================================\n"); //Imprime na tela
}

/* Fim Busca em Largura*/

/* Função verificaCordao que verifica se o cordão está completo ou incompleto*/
void verificaCordao(tipo_grafo *g, int n){
	int i; //Declara variável i do tipo inteiro
	int c = 0; //Declara variável c que recebe 0 (contador)
	for (i = 0; i < g->nVer; i++){ //Percorre vetor
		if (g->vetorLista[i].cor == 2){ //Se ponteiro g que aponta para vetorLista na posição i em cor for igual a 2 (preto)
			c++; //Variável c recebe + 1
		}
	}
	if (c == n){ //Se c for igual a n (total de vértices)
		printf("COMPLETO\n"); //Imprime na tela
	}else{ //Não foi tudo pintado de preto
		printf("INCOMPLETO\n"); //Imprime na tela
	}
}

/* Função principal */
int main(void){
	int n, l, i, x, y; //Declara variáveis n, l, i, x, y do tipo inteiro
    scanf("%d %d", &n, &l); //Guarda os valores digitados nos endereços de n e l respectivamente
    if (n < 1 || n > 100 || l < 1 || l > 100){ //Se não respeitar (1 = N = 100, 1 = L = 100)
        scanf("%d %d", &n, &l); //Guarda os valores digitados nos endereços de n e l respectivamente
    }
    tipo_grafo *g = criaGrafo(n); //Ponteiro g recebe o retorno da função criaGrafo passando n
    for (i = 0; i < l; i++){
        scanf("%d %d", &x, &y); //Guarda os valores digitados nos endereços de x e y respectivamente
        addAresta(g, x - 1, y - 1); //Chama a função addAresta passando g, x e y (- 1 é devido as funções do grafo começarem em 0)
    }
	if (g == NULL){ //Se o grafo estiver vazio
		return -1; //Encerra o programa
	}
	//mostraGrafo(g);
	buscaLargura(g, x); //Função que faz a busca em largura do grafo com origem x
	//mostraBusca(g);
	verificaCordao(g, n); //Função que verifica se o cordão de led está completo ou incompleto passando g e n 
	g = destroiGrafo(g); //Destrói o grafo liberando a memória
	return 0; //Encerra o programa
}
