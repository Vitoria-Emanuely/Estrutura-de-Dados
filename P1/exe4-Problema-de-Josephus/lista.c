#include "lista.h" /* Interface lista.h */

Lista* inicializa(void){
	return NULL;
}

Lista* insereInicio(Lista *l, int i){
	Lista *novo = (Lista*) malloc(sizeof(Lista)); //Cria uma alocação dinâmica para o novo elemento
	novo->info = i; //Atribui o ponteiro novo que aponta para info o valor de i 
	novo->prox = l; //Atribui o ponteiro novo que aponta para prox o conteúdo do ponteiro l (que aponta para a lista em si)
	if (vazia(l)){ //Se estiver vazia
		novo->prox = novo; //Atribui o ponteiro novo que aponta para prox o conteúdo do ponteiro novo (aponta para ele mesmo) 
		return novo;
	}
	Lista *p = l;
	do {
		p = p->prox; //p recebe o endereço de p que aponta para prox 
	}
	while (p->prox != l); //Enquanto o próximo endereço for diferente do início da lista
	Lista *aux = p->prox; //Atribui o ponteiro aux o conteúdo de p que aponta para prox
	novo->prox = aux; //Atribui a novo que aponta para prox o conteúdo de aux (próximo de novo recebe o aux)
	p->prox = novo; //Atribui a p que aponta para prox o conteúdo de novo (próximo recebe o novo conteúdo, aponta para o início)
	return novo;
}

void imprime(Lista *l){
	Lista *p = l; //Ponteiro p recebe a lista
	do {
		printf("info = %d | info prox = %d\n", p->info, p->prox->info); //Imprime
		p = p->prox; //p recebe o endereço de p que aponta para prox  
	}
	while (p != l); //Enquanto p (atual) for diferente do início da lista
	printf("\n");
}

int vazia(Lista *l){
	return (l == NULL);	//Se for TRUE (1) está vazia, senão, FALSE (0)
}

Lista* busca(Lista *l, int v){
	Lista *p = l; //Ponteiro p recebe a lista
	do {
		if (p->info == v){ //Se o ponteiro p que aponta para a info for igual ao elemento procurado
			printf("info = %d | info prox = %d\n\n", p->info, p->prox->info);
			return p; //Retorna o nó
		}
		p = p->prox; //p recebe o endereço de p que aponta para prox 
	}
	while (p != l); //Enquanto p (atual) for diferente do início da lista		
	printf("Nao existe o elemento %d na lista \n", v);
	return NULL; //Não encontrou o elemento		
}

Lista* elimina(Lista *l, int v){
	Lista *p = l; //Ponteiro p recebe a lista
	Lista *aux = NULL; //Cria ponteiro auxiliar
	if(vazia(l)){ //Se estiver vazia
        return NULL;
    }
    /* Verifica se está no início e se existe só o elemento que será eliminado */
    if (p->info == v && p->prox == l){
    	free(l); //Libera a lista
    	return NULL;
	}
	do {
		aux = p; 
		p = p->prox; //p recebe o endereço de p que aponta para prox 
		if (p->info == v){ /* Encontrou o elemento */
			aux->prox = p->prox; //Atribui a aux que aponta para prox o conteúdo de p que aponta para prox (prox de aux recebe prox de p)
			if (p == l){ //Se está no início
				free(p); //Libera o ponteiro p
				return aux->prox; //Retorna o segundo elemento da lista, que será o novo "início"
			}
			free(p); //Libera o ponteiro p
			break;
		}
		if (p == l){ /* Caso não encontrou o elemento */
			printf("\n Nao existe o elemento %d na lista \n", v);
			break;
		}
	}while(1); //Sempre entrará no loop, sai ao satisfazer uma das condições
	return l;
}

void libera(Lista *l){
	Lista *p = l; //Cria o ponteiro p que inicia apontando para o começo da lista (l)
	Lista *t = NULL; //Servirá para guardar o próximo valor da lista
	do {
		t = p->prox; //Guarda o endereço do próximo elemento no ponteiro t
		free(p); //Libera a memória apontada por p (atual)
		p = t; //p recebe o endereço do próximo elemento (t)
	}
	while (p != l); //Enquanto p (atual) for diferente do início da lista	
}

/* Função do exercício 4 da p1: Problema de Josephus */
int Josephus(int n, int k){
	Lista *l = inicializa(); //Cria um ponteiro que aponta para o primeiro endereço da lista e inicializa a lista vazia
	int i, h, v; //Declara as variáveis do tipo inteiro (i será auxiliar no for, h guardará o valor digitado e v guardará o valor que será retornado da função)
	for (i = 0; i < n; i++){ //Pede para inserir na lista n elementos
		printf("Digite o numero a ser inserido no inicio: \n"); //Imprime na tela
		scanf("%d", &h); //Guarda o valor digitado no endereço de h
		l = insereInicio(l, h); //Lista (l) recebe o retorno da inserção no início
	}
	Lista *p; //Cria um ponteiro p que será auxiliar do tipo Lista
	Lista *q = l; //Cria o ponteiro q que inicia apontando para o começo da lista (l)
	while (n != 1){ //Enquanto não sobrar um único elemento
		int z = 1; //Declara a variável z do tipo inteiro que representa o número de trocas que o p->prox fez 
		if (k != 1){ //Verifica se k não é 1, assim fazendo um for para procurar o elemento a ser eliminado
			for (p = q; z < k; z++){ //Procura o elemento que k deve eliminar
				p = p->prox; //Guarda o endereço do próximo elemento no ponteiro p
			}
			q = p->prox; //Guarda o endereço do próximo elemento no ponteiro q
		}
		if (k == 1){ //Verifica se k é igual 1
			p = q; //Ponteiro p recebe conteúdo de q 
			q = p->prox; //Guarda o endereço do próximo elemento no ponteiro q
		}
		l = elimina(l, p->info); //Lista (l) recebe o retorno da eliminação 
		n--; //Subtrai uma unidade de n
	}
	v = q->info; //v recebe o conteúdo de q que aponra para info, ou seja, recebe a info (número inteiro)
	libera(l); //Libera a lista (l)
	return v; //Retorna o último elemento que sobrou na lista		
}
