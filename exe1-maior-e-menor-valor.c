/* Programa que l� dois valores inteiros e retorna na primeira vari�vel o maior valor passado e na segunda 
vari�vel o menor valor passado */

/* Biblioteca */
#include <stdio.h>
void troca(int *p1, int *p2);

/* Fun��o principal */ 
int main(void){
	/* Declara��o de vari�veis do tipo inteiro */
	int a, b;
	printf("Digite o valor da variavel a: \n");
	fflush(stdin); /* Limpa buffer do teclado */
	scanf("%d", &a); 
	printf("Digite o valor da variavel b: \n");
	fflush(stdin);
	scanf("%d", &b);
	/* Fun��o que faz a troca de valores de acordo com a condi��o (se � maior ou menor)*/
	troca(&a, &b); /* Passa os endere�os de mem�ria de a e b*/
	/* Printa na tela os valores de a e b */
	printf("O valor da primeira variavel seria %d e da segunda variavel seria %d \n", a, b);
	return 0;
}

/* Fun��o que realiza a troca de valores */
void troca(int *p1, int *p2){ 
	int temp; /* Declara a vari�vel do tipo inteiro */
	/* Se o conte�do do ponteiro p1 (primeira vari�vel) for maior que o conte�do do ponteiro p2 (segunda vari�vel) */
	if (*p1 > *p2){
		*p1 = *p1; /* O conte�do do ponteiro p1 recebe ele mesmo (n�o muda) */
	}else{ /* Se n�o */
		temp = *p2; /* temp guarda temporariamente o conte�do do ponteiro p2 */
		*p2 = *p1; /* O conte�do do ponteiro p2 recebe o conte�do do ponteiro p1 */
		*p1 = temp; /* O conte�do do ponteiro p1 recebe o valor de temp */
	}
}
