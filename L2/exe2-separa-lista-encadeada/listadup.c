#include "listadup.h" /* Interface listadup.h */

ListaDupla* inicializa(void){
	return NULL;
}

ListaDupla* insereOrd(ListaDupla *l, int i){
	ListaDupla *novo = (ListaDupla*) malloc(sizeof(ListaDupla)); //Cria uma aloca��o din�mica para o novo elemento
	novo->info = i; // Atribui o ponteiro novo que aponta para info o valor de i 
	if (vazia(l)){ //Se a lista estiver vazia
		novo->prox = l; //Atribui o ponteiro novo que aponta para prox o conte�do do ponteiro l (que aponta para a lista em si)
		novo->ant = NULL; //Atribui o ponteiro novo que aponta para ant NULL
	}else{ //Sen�o estiver vazia (procurar onde inserir)
		ListaDupla *ant, *p = l; //Ponteiro ant guardar� o endere�o anterior e p guardar� o endere�o atual
		while (p != NULL && p->info < novo->info){ //Percorre a lista at� o final 
			ant = p; //Guarda o elemento atual (p) no elemento anterior (ant)
			p = p->prox; //p recebe o conte�do do ponteiro p que aponta para prox
		}
		if (p == l){ //Insere no in�cio (elemento da lista j� era maior no in�cio)
			novo->ant = NULL; //Atribui o ponteiro novo que aponta para ant NULL
			novo->prox = l; //Atribui o ponteiro novo que aponta para prox o conte�do do ponteiro l (que aponta para a lista em si)
			p->ant = novo; //Atribui o ponteiro p que aponta para ant o cont�udo do ponteiro novo. Ou seja, o endere�o do atual ant recebe o endere�o do novo elemento
			l = novo; //Atribui o ponteiro l o conte�do do ponteiro novo
		}else{ //Sen�o estiver no in�cio (final ou meio)
			novo->prox = ant->prox; //Atribui o ponteiro novo que aponta para prox o conte�do do ponteiro ant que aponta para prox). Ou seja, o endere�o prox do elemento anterior a inser��o passa para o prox do novo elemento inserido
			novo->ant = ant; //Atribui o ponteiro novo que aponta para prox o conte�do do novo. Ou seja, o endere�o do ant de novo recebe o endere�o de ant, que seria o elemento anterior
			ant->prox = novo; //Atribui o ponteiro ant que aponta para prox o conte�do do novo. Ou seja, o endere�o do elemento anterior em prox ao elemento inserido recebe o endere�o do elemento inserido (novo) 
			if(p != NULL) //Sen�o estiver no fim da lista (meio)
				p->ant = novo; //Atribui o ponteiro p que aponta para ant o conte�do de novo. Ou seja, o endere�o do elemento atual em ant passa a ser o do novo elemento (inserido antes dele)
		}
	return l;	
	}
}

void imprime(ListaDupla *l){
	ListaDupla *p; //Ponteiro auxiliar para percorrer a lista
	for (p = l; p != NULL; p = p->prox) //Ponteiro p inicia com o apontamento do ponteiro l, onde at� n�o chegar no final da lista (NULL), ponteiro p recebe o conte�do de prox (aponta para o pr�ximo elemento da lista) 
		printf("info = %d\n", p->info);
	printf("\n");	
}

int vazia(ListaDupla *l){
	return (l == NULL);	//Se for TRUE (1) est� vazia, sen�o, FALSE (0)
}

ListaDupla* busca(ListaDupla *l, int v){
	ListaDupla *p; //Ponteiro auxiliar para percorrer a lista 
	for (p = l; p != NULL; p = p->prox){ //Ponteiro p inicia com o apontamento do ponteiro l, onde at� n�o chegar no final da lista (NULL), ponteiro p recebe o conte�do de prox (aponta para o pr�ximo elemento da lista) 
		if (p->info == v) //Se o ponteiro p que aponta para a info for igual ao elemento procurado, retorna o n�
			return p;
	}
	printf("Nao existe o elemento %d na lista\n\n", v);		
	return NULL; //N�o encontrou o elemento		
}

void libera(ListaDupla *l){
	ListaDupla *p = l; //Cria o ponteiro p que inicia apontando para o come�o da lista (l)
	ListaDupla *t = NULL; //Servir� para guardar o pr�ximo valor da lista
	while (p != NULL){ //Percorre toda a lista
		t = p->prox; //Guarda o endere�o do pr�ximo elemento no ponteiro t
		free(p); //Libera a mem�ria apontada por p (atual)
		p = t; //p recebe o endere�o do pr�ximo elemento (t)
	}
}

ListaDupla* separa(ListaDupla *l, int n){
	ListaDupla *p = busca(l, n); //Cria o ponteiro p que recebe o retorno da fun��o busca (o n� buscado)
	if (p == NULL) //Caso n�o exista o elemento
		return 0;
	if (p->prox == NULL){ //Caso a divis�o esteja no final da lista
		printf("\nNao foi possivel criar uma divisao \n\n");
		return 0;
	}
	ListaDupla *l2 = p->prox; //Atribui o ponteiro l2 (segunda lista) o conte�do de p que aponta para prox, ou seja, l2 recebe o pr�ximo conte�do de p
	p->prox->ant = NULL; //Atribui NULL ao anterior (ant) do pr�ximo (prox) de p (assim j� � definido NULL o ant da segunda subdivis�o da lista)
	p->prox = NULL; //Atribui NULL o ponteiro p que aponta para prox (define o "novo" final da primeira subdivis�o da lista (dividida em p) ent�o seu prox � NULL)
	return l2; //Retorna a segunda lista
}
