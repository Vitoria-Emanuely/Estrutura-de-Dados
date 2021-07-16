/* Programa que l� um valor inteiro N (0 < N < 13) e imprime seu fatorial */

#include <stdio.h>

/* Fun��o fatorial que calcula o fatorial recursivamente */
int fatorial(int n){
	if (n == 0){ //Se n for igual a 0
		return 1; //Retorna 1
	}
	return n * fatorial(n - 1); //Retorna recursivamente a fun��o para fazer o pr�ximo fatorial
}

/* Fun��o principal*/
int main(void){
	int n; //Declara vari�vel n do tipo inteiro
	scanf("%d", &n); //Guarda o valor digitado no endere�o de n
	if (n < 0 || n > 13){ //Se n for menor que 0 ou maior que 13 -> respeitando N (0 < N < 13)
		scanf("%d", &n); //Guarda o valor digitado no endere�o de n
	}
	printf("%d\n", fatorial(n)); //Imprime na tela (onde faz a primeira chamada a fun��o fatorial)
	return 0; //Encerra o programa
}
