#include "lista.h" /* Interface lista.h */

Lista* inicializa(void){
	return NULL;
}

Lista* insereInicio(Lista *l, int i){
	Lista *novo = (Lista*) malloc(sizeof(Lista)); //Cria uma alocação dinâmica para o novo elemento
	Lista *ant = NULL;
	novo->info = i; // Atribui o ponteiro novo que aponta para info o valor de i 
	novo->prox = l; //Atribui o ponteiro novo que aponta para prox o conteúdo do ponteiro l (que aponta para a lista em si)
	return novo;
}

Lista* insere(Lista *l, int i){
	if (vazia(l)){ //Se a lista estiver vazia
		return insereInicio(l, i); //Insere no início
	}else{ //Senão estiver vazia
		Lista *novo = (Lista*) malloc(sizeof(Lista)); //Cria uma alocação dinâmica para o novo elemento
		novo->info = i; // Atribui o ponteiro novo que aponta para info o valor de i
		Lista *p = l; //Ponteiro que guardará o endereço atual
		Lista *ant = NULL; //Ponteiro que guardará o endereço anterior
		while (p != NULL && novo->info > p->info){ //Percorre a lista até o final 
			ant = p; //Guarda o elemento atual (p) no elemento anterior (ant)
			p = p->prox; //p recebe o conteúdo do ponteiro p que aponta para prox
		}
		novo->prox = p; //O conteúdo do ponteiro novo que aponta para prox recebe p
		if(ant == NULL){ //Se o anterior for NULL (estiver no início)
			l = novo; //Atribui o ponteiro l o conteúdo do ponteiro novo
		}else{ //Senão estiver no início (no meio ou no final)
			ant->prox = novo; //Atribui o ponteiro ant que aponta para prox o conteúdo do ponteiro novo
		}
	return l;
	}
}

void imprime(Lista *l){
	Lista *p; //Ponteiro auxiliar para percorrer a lista
	for (p = l; p != NULL; p = p->prox) //Ponteiro p inicia com o apontamento do ponteiro l, onde até não chegar no final da lista (NULL), ponteiro p recebe o conteúdo de prox (aponta para o próximo elemento da lista) 
		printf("info = %d\n", p->info);
	printf("\n");	
}

int vazia(Lista *l){
	return (l == NULL);	//Se for TRUE (1) está vazia, senão, FALSE (0)
}

Lista* busca(Lista *l, int v){
	Lista *p; //Ponteiro auxiliar para percorrer a lista
	for (p = l; p != NULL; p = p->prox) //Ponteiro p inicia com o apontamento do ponteiro l, onde até não chegar no final da lista (NULL), ponteiro p recebe o conteúdo de prox (aponta para o próximo elemento da lista) 
		if (p->info == v) //Se o ponteiro p que aponta para a info for igual ao elemento procurado, retorna o nó
			return p;
	return NULL; //Não encontrou o elemento		
}

Lista* elimina(Lista *l, int v){
	Lista *ant = NULL; //Cria o ponteiro ant que guarda o endereço do elemento anterior (como inicia na primeia posição, a anterior é NULL)
	Lista *p = l; //Cria o ponteiro p que guarda o apontamento que l faz, mantendo o elemento atual (percorre a lista)
	
	while (p != NULL && p->info != v){ //Percorre a lista até o final ou até encontrar o elemento
		ant = p; //Guarda o elemento atual (p) no elemento anterior (ant)
		p = p->prox; //p recebe o conteúdo do ponteiro p que aponta para prox
	}
	
	/* Verifica se encontrou o elemento */
	if (p == NULL) //Se não achou o elemento, retorna a lista original
		return l;
		
	/* Se encontrou, remove o elemento */	
	if (ant == NULL){ //Se o elemento anterior for NULL, significa que está no início da lista
		l = p->prox; //O primeiro endereço da lista é substituído com o endereço do próximo elemento
	}else{ //Se não for no início, está no meio da lista
		ant->prox = p->prox; //Substitui no ponteiro ant (anterior) que aponta para prox com o conteúdo do ponteiro p que aponta para prox (nó que será removido)
	}
	
	free(p); //Libera o ponteiro p
	return l; //Retorna a lista	
}

void libera(Lista *l){
	Lista *p = l; //Cria o ponteiro p que inicia apontando para o começo da lista (l)
	Lista *t = NULL; //Servirá para guardar o próximo valor da lista
	while (p != NULL){ //Percorre toda a lista
		t = p->prox; //Guarda o endereço do próximo elemento no ponteiro t
		free(p); //Libera a memória apontada por p (atual)
		p = t; //p recebe o endereço do próximo elemento (t)
	}
}
