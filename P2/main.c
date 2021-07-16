#include "arvbb.h"

int main(void){
	Arv *a = inicializa();
	a = insere(a, 6);
	a = insere(a, 2);
	a = insere(a, 8);
	a = insere(a, 1);
	a = insere(a, 4);
	a = insere(a, 3);
		
	/*Arv *b = inicializa();
	b = insere(b, 6);
	b = insere(b, 8);
	b = insere(b, 2);
	b = insere(b, 1);
	b = insere(b, 4);
	b = insere(b, 3);*/

	//imprime(a);
	//printf("%d de altura \n", calculaAlt(a));
	//printf("%d nos \n", contaNos(a));
	//a = retira(a, 6);
	//imprime(a);
	
	//printf("%d folhas \n", contaFolhas(a));
	//printf("%d maior elemento \n", contaMaior(a));
	/*if (igual(a,b) == 0)
		printf("Sao iguais");
	else
		printf("Nao sao iguais");*/
		
	printf("%d nao-folhas \n", contaNFolhas(a)); //Conta o número de não-folhas da árvore
	
	int fb =  calculaFB(a, 6); //Calcula o fator de balanceamento do nó
	if (fb == 20) //Se o nó estiver vazio
		printf("No esta vazio \n"); //Imprime
	else if (fb == 30) //Se o valor do nó não existir
		printf("Valor nao encontrado \n"); //Imprime
	else //Se encontrar o valor
		printf("Fator de balanceamento do no: %d \n", fb); //Imprime
	libera(a); //Libera a árvore
	//libera(b);
	return 0;
}
