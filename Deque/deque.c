#include "deque.h" /* Interface deque.h */

Deque* cria(void){
	Deque *d = (Deque*)malloc(sizeof(Deque)); //Cria uma aloca��o din�mica para o novo elemento
	d->ini = d->fim = NULL;
	return d;
}

Deque* insereIni(Deque* d, int v){
	No *novo = (No*)malloc(sizeof(No));
	novo->info = v; //Atribui o ponteiro novo que aponta para info o valor de v
	novo->prox = NULL; //Atribui o ponteiro novo que aponta para prox NULL
	novo->ant = NULL; //Atribui o ponteiro novo que aponta para ant NULL
	if (d->ini != NULL){ //Verifica se a lista n�o estava vazia
		novo->prox = d->ini; //Atribui o ponteiro novo que aponta para prox o conte�do de d que aponta para ini. Ou seja, o pr�ximo do novo elemento recebe o endere�o do in�cio
		d->ini->ant = novo; //Atribui o ponteiro d que aponta para ini que aponta para ant o conte�do do ponteiro novo. Ou seja, em d no anterior do in�cio recebe o endere�o do novo elemento
	}
	d->ini = novo; //Atribui o ponteiro d que ap�nta para ini o conte�dodo ponteiro novo. Assim em d no in�cio ser� o elemento adicionado
	if (d->fim == NULL) //Se estiver vazia
		d->fim = d->ini; //Atribui o ponteiro d que aponta para fim o conte�do de d que aponta para ini (ambos ter�o o mesmo conte�do)
	return d;		
}

Deque* insereFim(Deque* d, int v){
	No *novo = (No*)malloc(sizeof(No));
	novo->info = v; //Atribui o ponteiro novo que aponta para info o valor de v
	novo->prox = NULL; //Atribui o ponteiro novo que aponta para prox NULL
	novo->ant = NULL; //Atribui o ponteiro novo que aponta para ant NULL
	if (d->fim != NULL){ //Verifica se a lista n�o estava vazia
		novo->ant = d->fim; //Atribui o ponteiro novo que aponta para ant o conte�do de d que aponta para fim. Ou seja, o anterior do novo elemento recebe o endere�o do fim
		d->fim->prox = novo; //Atribui o ponteiro d que aponta para fim que aponta para prox o conte�do do ponteiro novo. Ou seja, em d no pr�ximo do fim recebe o endere�o do novo elemento
	}
	d->fim = novo; //Atribui o ponteiro d que aponta para fim o conte�dodo ponteiro novo. Assim em d no fim ser� o elemento adicionado
	if (vazia(d)) //Se estiver vazia
		d->ini = d->fim; //Atribui o ponteiro d que aponta para ini o conte�do de d que aponta para fim (ambos ter�o o mesmo conte�do)	
	return d;			
}

/* Vers�o com lista (apenas para verificar como est� indo) */
void imprime(Deque *d){
	No *q; //Ponteiro auxiliar para percorrer a lista
	for (q = d->ini; q != NULL; q = q->prox) //Ponteiro q inicia com o apontamento do ponteiro d->ini, onde at� n�o chegar no final da lista (NULL), ponteiro q recebe o conte�do de prox (aponta para o pr�ximo elemento da lista) 
		printf("info: %d \n", q->info);
	if (vazia(d))
		printf("Lista vazia \n");
	printf("\n");
}

int vazia(Deque *d){
	return (d->ini == NULL); //Se for TRUE (1) est� vazia, sen�o, FALSE (0)
}

int eliminaIni(Deque *d){
	int v;
	if (vazia(d)){ //Verifica se a lista est� vazia
		printf("Deque vazio \n");
		exit(1); //Aborta o programa
	}
	v = d->ini->info; //v recebe o elemento a ser removido (info que est� no in�cio da lista) 
	No *p = d->ini->prox; //Ponteiro p recebe o endere�o de prox do in�cio do elemento a ser removido 
	free(d->ini); //Libera o endere�o de d que aponta para ini
	d->ini = p; //d que aponta para ini (in�cio) recebe o conte�do de p
	if (vazia(d)) //Se o deque ficou vazio
		d->fim = NULL;
	d->ini->ant = NULL; //d que aponta para o in�cio que aponta para o anterior recebe NULL (endere�o anterior do in�cio)	
	return v; //Retorna o elemento eliminado
}

int eliminaFim(Deque *d){
	int v;
	if (vazia(d)){ //Verifica se a lista est� vazia
		printf("Deque vazio \n");
		exit(1); //Aborta o programa
	}
	v = d->fim->info; //v recebe o elemento a ser removido (info que est� no final da lista)
	No *p = d->fim->ant; //Ponteiro p recebe o endere�o de ant do fim do elemento a ser removido 
	free(d->fim); //Libera o endere�o de d que aponta para fim
	d->fim = p; //d que aponta para fim recebe o endere�o de ant que est� no fim do elemento a ser removido 
	if (d->fim == NULL) //Se o deque ficou vazio
		d->ini = NULL;	
	d->fim->prox = NULL; //d que aponta para o fim que aponta para o pr�ximo recebe NULL (endere�o pr�ximo do fim)	
	return v; //Retorna o elemento eliminado
}

void libera(Deque *d){
	No *q = d->ini; //Cria o ponteiro q que inicia apontando para o come�o da lista (d)
	while (q != NULL){ //Percorre toda a lista
		No *t = q->prox; //Guarda o endere�o do pr�ximo elemento no ponteiro t
		free(q); //Libera a mem�ria apontada por q (atual)
		q = t; //q recebe o endere�o do pr�ximo elemento (t)
	}
	free(d); //Libera o deque
}
