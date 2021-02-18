#include "listadup.h"

int main(void){
	ListaDupla *l = inicializa(); //Cria um ponteiro que aponta para o primeiro endereço da lista dupla e inicializa a lista vazia
	l = insereOrd(l, 2);
	l = insereOrd(l, 4);
	l = insereOrd(l, 1);
	l = insereOrd(l, 6);
	l = insereOrd(l, 3);
	imprimePU(l); //Imprime a lista atual do primeiro ao último elemento
	imprimeUP(l); //Imprime a lista atual do último ao primeiro elemento
	//l = elimina(l, 4); //Remove o elemento 36
	//imprimePU(l);
	//imprimeUP(l);
	libera(l);
	
	return 0;
}
