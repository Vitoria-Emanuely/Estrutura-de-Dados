#include "lista.h"

int main(void){
	/* Obs: Minha fun��o Josephus faz a inicializa��o e inser��o dentro dela mesma */
	int v = Josephus(5, 2); //v recebe o retorno da fun��o
	printf("\nO elemento que sobrou foi: %d\n\n", v); //Imprime na tela o valor de v
	/*int w = Josephus(6, 3);
	printf("\nO elemento que sobrou foi: %d\n\n", w);
	int x = Josephus(7, 3);
	printf("\nO elemento que sobrou foi: %d\n\n", x);*/

	return 0; //Encerra o programa
}
