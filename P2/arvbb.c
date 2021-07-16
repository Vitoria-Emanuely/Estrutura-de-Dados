#include "arvbb.h" /* Interface arvbb.h */

Arv* inicializa(void){ //Inicializa a �rvore vazia
	return NULL;
}

Arv* insere(Arv *a, int v){
	if (a == NULL){ //Se o n� est� vazio
		a = (Arv*)malloc(sizeof(Arv)); //Cria uma aloca��o din�mica para o novo n�
		a->info = v; //Atribui o ponteiro a que aponta para info o valor de v
		a->esq = a->dir = NULL; //Atribui o ponteiro a que aponta para a esq e a dir (sub-�rvores) NULL
	}
	else if (v < a->info) //Se o valor a ser inserido � menor que info
		a->esq = insere(a->esq, v); //Ponteiro a que aponta para esq recebe recursivamente a fun��o insere para o n� da esquerda e v
	else //O valor a ser inserido � maior que info
		a->dir = insere(a->dir, v); //Ponteiro a que aponta para dir recebe recursivamente a fun��o insere para o n� da direita e v
	return a; //Retorna a, refazendo as liga��es entre os ponteiros
}

void imprime(Arv *a){ //Imprime sempre n� mais a esquerda (In-Ordem/Ordem Sim�trica)
	if (a != NULL){ //Enquanto n� n�o estiver vazio
		imprime(a->esq); //Chama recursivamente a fun��o imprime para o n� da esquerda
		printf("%d\n", a->info); //Imprime
		imprime(a->dir); //Chama recursivamente a fun��o imprime para o n� da direita
	}
}

Arv* busca(Arv *r, int v){
	if (r == NULL) //Se n�o encontrar o elemento (chegar em um n� NULL)
		return NULL;
	else if (v < r->info) //Se o valor a ser procurado � menor que info
		return busca(r->esq, v); //Retorna recursivamente uma busca para o n� da esquerda e v
	else if (v > r->info) //Se o valor a ser procurado � maior que info
		return busca(r->dir, v); //Retorna recursivamente uma busca para o n� da direita e v
	else //Achou o elemento
		return r; //Retorna o endere�o do elemento buscado
}

Arv* retira(Arv *r, int v){
	/* Localiza o elemento */
	if (r == NULL) //Se n�o encontrar o elemento (chegar em um n� NULL)
		return NULL;
	else if (v < r->info) //Se o valor a ser eliminado � menor que info
		r->esq = retira(r->esq, v); //Ponteiro r que aponta para esq recebe recursivamente a fun��o retira para o n� da esquerda e v
	else if (v > r->info) //Se o valor a ser eliminado � maior que info
		r->dir = retira(r->dir, v); //Ponteiro r que aponta para dir recebe recursivamente a fun��o retira para o n� da direita e v
	else { /* Achou o elemnto */
		if (r->esq == NULL && r->dir == NULL){ /* Sae e Sad NULL: Elemento sem filhos */
			free(r); //Libera o n� 
			r = NULL; //r recebe NULL
		}	
		else if (r->esq == NULL){ /* S� tem filho a direita */
			Arv *t = r; //Cria um ponteiro t que recebe o conte�do de r
			r = r->dir; //r recebe o conte�do do ponteiro r que aponta para dir (r recebe n� da direta)
			free(t); //Libera o t
		}		
		else if (r->dir == NULL){ /* S� tem filho a esquerda */
			Arv *t = r; //Cria um ponteiro t que recebe o conte�do de r
			r = r->esq; //r recebe o conte�do do ponteiro r que aponta para esq (r recebe n� da esquerda)
			free(t); //Libera o t
		}
		else{ /* Tem os dois filhos */
			Arv *pai = r; //Cria um ponteiro pai que recebe o conte�do de r
			Arv *f = r->esq; //Cria um ponteiro f que recebe o conte�do de r que aponta para esq (n� a esquerda)
			while (f->dir != NULL){ //Enquanto f que aponta para dir (regi�o a direita) n�o for NULL
				pai = f; //pai recebe f (r->esq)
				f = f->dir; //f recebe f que aponta para dir
			}
			r->info = f->info; //Troca as informa��es
			f->info = v; //Troca as informa��es
			r->esq = retira(r->esq, v); //Ponteiro r que aponta para esq recebe recursivamente a fun��o retira para o n� da esquerda e v
		}
	}
	return r; //Retorna a �rvore
}

Arv* libera(Arv *a){
	if (a != NULL){ //Se n�o estiver vazia
		libera(a->esq); //Libera sae
		libera(a->dir); //Libera sad
		free(a); //Libera a raiz
	}
	return NULL; //Retorna a �rvore vazia
}

int contaNos(Arv *r){
	if (r == NULL) //Se o n� estiver vazio
		return 0; //0 n�s
	int nEsq = contaNos(r->esq); //Cria vari�vel nEsq que recebe recursivamente a fun��o contaNos para o n� da esquerda 
	int nDir = contaNos(r->dir); //Cria vari�vel nDir que recebe recursivamente a fun��o contaNos para o n� da direita
	return (nEsq + nDir + 1); //Retorna a soma dos n�s a esquerda e direita + 1 (raiz)
}

int calculaAlt(Arv *r){
	if (r == NULL) //Se a �rvore estiver vazia
    	return -1; // Altura da �rvore vazia
    int aEsq = calculaAlt(r->esq); //Cria vari�vel aEsq que recebe recursivamente a fun��o calculaAlt para o n� da esquerda 
    int aDir = calculaAlt(r->dir); //Cria vari�vel aDir que recebe recursivamente a fun��o calculaAlt para o n� da direita
    if (aEsq < aDir) //Se aEsq � menor que aDir 
		return aDir + 1; //Retorna a soma de aDir com 1
    else //Se aEsq � maior que aDir 
		return aEsq + 1; //Retorna a soma de aEsq com 1
}

int contaFolhas(Arv *r){
	if (r == NULL) //Se o n� estiver vazio
		return 0; //0 folhas
	int fEsq = contaFolhas(r->esq); //Cria vari�vel fEsq que recebe recursivamente a fun��o contaFolhas para o n� da esquerda 
	int fDir = contaFolhas(r->dir); //Cria vari�vel fDir que recebe recursivamente a fun��o contaFolhas para o n� da direita
	if (fEsq == 0 && fDir == 0) //Se os n�s estiverem vazios (sem filhos)
		return 1; //Retorna que tem uma folha
	return fDir + fEsq; //Retorna a soma das folhas da direita e esquerda
}

int contaMaior(Arv *r){
	if (r == NULL) //Se o n� estiver vazio
		return 0; //0 n�s
	else if (r->dir == NULL) //Verifica se a sub-�rvore � direita � nula (os n�meros mais altos encontram-se a direita)
		return r->info; //Retorna a raiz (que sempre ser� mais alta que os valores da sub-�rvore � esquerda)
	else{ //Se a sub-�rvore � direita existir (n�o for NULL)
		int maior = contaMaior(r->dir); //Cria vari�vel maior que recebe recursivamente a fun��o contaMaior para o n� da direita
		if (maior == 0){ //Se maior receber 0, signfica que ele chegou no �ltimo n� todo a direita (maior elemento da �rvore)
			maior = r->info; //maior recebe o conte�do de r que aponra para info (info do n�)
			return maior; //Retorna maior
		}
	}	 
}

int igual(Arv *r, Arv *s){
	if (r == NULL && s == NULL) //Se ambos os n�s estiverem vazios
		return 0; //Retorna para serem iguais
	else if (r == NULL && s != NULL) //Se o n� r estiver vazio o s n�o
        return 1; //Retorna para n�o serem iguais
    else if (r != NULL && s == NULL) //Se o n� r n�o estiver vazio o s sim
        return 1; //Retorna para n�o serem iguais
	else if (r->info == s->info){ //Verifica se os infos dos n�s de ambas as �rvores s�o iguais
		int iEsq = igual(r->esq, s->esq); //Cria vari�vel iEsq que recebe recursivamente a fun��o igual para os n�s da esquerda de ambas as �rvores
		if(iEsq == 1) //Se iEsq receber 1, significa que algum n� era diferente
			return 1; //Retorna para n�o serem iguais
		int iDir = igual(r->dir, s->dir); //Cria vari�vel iDir que recebe recursivamente a fun��o igual para os n�s da direita de ambas as �rvores
		if(iDir == 1) //Se iDir receber 1, significa que algum n� era diferente
			return 1; //Retorna para n�o serem iguais
		return 0; //Retorna para serem iguais 
	}
	else
		return 1; //Retorna para n�o serem iguais
}

/* Exerc�cio 1 */
int contaNFolhas(Arv *r){	
	if (r == NULL) //Se o n� estiver vazio
		return 0; //0 n�s
	else if (r->esq == NULL && r->dir == NULL) //Se ambos os n�s estiverem vazios 
		return 0; //Retorna 0 por ser uma folha (n�o alterando a soma)
	int nfEsq = contaNFolhas(r->esq); //Cria vari�vel nfEsq que recebe recursivamente a fun��o contaNFolhas para o n� da esquerda 
	int nfDir = contaNFolhas(r->dir); //Cria vari�vel nfDir que recebe recursivamente a fun��o contaNFolhas para o n� da direita
	return (nfEsq + nfDir + 1); //Retorna a soma dos n�s a esquerda e direita + 1 (raiz)
}

/* Exerc�cio 4 */
int calculaFB(Arv *r, int v){
	if (r == NULL) //Se o n� estiver vazio
		return 20; //Retorna 20 para tratar no main
	Arv *n = busca(r, v); //Cria vari�vel n que recebe o retorno da fun��o busca (o endere�o do elemento buscado)
	if (n == NULL) //Se o n� n�o for encontrado
		return 30; //Retorna 30 para tratar no main
	return calculaAlt(n->dir) - calculaAlt(n->esq); //Retorna o fator de balanceamento do n�, que � dado pela altura da sub-�rvore � direita menos a altura da sub-�rvore � esquerda
}
