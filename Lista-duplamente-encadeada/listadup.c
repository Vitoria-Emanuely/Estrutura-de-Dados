#include "listadup.h" /* Interface listadup.h */

ListaDupla* inicializa(void){
	return NULL;
}

ListaDupla* insereOrd(ListaDupla *l, int i){
	ListaDupla *novo = (ListaDupla*) malloc(sizeof(ListaDupla)); //Cria uma alocação dinâmica para o novo elemento
	novo->info = i; // Atribui o ponteiro novo que aponta para info o valor de i 
	if (vazia(l)){ //Se a lista estiver vazia
		novo->prox = l; //Atribui o ponteiro novo que aponta para prox o conteúdo do ponteiro l (que aponta para a lista em si)
		novo->ant = NULL; //Atribui o ponteiro novo que aponta para ant NULL
	}else{ //Senão estiver vazia (procurar onde inserir)
		ListaDupla *ant, *p = l; //Ponteiro ant guardará o endereço anterior e p guardará o endereço atual
		while (p != NULL && p->info < novo->info){ //Percorre a lista até o final 
			ant = p; //Guarda o elemento atual (p) no elemento anterior (ant)
			p = p->prox; //p recebe o conteúdo do ponteiro p que aponta para prox
		}
		if (p == l){ //Insere no início (elemento da lista já era maior no início)
			novo->ant = NULL; //Atribui o ponteiro novo que aponta para ant NULL
			novo->prox = l; //Atribui o ponteiro novo que aponta para prox o conteúdo do ponteiro l (que aponta para a lista em si)
			p->ant = novo; //Atribui o ponteiro p que aponta para ant o contéudo do ponteiro novo. Ou seja, o endereço do atual ant recebe o endereço do novo elemento
			l = novo; //Atribui o ponteiro l o conteúdo do ponteiro novo
		}else{ //Senão estiver no início (final ou meio)
			novo->prox = ant->prox; //Atribui o ponteiro novo que aponta para prox o conteúdo do ponteiro ant que aponta para prox). Ou seja, o endereço prox do elemento anterior a inserção passa para o prox do novo elemento inserido
			novo->ant = ant; //Atribui o ponteiro novo que aponta para prox o conteúdo do novo. Ou seja, o endereço do ant de novo recebe o endereço de ant, que seria o elemento anterior
			ant->prox = novo; //Atribui o ponteiro ant que aponta para prox o conteúdo do novo. Ou seja, o endereço do elemento anterior em prox ao elemento inserido recebe o endereço do elemento inserido (novo) 
			if(p != NULL) //Senão estiver no fim da lista (meio)
				p->ant = novo; //Atribui o ponteiro p que aponta para ant o conteúdo de novo. Ou seja, o endereço do elemento atual em ant passa a ser o do novo elemento (inserido antes dele)
		}
	return l;	
	}
}

void imprimePU(ListaDupla *l){
	ListaDupla *p; //Ponteiro auxiliar para percorrer a lista
	for (p = l; p != NULL; p = p->prox) //Ponteiro p inicia com o apontamento do ponteiro l, onde até não chegar no final da lista (NULL), ponteiro p recebe o conteúdo de prox (aponta para o próximo elemento da lista) 
		printf("info = %d\n", p->info);
	printf("\n");	
}

void imprimeUP(ListaDupla *l){
	ListaDupla *p, *f; //Ponteiro auxiliar para percorrer a lista e ponteiro que guardará o último endereço
	for (p = l; p != NULL; p = p->prox){ //Ponteiro p inicia com o apontamento do ponteiro l, onde até não chegar no final da lista (NULL), ponteiro p recebe o conteúdo de prox (aponta para o próximo elemento da lista) 
		if (p->prox == NULL) //Se estiver no último elemento
			f = p; //Ponteiro f recebe o endereço do último elemento
	}
	for (p = f; p != NULL; p = p->ant) //Ponteiro p inicia com o conteúdo de f (último endereço), onde até não chegar no início da lista (NULL), ponteiro p recebe o conteúdo de ant (aponta para o elemento anterior da lista) 	
		printf("info = %d\n", p->info);
	printf("\n");
}

int vazia(ListaDupla *l){
	return (l == NULL);	//Se for TRUE (1) está vazia, senão, FALSE (0)
}

ListaDupla* busca(ListaDupla *l, int v){
	ListaDupla *p; //Ponteiro auxiliar para percorrer a lista 
	for (p = l; p != NULL; p = p->prox){ //Ponteiro p inicia com o apontamento do ponteiro l, onde até não chegar no final da lista (NULL), ponteiro p recebe o conteúdo de prox (aponta para o próximo elemento da lista) 
		if (p->info == v) //Se o ponteiro p que aponta para a info for igual ao elemento procurado, retorna o nó
			return p;
	}
	return NULL; //Não encontrou o elemento		
}

ListaDupla* elimina(ListaDupla *l, int v){
	ListaDupla *p = busca(l, v);
	
	/* Verifica se encontrou o elemento */
	if (p == NULL) //Se não achou o elemento, retorna a lista original
		return l;
		
	/* Se encontrou, remove o elemento */	
	if (l == p) //Se p for o primeiro elemento
		l = p->prox; //O primeiro endereço da lista é substituído com o endereço do próximo elemento
	else //Se não for no início, está no meio da lista
		p->ant->prox = p->prox; //Substitui no ponteiro prox apontado pelo ant com o conteúdo do ponteiro p que aponta para prox (nó que será removido)
	
	if (p->prox != NULL) //Se p não for o último elemento
		p->prox->ant = p->ant; //Substitui no ponteiro ant apontado pelo prox com o conteúdo de p que aponta para ant
	
	free(p); //Libera o ponteiro p
	return l; //Retorna a lista	
}

void libera(ListaDupla *l){
	ListaDupla *p = l; //Cria o ponteiro p que inicia apontando para o começo da lista (l)
	ListaDupla *t = NULL; //Servirá para guardar o próximo valor da lista
	while (p != NULL){ //Percorre toda a lista
		t = p->prox; //Guarda o endereço do próximo elemento no ponteiro t
		free(p); //Libera a memória apontada por p (atual)
		p = t; //p recebe o endereço do próximo elemento (t)
	}
}
