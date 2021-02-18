/*1. Programa que retorna o maior valor de três números digitados */
 
 #include <stdio.h>
 float maior(float a, float b, float c);
 
 int main(void){
 	float d, e, f;
 	printf("Digite tres numeros para saber o maior entre eles \n");
 	printf("Digite o primeiro numero para comparacao: \n");
 	scanf("%f", &d);
 	printf("Digite o segundo numero para comparacao: \n");
 	scanf("%f", &e);
 	printf("Digite o ultimo numero para comparacao: \n");
 	scanf("%f", &f);
 	printf("O maior numero = %f\n", maior(d, e, f));
 	return 0;
 }
 
 float maior(float a, float b, float c){
 	float maior;
 	if (a >= b && a >= c)
 		maior = a;
 	else if (b >= a && b >= c)
	 	maior = b;
	else
		maior = c;
	return maior;		 	
 }
