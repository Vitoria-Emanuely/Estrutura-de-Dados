#include "pilha.h" /* Interface pilha.h */

/* TAD: Pilha */
struct pilha{
	int info; /* Informação guardada na lista */
	struct pilha *prox;	/* Ponteiro para o próximo elemento da lista */
};

Pilha* inicializa(void){
	return NULL;
}

Pilha* push(Pilha *p, int v){
	Pilha *novo = (Pilha*) malloc(sizeof(Pilha)); //Cria uma alocação dinâmica para o novo elemento
	Pilha *ant = NULL;
	novo->info = v; //Atribui o ponteiro novo que aponta para info o valor de v
	novo->prox = p; //Atribui o ponteiro novo que aponta para prox o conteúdo do ponteiro p (que aponta para a lista em si)
	return novo;
}

/* Versão com lista */
void imprime(Pilha *p){
	Pilha *q; //Ponteiro auxiliar para percorrer a lista
	for (q = p; q != NULL; q = q->prox) //Ponteiro q inicia com o apontamento do ponteiro p, onde até não chegar no final da lista (NULL), ponteiro q recebe o conteúdo de prox (aponta para o próximo elemento da lista) 
		printf("%d \n", q->info);
	//printf("\n");	
}

/* A pilha estará vazia se a lista estiver vazia */
int vazia(Pilha *p){
	return (p == NULL);	//Se for TRUE (1) está vazia, senão, FALSE (0)
}

int pop(Pilha **p){
	int v = (*p)->info; //Atribui a v o conteúdo do ponteiro do ponteiro que aponta pra info
	Pilha *t = (*p)->prox; //Atribui ao ponteiro t (temporário) o conteúdo do ponteiro do ponteiro que aponta pra prox
	free(*p); //Libera o ponteiro do ponteiro p
	*p = t; //p recebe o endereço temporário
	return v; //Retorna o elemento excluído	
}

void libera(Pilha *p){
	Pilha *q = p; //Cria o ponteiro q que inicia apontando para o começo da lista/pilha (p)
	while (q != NULL){ //Percorre toda a lista
		Pilha *t = q->prox; //Guarda o endereço do próximo elemento no ponteiro t
		free(q); //Libera a memória apontada por q (atual)
		q = t; //q recebe o endereço do próximo elemento (t)
	}
}
