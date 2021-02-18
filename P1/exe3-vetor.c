/* Programa que l� um valor inteiro n, aloca um vetor dinamicamente de n posi��es, preenche esse vetor e o 
imprime na tela */

#include <stdio.h>
#include <stdlib.h> //Lib que permite usar o malloc

/* Fun��o principal */
int main(void){
	int n, i, *v; //Declara as vari�veis do tipo inteiro (n guardar� o valor digitado, i ser� auxiliar no for e *v ser� o ponteiro do vetor) 
	printf("Digite um valor inteiro: \n"); //Imprime na tela
	scanf("%d", &n); //Guarda o valor digitado no endere�o de n
	while (n < 1){ //Solicita outro valor inteiro enquanto for menor que 1 (negativo)
		printf("Digite um valor inteiro: \n"); //Imprime na tela
		scanf("%d", &n); //Guarda o valor digitado no endere�o de n
	}
	/*Ao sair do while, sendo n positivo (n >= 1) */
	v = (int*)malloc(n*sizeof(int)); //Aloca dinamicamente de acordo com n o vetor v
	
	/* Guarda os valores passados no vetor v */
	for (i = 0; i < n; i++){
		printf("Digite um valor para a posicao %d: \n", i); //Imprime na tela
		scanf("%d", &v[i]); //Guarda o valor digitado no endere�o de v na posi��o i
	}
	
	/* Imprime o vetor v */
	for (i = 0; i < n; i++){
		printf("\nv[%d] = %d\n", i, v[i]); //Imprime o vetor
	}
	
	free(v); //Libera o vetor
	
	return 0; //Encerra o programa
}
