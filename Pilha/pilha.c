#include "pilha.h" /* Interface pilha.h */

/* TAD: Pilha */
struct pilha{
	int info; /* Informa��o guardada na lista */
	struct pilha *prox;	/* Ponteiro para o pr�ximo elemento da lista */
};

Pilha* inicializa(void){
	return NULL;
}

Pilha* push(Pilha *p, int v){
	Pilha *novo = (Pilha*) malloc(sizeof(Pilha)); //Cria uma aloca��o din�mica para o novo elemento
	Pilha *ant = NULL;
	novo->info = v; //Atribui o ponteiro novo que aponta para info o valor de v
	novo->prox = p; //Atribui o ponteiro novo que aponta para prox o conte�do do ponteiro p (que aponta para a lista em si)
	return novo;
}

/* Vers�o com lista */
void imprime(Pilha *p){
	Pilha *q; //Ponteiro auxiliar para percorrer a lista
	for (q = p; q != NULL; q = q->prox) //Ponteiro q inicia com o apontamento do ponteiro p, onde at� n�o chegar no final da lista (NULL), ponteiro q recebe o conte�do de prox (aponta para o pr�ximo elemento da lista) 
		printf("%d \n", q->info);
	//printf("\n");	
}

/* A pilha estar� vazia se a lista estiver vazia */
int vazia(Pilha *p){
	return (p == NULL);	//Se for TRUE (1) est� vazia, sen�o, FALSE (0)
}

int pop(Pilha **p){
	int v = (*p)->info; //Atribui a v o conte�do do ponteiro do ponteiro que aponta pra info
	Pilha *t = (*p)->prox; //Atribui ao ponteiro t (tempor�rio) o conte�do do ponteiro do ponteiro que aponta pra prox
	free(*p); //Libera o ponteiro do ponteiro p
	*p = t; //p recebe o endere�o tempor�rio
	return v; //Retorna o elemento exclu�do	
}

void libera(Pilha *p){
	Pilha *q = p; //Cria o ponteiro q que inicia apontando para o come�o da lista/pilha (p)
	while (q != NULL){ //Percorre toda a lista
		Pilha *t = q->prox; //Guarda o endere�o do pr�ximo elemento no ponteiro t
		free(q); //Libera a mem�ria apontada por q (atual)
		q = t; //q recebe o endere�o do pr�ximo elemento (t)
	}
}
