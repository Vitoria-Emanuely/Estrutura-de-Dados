/*  Programa que l� um conjunto de 20 valores reais, armazena-os em um
vetor e os imprime ao contr�rio da ordem de leitura.*/

#include <stdio.h>

//Fun��o que faz a impress�o
void imprime(float *v){
	int i;
	for (i = 0; i < 20; i++){ //Percorre o vetor 
		printf("%.2f \n", v[19-i]); //Come�a em 19 pois o vetor armazena de 0 a 19 (20 elementos)
	}
}

int main(void){
	float v[20]; //Cria o vetor
	int i;
	for (i = 0; i < 20; i++){ //Percorre o vetor
		printf("Digite o valor a ser armazenado:\n");
		scanf("%f", &v[i]); //Guarda o valor digitado no vetor
	}
	printf("\n");
	imprime(v);
	
	return 0;
}
