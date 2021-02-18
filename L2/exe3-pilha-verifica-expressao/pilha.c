#include "pilha.h" /* Interface pilha.h */

/* TAD: Pilha */
struct pilha{
	char info; /* Informação guardada na lista */
	struct pilha *prox;	/* Ponteiro para o próximo elemento da lista */
};

Pilha* inicializa(void){
	return NULL;
}

Pilha* push(Pilha *p, char v){
	Pilha *novo = (Pilha*) malloc(sizeof(Pilha)); //Cria uma alocação dinâmica para o novo elemento
	Pilha *ant = NULL;
	novo->info = v; //Atribui o ponteiro novo que aponta para info o valor de v
	novo->prox = p; //Atribui o ponteiro novo que aponta para prox o conteúdo do ponteiro p (que aponta para a lista em si)
	return novo;
}

/* Versão com lista */
void imprime(Pilha *p){
	Pilha *q; //Ponteiro auxiliar para percorrer a lista
	for (q = p; q != NULL; q = q->prox) //Ponteiro q inicia com o apontamento do ponteiro p, onde até não chegar no final da lista (NULL), ponteiro q recebe o conteúdo de prox (aponta para o próximo elemento da lista) 
		printf("%c \n", q->info);
}

/* A pilha estará vazia se a lista estiver vazia */
int vazia(Pilha *p){
	return (p == NULL);	//Se for TRUE (1) está vazia, senão, FALSE (0)
}

void pop(Pilha **p){
	Pilha* q = *p; //Atribui o ponteiro q a pilha p
	*p = q->prox; //Atribui a p o conteúdo de q que aponta para prox
	free(q); //Libera o ponteiro q
}

void libera(Pilha *p){
	Pilha *q = p; //Cria o ponteiro q que inicia apontando para o começo da lista/pilha (p)
	while (q != NULL){ //Percorre toda a lista
		Pilha *t = q->prox; //Guarda o endereço do próximo elemento no ponteiro t
		free(q); //Libera a memória apontada por q (atual)
		q = t; //q recebe o endereço do próximo elemento (t)
	}
}

void verifica(char v[]){
	Pilha *p = inicializa(); //Inicializa uma pilha no ponteiro p
	int i = 0; //Índice do vetor v
	int e = 0; //Guarda se está correta ou incorreta (0 == correta e 1 == incorreta)
	for(i = 0; v[i] != '\0'; i++){ //Percorre a lista até o final
		if (v[i] == '('){ //Caso encontre um caracter de abertura de parêntese
			p = push(p, '('); //Atribui a p o retorno de push (insere na pilha o '(')
		}	
		
		if (v[i] == ')'){ //Caso encontre um caracter de fechamento de parêntese
			if (vazia(p)){ //Verifica se a pilha está vazia
				e = 1; //Significa que está vazia e incorreta
				break;
			}
			pop(&p); //Remove um parêntese
		}
	}
	if (vazia(p) && e == 0){ //Se estiver vazia e não ter entrado no if do vazia do fechamento de parêntese
		printf("Esta correto\n");
	}else{ //Se não estiver vazia
		printf("Esta incorreto\n");
	}
	libera(p); //Libera o ponteiro p
}
