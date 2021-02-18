#include "lista.h" /* Interface lista.h */

Lista* inicializa(void){
	return NULL;
}

Lista* insereInicio(Lista *l, int i){
	Lista *novo = (Lista*) malloc(sizeof(Lista)); //Cria uma aloca��o din�mica para o novo elemento
	novo->info = i; //Atribui o ponteiro novo que aponta para info o valor de i 
	novo->prox = l; //Atribui o ponteiro novo que aponta para prox o conte�do do ponteiro l (que aponta para a lista em si)
	if (vazia(l)){ //Se estiver vazia
		novo->prox = novo; //Atribui o ponteiro novo que aponta para prox o conte�do do ponteiro novo (aponta para ele mesmo) 
		return novo;
	}
	Lista *p = l;
	do {
		p = p->prox; //p recebe o endere�o de p que aponta para prox 
	}
	while (p->prox != l); //Enquanto o pr�ximo endere�o for diferente do in�cio da lista
	Lista *aux = p->prox; //Atribui o ponteiro aux o conte�do de p que aponta para prox
	novo->prox = aux; //Atribui a novo que aponta para prox o conte�do de aux (pr�ximo de novo recebe o aux)
	p->prox = novo; //Atribui a p que aponta para prox o conte�do de novo (pr�ximo recebe o novo conte�do, aponta para o in�cio)
	return novo;
}

void imprime(Lista *l){
	Lista *p = l; //Ponteiro p recebe a lista
	do {
		printf("info = %d | info prox = %d\n", p->info, p->prox->info); //Imprime
		p = p->prox; //p recebe o endere�o de p que aponta para prox  
	}
	while (p != l); //Enquanto p (atual) for diferente do in�cio da lista
	printf("\n");
}

int vazia(Lista *l){
	return (l == NULL);	//Se for TRUE (1) est� vazia, sen�o, FALSE (0)
}

Lista* busca(Lista *l, int v){
	Lista *p = l; //Ponteiro p recebe a lista
	do {
		if (p->info == v){ //Se o ponteiro p que aponta para a info for igual ao elemento procurado
			printf("info = %d | info prox = %d\n\n", p->info, p->prox->info);
			return p; //Retorna o n�
		}
		p = p->prox; //p recebe o endere�o de p que aponta para prox 
	}
	while (p != l); //Enquanto p (atual) for diferente do in�cio da lista		
	printf("Nao existe o elemento %d na lista \n", v);
	return NULL; //N�o encontrou o elemento		
}

Lista* elimina(Lista *l, int v){
	Lista *p = l; //Ponteiro p recebe a lista
	Lista *aux = NULL; //Cria ponteiro auxiliar
	if(vazia(l)){ //Se estiver vazia
        return NULL;
    }
    /* Verifica se est� no in�cio e se existe s� o elemento que ser� eliminado */
    if (p->info == v && p->prox == l){
    	free(l); //Libera a lista
    	return NULL;
	}
	do {
		aux = p; 
		p = p->prox; //p recebe o endere�o de p que aponta para prox 
		if (p->info == v){ /* Encontrou o elemento */
			aux->prox = p->prox; //Atribui a aux que aponta para prox o conte�do de p que aponta para prox (prox de aux recebe prox de p)
			if (p == l){ //Se est� no in�cio
				free(p); //Libera o ponteiro p
				return aux->prox; //Retorna o segundo elemento da lista, que ser� o novo "in�cio"
			}
			free(p); //Libera o ponteiro p
			break;
		}
		if (p == l){ /* Caso n�o encontrou o elemento */
			printf("\n Nao existe o elemento %d na lista \n", v);
			break;
		}
	}while(1); //Sempre entrar� no loop, sai ao satisfazer uma das condi��es
	return l;
}

void libera(Lista *l){
	Lista *p = l; //Cria o ponteiro p que inicia apontando para o come�o da lista (l)
	Lista *t = NULL; //Servir� para guardar o pr�ximo valor da lista
	do {
		t = p->prox; //Guarda o endere�o do pr�ximo elemento no ponteiro t
		free(p); //Libera a mem�ria apontada por p (atual)
		p = t; //p recebe o endere�o do pr�ximo elemento (t)
	}
	while (p != l); //Enquanto p (atual) for diferente do in�cio da lista	
}

/* Fun��o do exerc�cio 4 da p1: Problema de Josephus */
int Josephus(int n, int k){
	Lista *l = inicializa(); //Cria um ponteiro que aponta para o primeiro endere�o da lista e inicializa a lista vazia
	int i, h, v; //Declara as vari�veis do tipo inteiro (i ser� auxiliar no for, h guardar� o valor digitado e v guardar� o valor que ser� retornado da fun��o)
	for (i = 0; i < n; i++){ //Pede para inserir na lista n elementos
		printf("Digite o numero a ser inserido no inicio: \n"); //Imprime na tela
		scanf("%d", &h); //Guarda o valor digitado no endere�o de h
		l = insereInicio(l, h); //Lista (l) recebe o retorno da inser��o no in�cio
	}
	Lista *p; //Cria um ponteiro p que ser� auxiliar do tipo Lista
	Lista *q = l; //Cria o ponteiro q que inicia apontando para o come�o da lista (l)
	while (n != 1){ //Enquanto n�o sobrar um �nico elemento
		int z = 1; //Declara a vari�vel z do tipo inteiro que representa o n�mero de trocas que o p->prox fez 
		if (k != 1){ //Verifica se k n�o � 1, assim fazendo um for para procurar o elemento a ser eliminado
			for (p = q; z < k; z++){ //Procura o elemento que k deve eliminar
				p = p->prox; //Guarda o endere�o do pr�ximo elemento no ponteiro p
			}
			q = p->prox; //Guarda o endere�o do pr�ximo elemento no ponteiro q
		}
		if (k == 1){ //Verifica se k � igual 1
			p = q; //Ponteiro p recebe conte�do de q 
			q = p->prox; //Guarda o endere�o do pr�ximo elemento no ponteiro q
		}
		l = elimina(l, p->info); //Lista (l) recebe o retorno da elimina��o 
		n--; //Subtrai uma unidade de n
	}
	v = q->info; //v recebe o conte�do de q que aponra para info, ou seja, recebe a info (n�mero inteiro)
	libera(l); //Libera a lista (l)
	return v; //Retorna o �ltimo elemento que sobrou na lista		
}
