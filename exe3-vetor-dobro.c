/* Programa que recebe valores para um vetor de 5 elementos e imprime na tela o dobro de cada valor lido */

/* Biblioteca */
#include <stdio.h>

/* Fun��o principal */ 
int main(void){
	int v[5]; /* Declara vetor com 5 elementos */
	int i; /* Vari�vel utilizada como �ndice do vetor */
	
	/* Leitura dos valores */
	for (i = 0; i < 5; i++){ /* Faz o �ndice ir de 0 a 5 */
		printf("Digite o numero do indice %d \n", i);
		scanf("%d", (v+i)); /* L� cada elemento do vetor */
	}
	
	printf("\nSegue abaixo o vetor: \n");
	/* Impress�o dos valores */
		for (i = 0; i < 5; i++){
		printf("%d \n", *(v+i) * 2);
	}
	return 0;
}

