#include "lista.h" /* Interface lista.h */

Lista* inicializa(void){
	return NULL;
}

Lista* insereInicio(Lista *l, int i){
	Lista *novo = (Lista*) malloc(sizeof(Lista)); //Cria uma aloca��o din�mica para o novo elemento
	Lista *ant = NULL;
	novo->info = i; // Atribui o ponteiro novo que aponta para info o valor de i 
	novo->prox = l; //Atribui o ponteiro novo que aponta para prox o conte�do do ponteiro l (que aponta para a lista em si)
	return novo;
}

Lista* insere(Lista *l, int i){
	if (vazia(l)){ //Se a lista estiver vazia
		return insereInicio(l, i); //Insere no in�cio
	}else{ //Sen�o estiver vazia
		Lista *novo = (Lista*) malloc(sizeof(Lista)); //Cria uma aloca��o din�mica para o novo elemento
		novo->info = i; // Atribui o ponteiro novo que aponta para info o valor de i
		Lista *p = l; //Ponteiro que guardar� o endere�o atual
		Lista *ant = NULL; //Ponteiro que guardar� o endere�o anterior
		while (p != NULL && novo->info > p->info){ //Percorre a lista at� o final 
			ant = p; //Guarda o elemento atual (p) no elemento anterior (ant)
			p = p->prox; //p recebe o conte�do do ponteiro p que aponta para prox
		}
		novo->prox = p; //O conte�do do ponteiro novo que aponta para prox recebe p
		if(ant == NULL){ //Se o anterior for NULL (estiver no in�cio)
			l = novo; //Atribui o ponteiro l o conte�do do ponteiro novo
		}else{ //Sen�o estiver no in�cio (no meio ou no final)
			ant->prox = novo; //Atribui o ponteiro ant que aponta para prox o conte�do do ponteiro novo
		}
	return l;
	}
}

void imprime(Lista *l){
	Lista *p; //Ponteiro auxiliar para percorrer a lista
	for (p = l; p != NULL; p = p->prox) //Ponteiro p inicia com o apontamento do ponteiro l, onde at� n�o chegar no final da lista (NULL), ponteiro p recebe o conte�do de prox (aponta para o pr�ximo elemento da lista) 
		printf("info = %d\n", p->info);
	printf("\n");	
}

int vazia(Lista *l){
	return (l == NULL);	//Se for TRUE (1) est� vazia, sen�o, FALSE (0)
}

Lista* busca(Lista *l, int v){
	Lista *p; //Ponteiro auxiliar para percorrer a lista
	for (p = l; p != NULL; p = p->prox) //Ponteiro p inicia com o apontamento do ponteiro l, onde at� n�o chegar no final da lista (NULL), ponteiro p recebe o conte�do de prox (aponta para o pr�ximo elemento da lista) 
		if (p->info == v) //Se o ponteiro p que aponta para a info for igual ao elemento procurado, retorna o n�
			return p;
	return NULL; //N�o encontrou o elemento		
}

Lista* elimina(Lista *l, int v){
	Lista *ant = NULL; //Cria o ponteiro ant que guarda o endere�o do elemento anterior (como inicia na primeia posi��o, a anterior � NULL)
	Lista *p = l; //Cria o ponteiro p que guarda o apontamento que l faz, mantendo o elemento atual (percorre a lista)
	
	while (p != NULL && p->info != v){ //Percorre a lista at� o final ou at� encontrar o elemento
		ant = p; //Guarda o elemento atual (p) no elemento anterior (ant)
		p = p->prox; //p recebe o conte�do do ponteiro p que aponta para prox
	}
	
	/* Verifica se encontrou o elemento */
	if (p == NULL) //Se n�o achou o elemento, retorna a lista original
		return l;
		
	/* Se encontrou, remove o elemento */	
	if (ant == NULL){ //Se o elemento anterior for NULL, significa que est� no in�cio da lista
		l = p->prox; //O primeiro endere�o da lista � substitu�do com o endere�o do pr�ximo elemento
	}else{ //Se n�o for no in�cio, est� no meio da lista
		ant->prox = p->prox; //Substitui no ponteiro ant (anterior) que aponta para prox com o conte�do do ponteiro p que aponta para prox (n� que ser� removido)
	}
	
	free(p); //Libera o ponteiro p
	return l; //Retorna a lista	
}

void libera(Lista *l){
	Lista *p = l; //Cria o ponteiro p que inicia apontando para o come�o da lista (l)
	Lista *t = NULL; //Servir� para guardar o pr�ximo valor da lista
	while (p != NULL){ //Percorre toda a lista
		t = p->prox; //Guarda o endere�o do pr�ximo elemento no ponteiro t
		free(p); //Libera a mem�ria apontada por p (atual)
		p = t; //p recebe o endere�o do pr�ximo elemento (t)
	}
}
