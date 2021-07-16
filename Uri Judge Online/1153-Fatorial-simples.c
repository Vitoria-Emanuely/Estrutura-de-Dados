/* Programa que lê um valor inteiro N (0 < N < 13) e imprime seu fatorial */

#include <stdio.h>

/* Função fatorial que calcula o fatorial recursivamente */
int fatorial(int n){
	if (n == 0){ //Se n for igual a 0
		return 1; //Retorna 1
	}
	return n * fatorial(n - 1); //Retorna recursivamente a função para fazer o próximo fatorial
}

/* Função principal*/
int main(void){
	int n; //Declara variável n do tipo inteiro
	scanf("%d", &n); //Guarda o valor digitado no endereço de n
	if (n < 0 || n > 13){ //Se n for menor que 0 ou maior que 13 -> respeitando N (0 < N < 13)
		scanf("%d", &n); //Guarda o valor digitado no endereço de n
	}
	printf("%d\n", fatorial(n)); //Imprime na tela (onde faz a primeira chamada a função fatorial)
	return 0; //Encerra o programa
}
