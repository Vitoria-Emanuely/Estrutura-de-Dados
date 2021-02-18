#include "deque.h" /* Interface deque.h */

Deque* cria(void){
	Deque *d = (Deque*)malloc(sizeof(Deque)); //Cria uma alocação dinâmica para o novo elemento
	d->ini = d->fim = NULL;
	return d;
}

Deque* insereIni(Deque* d, int v){
	No *novo = (No*)malloc(sizeof(No));
	novo->info = v; //Atribui o ponteiro novo que aponta para info o valor de v
	novo->prox = NULL; //Atribui o ponteiro novo que aponta para prox NULL
	novo->ant = NULL; //Atribui o ponteiro novo que aponta para ant NULL
	if (d->ini != NULL){ //Verifica se a lista não estava vazia
		novo->prox = d->ini; //Atribui o ponteiro novo que aponta para prox o conteúdo de d que aponta para ini. Ou seja, o próximo do novo elemento recebe o endereço do início
		d->ini->ant = novo; //Atribui o ponteiro d que aponta para ini que aponta para ant o conteúdo do ponteiro novo. Ou seja, em d no anterior do início recebe o endereço do novo elemento
	}
	d->ini = novo; //Atribui o ponteiro d que apónta para ini o conteúdodo ponteiro novo. Assim em d no início será o elemento adicionado
	if (d->fim == NULL) //Se estiver vazia
		d->fim = d->ini; //Atribui o ponteiro d que aponta para fim o conteúdo de d que aponta para ini (ambos terão o mesmo conteúdo)
	return d;		
}

Deque* insereFim(Deque* d, int v){
	No *novo = (No*)malloc(sizeof(No));
	novo->info = v; //Atribui o ponteiro novo que aponta para info o valor de v
	novo->prox = NULL; //Atribui o ponteiro novo que aponta para prox NULL
	novo->ant = NULL; //Atribui o ponteiro novo que aponta para ant NULL
	if (d->fim != NULL){ //Verifica se a lista não estava vazia
		novo->ant = d->fim; //Atribui o ponteiro novo que aponta para ant o conteúdo de d que aponta para fim. Ou seja, o anterior do novo elemento recebe o endereço do fim
		d->fim->prox = novo; //Atribui o ponteiro d que aponta para fim que aponta para prox o conteúdo do ponteiro novo. Ou seja, em d no próximo do fim recebe o endereço do novo elemento
	}
	d->fim = novo; //Atribui o ponteiro d que aponta para fim o conteúdodo ponteiro novo. Assim em d no fim será o elemento adicionado
	if (vazia(d)) //Se estiver vazia
		d->ini = d->fim; //Atribui o ponteiro d que aponta para ini o conteúdo de d que aponta para fim (ambos terão o mesmo conteúdo)	
	return d;			
}

/* Versão com lista (apenas para verificar como está indo) */
void imprime(Deque *d){
	No *q; //Ponteiro auxiliar para percorrer a lista
	for (q = d->ini; q != NULL; q = q->prox) //Ponteiro q inicia com o apontamento do ponteiro d->ini, onde até não chegar no final da lista (NULL), ponteiro q recebe o conteúdo de prox (aponta para o próximo elemento da lista) 
		printf("info: %d \n", q->info);
	if (vazia(d))
		printf("Lista vazia \n");
	printf("\n");
}

int vazia(Deque *d){
	return (d->ini == NULL); //Se for TRUE (1) está vazia, senão, FALSE (0)
}

int eliminaIni(Deque *d){
	int v;
	if (vazia(d)){ //Verifica se a lista está vazia
		printf("Deque vazio \n");
		exit(1); //Aborta o programa
	}
	v = d->ini->info; //v recebe o elemento a ser removido (info que está no início da lista) 
	No *p = d->ini->prox; //Ponteiro p recebe o endereço de prox do início do elemento a ser removido 
	free(d->ini); //Libera o endereço de d que aponta para ini
	d->ini = p; //d que aponta para ini (início) recebe o conteúdo de p
	if (vazia(d)) //Se o deque ficou vazio
		d->fim = NULL;
	d->ini->ant = NULL; //d que aponta para o início que aponta para o anterior recebe NULL (endereço anterior do início)	
	return v; //Retorna o elemento eliminado
}

int eliminaFim(Deque *d){
	int v;
	if (vazia(d)){ //Verifica se a lista está vazia
		printf("Deque vazio \n");
		exit(1); //Aborta o programa
	}
	v = d->fim->info; //v recebe o elemento a ser removido (info que está no final da lista)
	No *p = d->fim->ant; //Ponteiro p recebe o endereço de ant do fim do elemento a ser removido 
	free(d->fim); //Libera o endereço de d que aponta para fim
	d->fim = p; //d que aponta para fim recebe o endereço de ant que está no fim do elemento a ser removido 
	if (d->fim == NULL) //Se o deque ficou vazio
		d->ini = NULL;	
	d->fim->prox = NULL; //d que aponta para o fim que aponta para o próximo recebe NULL (endereço próximo do fim)	
	return v; //Retorna o elemento eliminado
}

void libera(Deque *d){
	No *q = d->ini; //Cria o ponteiro q que inicia apontando para o começo da lista (d)
	while (q != NULL){ //Percorre toda a lista
		No *t = q->prox; //Guarda o endereço do próximo elemento no ponteiro t
		free(q); //Libera a memória apontada por q (atual)
		q = t; //q recebe o endereço do próximo elemento (t)
	}
	free(d); //Libera o deque
}
