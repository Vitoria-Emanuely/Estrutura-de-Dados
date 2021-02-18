/* Programa que lê um valor inteiro n, aloca um vetor dinamicamente de n posições, preenche esse vetor e o 
imprime na tela */

#include <stdio.h>
#include <stdlib.h> //Lib que permite usar o malloc

/* Função principal */
int main(void){
	int n, i, *v; //Declara as variáveis do tipo inteiro (n guardará o valor digitado, i será auxiliar no for e *v será o ponteiro do vetor) 
	printf("Digite um valor inteiro: \n"); //Imprime na tela
	scanf("%d", &n); //Guarda o valor digitado no endereço de n
	while (n < 1){ //Solicita outro valor inteiro enquanto for menor que 1 (negativo)
		printf("Digite um valor inteiro: \n"); //Imprime na tela
		scanf("%d", &n); //Guarda o valor digitado no endereço de n
	}
	/*Ao sair do while, sendo n positivo (n >= 1) */
	v = (int*)malloc(n*sizeof(int)); //Aloca dinamicamente de acordo com n o vetor v
	
	/* Guarda os valores passados no vetor v */
	for (i = 0; i < n; i++){
		printf("Digite um valor para a posicao %d: \n", i); //Imprime na tela
		scanf("%d", &v[i]); //Guarda o valor digitado no endereço de v na posição i
	}
	
	/* Imprime o vetor v */
	for (i = 0; i < n; i++){
		printf("\nv[%d] = %d\n", i, v[i]); //Imprime o vetor
	}
	
	free(v); //Libera o vetor
	
	return 0; //Encerra o programa
}
