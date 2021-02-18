#include "lista.h"

int main(void){
	Lista *l = inicializa(); //Cria um ponteiro que aponta para o primeiro endereço da lista e inicializa a lista vazia
	/*l = insereInicio(l, 15); //Insere na primeira posição da lista o elemento 15
	l = insereInicio(l, 68); //Insere na primeira posição da lista o elemento 68
	l = insereInicio(l, 22); //Insere na primeira posição da lista o elemento 22
	l = insereInicio(l, 57); //Insere na primeira posição da lista o elemento 57
	l = insereInicio(l, 36); //Insere na primeira posição da lista o elemento 36
	imprime(l); //Imprime a lista atual
	l = elimina(l, 36); //Remove o elemento 36
	imprime(l); //Imprime a lista atual
	l = elimina(l, 22); //Remove o elemento 22
	imprime(l); //Imprime a lista atual
	libera(l);*/
	l = insere(l, 4);
	l = insere(l, 2);
	l = insere(l, 1);
	l = insere(l, 6);
	l = insere(l, 3);
	imprime(l);
	libera(l);

	return 0;
}
