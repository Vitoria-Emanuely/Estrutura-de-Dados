/* Programa que lê dois números e calcula as quatro operações básicas entre eles */

#include <stdio.h>
/* Função que faz a adição entre os dois números passados */
int adicao(int a, int b){
 	return a + b; //Retorna a adição entre o primeiro valor com o segundo valor
}

/* Função que faz a subtração entre os dois números passados */ 
int subtracao(int a, int b){
 	return a - b; //Retorna a subtração entre o primeiro valor com o segundo valor
}

/* Função que faz a multiplicação entre os dois números passados */
int multiplicacao(int a, int b){
 	return a * b; //Retorna a multiplicação entre o primeiro valor com o segundo valor
}

/* Função que faz a divisão entre os dois números passados */
int divisao(int a, int b){
	return a / b; //Retorna a divisão entre o primeiro valor com o segundo valor
}
 
/* Função principal */ 
int main(void){
 	int a, b; //Declara as duas variáveis do tipo inteiro que irão guardar os valores para as operações
 	printf("Digite o primeiro valor: \n"); //Imprime na tela
 	scanf("%d", &a); //Guarda o valor digitado no endereço de a
 	fflush(stdin); //Limpa o buffer do teclado
	printf("Digite o segundo valor: \n"); //Imprime na tela
 	scanf("%d", &b); //Guarda o valor digitado no endereço de b
 	/* Imprime na tela os valores de a, b e os returns de cada função */
 	printf("\nResultados:\nAdicao: %d + %d = %d\nSubtracao: %d - %d = %d\nMultiplicacao: %d * %d = %d\nDivisao: %d / %d = %d\n", a, b, adicao(a, b), a, b, subtracao(a, b), a, b, multiplicacao(a, b), a, b, divisao(a, b));
  	
 	return 0; //Encerra o programa
}
