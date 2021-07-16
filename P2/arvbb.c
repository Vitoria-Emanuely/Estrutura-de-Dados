#include "arvbb.h" /* Interface arvbb.h */

Arv* inicializa(void){ //Inicializa a árvore vazia
	return NULL;
}

Arv* insere(Arv *a, int v){
	if (a == NULL){ //Se o nó está vazio
		a = (Arv*)malloc(sizeof(Arv)); //Cria uma alocação dinâmica para o novo nó
		a->info = v; //Atribui o ponteiro a que aponta para info o valor de v
		a->esq = a->dir = NULL; //Atribui o ponteiro a que aponta para a esq e a dir (sub-árvores) NULL
	}
	else if (v < a->info) //Se o valor a ser inserido é menor que info
		a->esq = insere(a->esq, v); //Ponteiro a que aponta para esq recebe recursivamente a função insere para o nó da esquerda e v
	else //O valor a ser inserido é maior que info
		a->dir = insere(a->dir, v); //Ponteiro a que aponta para dir recebe recursivamente a função insere para o nó da direita e v
	return a; //Retorna a, refazendo as ligações entre os ponteiros
}

void imprime(Arv *a){ //Imprime sempre nó mais a esquerda (In-Ordem/Ordem Simétrica)
	if (a != NULL){ //Enquanto nó não estiver vazio
		imprime(a->esq); //Chama recursivamente a função imprime para o nó da esquerda
		printf("%d\n", a->info); //Imprime
		imprime(a->dir); //Chama recursivamente a função imprime para o nó da direita
	}
}

Arv* busca(Arv *r, int v){
	if (r == NULL) //Se não encontrar o elemento (chegar em um nó NULL)
		return NULL;
	else if (v < r->info) //Se o valor a ser procurado é menor que info
		return busca(r->esq, v); //Retorna recursivamente uma busca para o nó da esquerda e v
	else if (v > r->info) //Se o valor a ser procurado é maior que info
		return busca(r->dir, v); //Retorna recursivamente uma busca para o nó da direita e v
	else //Achou o elemento
		return r; //Retorna o endereço do elemento buscado
}

Arv* retira(Arv *r, int v){
	/* Localiza o elemento */
	if (r == NULL) //Se não encontrar o elemento (chegar em um nó NULL)
		return NULL;
	else if (v < r->info) //Se o valor a ser eliminado é menor que info
		r->esq = retira(r->esq, v); //Ponteiro r que aponta para esq recebe recursivamente a função retira para o nó da esquerda e v
	else if (v > r->info) //Se o valor a ser eliminado é maior que info
		r->dir = retira(r->dir, v); //Ponteiro r que aponta para dir recebe recursivamente a função retira para o nó da direita e v
	else { /* Achou o elemnto */
		if (r->esq == NULL && r->dir == NULL){ /* Sae e Sad NULL: Elemento sem filhos */
			free(r); //Libera o nó 
			r = NULL; //r recebe NULL
		}	
		else if (r->esq == NULL){ /* Só tem filho a direita */
			Arv *t = r; //Cria um ponteiro t que recebe o conteúdo de r
			r = r->dir; //r recebe o conteúdo do ponteiro r que aponta para dir (r recebe nó da direta)
			free(t); //Libera o t
		}		
		else if (r->dir == NULL){ /* Só tem filho a esquerda */
			Arv *t = r; //Cria um ponteiro t que recebe o conteúdo de r
			r = r->esq; //r recebe o conteúdo do ponteiro r que aponta para esq (r recebe nó da esquerda)
			free(t); //Libera o t
		}
		else{ /* Tem os dois filhos */
			Arv *pai = r; //Cria um ponteiro pai que recebe o conteúdo de r
			Arv *f = r->esq; //Cria um ponteiro f que recebe o conteúdo de r que aponta para esq (nó a esquerda)
			while (f->dir != NULL){ //Enquanto f que aponta para dir (região a direita) não for NULL
				pai = f; //pai recebe f (r->esq)
				f = f->dir; //f recebe f que aponta para dir
			}
			r->info = f->info; //Troca as informações
			f->info = v; //Troca as informações
			r->esq = retira(r->esq, v); //Ponteiro r que aponta para esq recebe recursivamente a função retira para o nó da esquerda e v
		}
	}
	return r; //Retorna a árvore
}

Arv* libera(Arv *a){
	if (a != NULL){ //Se não estiver vazia
		libera(a->esq); //Libera sae
		libera(a->dir); //Libera sad
		free(a); //Libera a raiz
	}
	return NULL; //Retorna a árvore vazia
}

int contaNos(Arv *r){
	if (r == NULL) //Se o nó estiver vazio
		return 0; //0 nós
	int nEsq = contaNos(r->esq); //Cria variável nEsq que recebe recursivamente a função contaNos para o nó da esquerda 
	int nDir = contaNos(r->dir); //Cria variável nDir que recebe recursivamente a função contaNos para o nó da direita
	return (nEsq + nDir + 1); //Retorna a soma dos nós a esquerda e direita + 1 (raiz)
}

int calculaAlt(Arv *r){
	if (r == NULL) //Se a árvore estiver vazia
    	return -1; // Altura da árvore vazia
    int aEsq = calculaAlt(r->esq); //Cria variável aEsq que recebe recursivamente a função calculaAlt para o nó da esquerda 
    int aDir = calculaAlt(r->dir); //Cria variável aDir que recebe recursivamente a função calculaAlt para o nó da direita
    if (aEsq < aDir) //Se aEsq é menor que aDir 
		return aDir + 1; //Retorna a soma de aDir com 1
    else //Se aEsq é maior que aDir 
		return aEsq + 1; //Retorna a soma de aEsq com 1
}

int contaFolhas(Arv *r){
	if (r == NULL) //Se o nó estiver vazio
		return 0; //0 folhas
	int fEsq = contaFolhas(r->esq); //Cria variável fEsq que recebe recursivamente a função contaFolhas para o nó da esquerda 
	int fDir = contaFolhas(r->dir); //Cria variável fDir que recebe recursivamente a função contaFolhas para o nó da direita
	if (fEsq == 0 && fDir == 0) //Se os nós estiverem vazios (sem filhos)
		return 1; //Retorna que tem uma folha
	return fDir + fEsq; //Retorna a soma das folhas da direita e esquerda
}

int contaMaior(Arv *r){
	if (r == NULL) //Se o nó estiver vazio
		return 0; //0 nós
	else if (r->dir == NULL) //Verifica se a sub-árvore à direita é nula (os números mais altos encontram-se a direita)
		return r->info; //Retorna a raiz (que sempre será mais alta que os valores da sub-árvore à esquerda)
	else{ //Se a sub-árvore à direita existir (não for NULL)
		int maior = contaMaior(r->dir); //Cria variável maior que recebe recursivamente a função contaMaior para o nó da direita
		if (maior == 0){ //Se maior receber 0, signfica que ele chegou no último nó todo a direita (maior elemento da árvore)
			maior = r->info; //maior recebe o conteúdo de r que aponra para info (info do nó)
			return maior; //Retorna maior
		}
	}	 
}

int igual(Arv *r, Arv *s){
	if (r == NULL && s == NULL) //Se ambos os nós estiverem vazios
		return 0; //Retorna para serem iguais
	else if (r == NULL && s != NULL) //Se o nó r estiver vazio o s não
        return 1; //Retorna para não serem iguais
    else if (r != NULL && s == NULL) //Se o nó r não estiver vazio o s sim
        return 1; //Retorna para não serem iguais
	else if (r->info == s->info){ //Verifica se os infos dos nós de ambas as árvores são iguais
		int iEsq = igual(r->esq, s->esq); //Cria variável iEsq que recebe recursivamente a função igual para os nós da esquerda de ambas as árvores
		if(iEsq == 1) //Se iEsq receber 1, significa que algum nó era diferente
			return 1; //Retorna para não serem iguais
		int iDir = igual(r->dir, s->dir); //Cria variável iDir que recebe recursivamente a função igual para os nós da direita de ambas as árvores
		if(iDir == 1) //Se iDir receber 1, significa que algum nó era diferente
			return 1; //Retorna para não serem iguais
		return 0; //Retorna para serem iguais 
	}
	else
		return 1; //Retorna para não serem iguais
}

/* Exercício 1 */
int contaNFolhas(Arv *r){	
	if (r == NULL) //Se o nó estiver vazio
		return 0; //0 nós
	else if (r->esq == NULL && r->dir == NULL) //Se ambos os nós estiverem vazios 
		return 0; //Retorna 0 por ser uma folha (não alterando a soma)
	int nfEsq = contaNFolhas(r->esq); //Cria variável nfEsq que recebe recursivamente a função contaNFolhas para o nó da esquerda 
	int nfDir = contaNFolhas(r->dir); //Cria variável nfDir que recebe recursivamente a função contaNFolhas para o nó da direita
	return (nfEsq + nfDir + 1); //Retorna a soma dos nós a esquerda e direita + 1 (raiz)
}

/* Exercício 4 */
int calculaFB(Arv *r, int v){
	if (r == NULL) //Se o nó estiver vazio
		return 20; //Retorna 20 para tratar no main
	Arv *n = busca(r, v); //Cria variável n que recebe o retorno da função busca (o endereço do elemento buscado)
	if (n == NULL) //Se o nó não for encontrado
		return 30; //Retorna 30 para tratar no main
	return calculaAlt(n->dir) - calculaAlt(n->esq); //Retorna o fator de balanceamento do nó, que é dado pela altura da sub-árvore à direita menos a altura da sub-árvore à esquerda
}
