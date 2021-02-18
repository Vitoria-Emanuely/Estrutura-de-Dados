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

void imprime(ListaDupla *l){
	ListaDupla *p; //Ponteiro auxiliar para percorrer a lista
	for (p = l; p != NULL; p = p->prox) //Ponteiro p inicia com o apontamento do ponteiro l, onde até não chegar no final da lista (NULL), ponteiro p recebe o conteúdo de prox (aponta para o próximo elemento da lista) 
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
	printf("Nao existe o elemento %d na lista\n\n", v);		
	return NULL; //Não encontrou o elemento		
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

ListaDupla* separa(ListaDupla *l, int n){
	ListaDupla *p = busca(l, n); //Cria o ponteiro p que recebe o retorno da função busca (o nó buscado)
	if (p == NULL) //Caso não exista o elemento
		return 0;
	if (p->prox == NULL){ //Caso a divisão esteja no final da lista
		printf("\nNao foi possivel criar uma divisao \n\n");
		return 0;
	}
	ListaDupla *l2 = p->prox; //Atribui o ponteiro l2 (segunda lista) o conteúdo de p que aponta para prox, ou seja, l2 recebe o próximo conteúdo de p
	p->prox->ant = NULL; //Atribui NULL ao anterior (ant) do próximo (prox) de p (assim já é definido NULL o ant da segunda subdivisão da lista)
	p->prox = NULL; //Atribui NULL o ponteiro p que aponta para prox (define o "novo" final da primeira subdivisão da lista (dividida em p) então seu prox é NULL)
	return l2; //Retorna a segunda lista
}
