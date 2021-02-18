#include "pilha.h"

int main(void){
	Pilha *p = inicializa(); //Aponta para o topo e inicializa a pilha
	p = push(p, 10);
	p = push(p, 30);
	p = push(p, 40);
	imprime(p);
	printf("Valor removido do topo: %d \n", pop(&p));
	imprime(p);
	libera(p);
	return 0;
}
