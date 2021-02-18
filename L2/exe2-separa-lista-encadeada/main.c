#include "listadup.h"

int main(void){
	ListaDupla *l = inicializa(); //Cria um ponteiro que aponta para o primeiro endereço da lista dupla e inicializa a lista vazia
	l = insereOrd(l, 2);
	l = insereOrd(l, 4);
	l = insereOrd(l, 1);
	l = insereOrd(l, 6);
	l = insereOrd(l, 3);
	imprime(l);
	ListaDupla *l2 = inicializa();
	l2 = separa(l, 3);
	printf("Primeira subdivisao: \n");
	imprime(l);
	printf("Segunda subdivisao: \n");
	imprime(l2);
	libera(l);
	libera(l2);
	
	return 0;
}
