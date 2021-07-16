#include "arvbin.h" /* Interface arvin.h */

Arv* inicializa(void){
	return NULL;
}

Arv* cria(char c, Arv *sae, Arv *sad){
	Arv *p = (Arv*)malloc(sizeof(Arv)); //Cria uma aloca��o din�mica para o novo n�
	p->info = c; //Atribui o ponteiro p que aponta para info o valor de c 
	p->esq = sae; //Atribui o ponteiro p que aponta para esq o valor de sae
	p->dir = sad; //Atribui o ponteiro p que aponta para dir o valor de sad
	return p; //Retorna o endere�o do n� raiz
}

int vazia(Arv *a){
	return a == NULL; //Se for TRUE (1) est� vazia, sen�o, FALSE (0)
}

void imprimePreOrdem(Arv *a){ 
	if(!vazia(a)){ //Se n�o estiver vazia
		printf("%c ", a->info); //Printa a info associada a raiz
		imprimePreOrdem(a->esq); //Printa a sae
		imprimePreOrdem(a->dir); //Imprime a sad
	}
}

void imprimePosOrdem(Arv *a){ 
	if(!vazia(a)){ //Se n�o estiver vazia
		imprimePosOrdem(a->esq); //Printa a sae
		imprimePosOrdem(a->dir); //Imprime a sad
		printf("%c ", a->info); //Printa a info associada a raiz
	}
}

void imprimeInOrdem(Arv *a){ 
	if(!vazia(a)){ //Se n�o estiver vazia
		imprimeInOrdem(a->esq); //Printa a sae
		printf("%c ", a->info); //Printa a info associada a raiz
		imprimeInOrdem(a->dir); //Imprime a sad
	}
}

Arv* libera(Arv *a){
	if (!vazia(a)){ //Se n�o estiver vazia
		libera(a->esq); //Libera sae
		libera(a->dir); //Libera sad
		free(a); //Libera a raiz
	}
	return NULL; //Retorna a �rvore vazia
}

int busca(Arv *a, char c){
	if (vazia(a)) //Se estiver vazia
		return 0; //N�o encontrou
	else
		return a->info == c || busca(a->esq, c) || busca(a->dir, c); //Retorna 1 se encontrou o elemento
}
