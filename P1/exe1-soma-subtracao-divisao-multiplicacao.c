/* Programa que l� dois n�meros e calcula as quatro opera��es b�sicas entre eles */

#include <stdio.h>
/* Fun��o que faz a adi��o entre os dois n�meros passados */
int adicao(int a, int b){
 	return a + b; //Retorna a adi��o entre o primeiro valor com o segundo valor
}

/* Fun��o que faz a subtra��o entre os dois n�meros passados */ 
int subtracao(int a, int b){
 	return a - b; //Retorna a subtra��o entre o primeiro valor com o segundo valor
}

/* Fun��o que faz a multiplica��o entre os dois n�meros passados */
int multiplicacao(int a, int b){
 	return a * b; //Retorna a multiplica��o entre o primeiro valor com o segundo valor
}

/* Fun��o que faz a divis�o entre os dois n�meros passados */
int divisao(int a, int b){
	return a / b; //Retorna a divis�o entre o primeiro valor com o segundo valor
}
 
/* Fun��o principal */ 
int main(void){
 	int a, b; //Declara as duas vari�veis do tipo inteiro que ir�o guardar os valores para as opera��es
 	printf("Digite o primeiro valor: \n"); //Imprime na tela
 	scanf("%d", &a); //Guarda o valor digitado no endere�o de a
 	fflush(stdin); //Limpa o buffer do teclado
	printf("Digite o segundo valor: \n"); //Imprime na tela
 	scanf("%d", &b); //Guarda o valor digitado no endere�o de b
 	/* Imprime na tela os valores de a, b e os returns de cada fun��o */
 	printf("\nResultados:\nAdicao: %d + %d = %d\nSubtracao: %d - %d = %d\nMultiplicacao: %d * %d = %d\nDivisao: %d / %d = %d\n", a, b, adicao(a, b), a, b, subtracao(a, b), a, b, multiplicacao(a, b), a, b, divisao(a, b));
  	
 	return 0; //Encerra o programa
}
