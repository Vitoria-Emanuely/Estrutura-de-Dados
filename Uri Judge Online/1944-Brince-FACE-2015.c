#include <stdio.h>
#include <stdlib.h>

struct pilha{
	char info; /* Informação guardada na lista */
	struct pilha *prox;	/* Ponteiro para o próximo elemento da lista */
};

typedef struct pilha Pilha;

Pilha* inicializa(void){
	return NULL;
}

Pilha* push(Pilha *p, char v){
	Pilha *novo = (Pilha*) malloc(sizeof(Pilha)); //Cria uma alocação dinâmica para o novo elemento
	novo->info = v; //Atribui o ponteiro novo que aponta para info o valor de v
	novo->prox = p; //Atribui o ponteiro novo que aponta para prox o conteúdo do ponteiro p (que aponta para a lista em si)
	return novo;
}

/* Versão com lista */
/*void imprime(Pilha *p){
	Pilha *q; //Ponteiro auxiliar para percorrer a lista
	for (q = p; q != NULL; q = q->prox) //Ponteiro q inicia com o apontamento do ponteiro p, onde até não chegar no final da lista (NULL), ponteiro q recebe o conteúdo de prox (aponta para o próximo elemento da lista) 
		printf("%c \n", q->info);
	//printf("\n");	
}*/

/* A pilha estará vazia se a lista estiver vazia */
int vazia(Pilha *p){
	return (p == NULL);	//Se for TRUE (1) está vazia, senão, FALSE (0)
}

char pop(Pilha **p){
	int v = (*p)->info; //Atribui a v o conteúdo do ponteiro do ponteiro que aponta pra info
	Pilha *t = (*p)->prox; //Atribui ao ponteiro t (temporário) o conteúdo do ponteiro do ponteiro que aponta pra prox
	free(*p); //Libera o ponteiro do ponteiro p
	*p = t; //p recebe o endereço temporário
	return v; //Retorna o elemento excluído	
}

void libera(Pilha *p){
	Pilha *q = p; //Cria o ponteiro q que inicia apontando para o começo da lista/pilha (p)
	while (q != NULL){ //Percorre toda a lista
		Pilha *t = q->prox; //Guarda o endereço do próximo elemento no ponteiro t
		free(q); //Libera a memória apontada por q (atual)
		q = t; //q recebe o endereço do próximo elemento (t)
	}
}

int insereSorteio(int N){
    Pilha *p = inicializa(); //Aponta para o topo e inicializa a pilha
    if (vazia(p)){
        p = push(p, 'F');
        p = push(p, 'A');
        p = push(p, 'C');
        p = push(p, 'E');
    }

    int z, j = 0, brindes = 0;
    char letra1, letra2, letra3, letra4;
    if (N >= 1 || N <= 100){
        while(j < N){
            if (vazia(p)){
                p = push(p, 'F');
                p = push(p, 'A');
                p = push(p, 'C');
                p = push(p, 'E');
            }
            Pilha *q = p;
                //printf("Digite o caracter: \n");
                fflush(stdin);
                scanf("%c %c %c %c", &letra1, &letra2, &letra3, &letra4);
                getchar();

                if (letra1 == q->info){
					q = q->prox;
					p = push(p, letra1);
					if (letra2 == q->info){
						q = q->prox;
						p = push(p, letra2);
						if (letra3 == q->info){
							q = q->prox;
							p = push(p, letra3);
							if (letra4 == q->info){
								for (z = 0; z < 7; z++){
                                	pop(&p);
                                }
                            	brindes++;
							}else{
                				p = push(p, letra4);
							}
						}else{
                			p = push(p, letra3);
                			p = push(p, letra4);
						}
					}else{
                		p = push(p, letra2);
                		p = push(p, letra3);
                		p = push(p, letra4);
					}
                }else{
                    p = push(p, letra1);
                	p = push(p, letra2);
                	p = push(p, letra3);
                	p = push(p, letra4);
                }
            j++;
        }
    }
    else{
        return 0;
    }
    //imprime(p);
    libera(p);
    return brindes;
}

int main(void){
	int N;
	//printf("Digite o numero de visitantes: \n");
	scanf("%d", &N);
	getchar();
	printf("%d\n", insereSorteio(N));
	
	return 0;
	
}
