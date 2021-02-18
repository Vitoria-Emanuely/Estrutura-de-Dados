/*  Programa que recebe dois valores inteiros, calcula a soma e a subtra��o dos valores e imprime 
os resultados. */

#include <stdio.h>

/*Fun��o que faz a soma e a subtra��o dos valores passados */
void operacoes(int a, int b, int *s, int *p){
	*s = a + b; //Guarda resultado da soma no ponteiro
	*p = a - b; //Guarda resultado da subtra��o no ponteiro
}

int main(void){
	int a, b, soma, sub;
	printf("Digite dois valores que deseja fazer as operacoes: \n");
	scanf("%d %d", &a, &b);
	operacoes(a, b, &soma, &sub);
	printf("Resultado da soma: %d \nResultado da subtracao: %d \n", soma, sub); //Imprime resultados da soma e subtra��o
	return 0;
}
