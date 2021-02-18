#include "pilha.h" /* Interface pilha.h */

/* TAD: Pilha */
struct pilha{
	char info; /* Informa��o guardada na lista */
	struct pilha *prox;	/* Ponteiro para o pr�ximo elemento da lista */
};

Pilha* inicializa(void){
	return NULL;
}

Pilha* push(Pilha *p, char v){
	Pilha *novo = (Pilha*) malloc(sizeof(Pilha)); //Cria uma aloca��o din�mica para o novo elemento
	Pilha *ant = NULL;
	novo->info = v; //Atribui o ponteiro novo que aponta para info o valor de v
	novo->prox = p; //Atribui o ponteiro novo que aponta para prox o conte�do do ponteiro p (que aponta para a lista em si)
	return novo;
}

/* Vers�o com lista */
void imprime(Pilha *p){
	Pilha *q; //Ponteiro auxiliar para percorrer a lista
	for (q = p; q != NULL; q = q->prox) //Ponteiro q inicia com o apontamento do ponteiro p, onde at� n�o chegar no final da lista (NULL), ponteiro q recebe o conte�do de prox (aponta para o pr�ximo elemento da lista) 
		printf("%c \n", q->info);
}

/* A pilha estar� vazia se a lista estiver vazia */
int vazia(Pilha *p){
	return (p == NULL);	//Se for TRUE (1) est� vazia, sen�o, FALSE (0)
}

void pop(Pilha **p){
	Pilha* q = *p; //Atribui o ponteiro q a pilha p
	*p = q->prox; //Atribui a p o conte�do de q que aponta para prox
	free(q); //Libera o ponteiro q
}

void libera(Pilha *p){
	Pilha *q = p; //Cria o ponteiro q que inicia apontando para o come�o da lista/pilha (p)
	while (q != NULL){ //Percorre toda a lista
		Pilha *t = q->prox; //Guarda o endere�o do pr�ximo elemento no ponteiro t
		free(q); //Libera a mem�ria apontada por q (atual)
		q = t; //q recebe o endere�o do pr�ximo elemento (t)
	}
}

void verifica(char v[]){
	Pilha *p = inicializa(); //Inicializa uma pilha no ponteiro p
	int i = 0; //�ndice do vetor v
	int e = 0; //Guarda se est� correta ou incorreta (0 == correta e 1 == incorreta)
	for(i = 0; v[i] != '\0'; i++){ //Percorre a lista at� o final
		if (v[i] == '('){ //Caso encontre um caracter de abertura de par�ntese
			p = push(p, '('); //Atribui a p o retorno de push (insere na pilha o '(')
		}	
		
		if (v[i] == ')'){ //Caso encontre um caracter de fechamento de par�ntese
			if (vazia(p)){ //Verifica se a pilha est� vazia
				e = 1; //Significa que est� vazia e incorreta
				break;
			}
			pop(&p); //Remove um par�ntese
		}
	}
	if (vazia(p) && e == 0){ //Se estiver vazia e n�o ter entrado no if do vazia do fechamento de par�ntese
		printf("Esta correto\n");
	}else{ //Se n�o estiver vazia
		printf("Esta incorreto\n");
	}
	libera(p); //Libera o ponteiro p
}
