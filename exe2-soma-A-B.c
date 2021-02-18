/* Programa que faz a soma de dois n�meros inteiros e salva na vari�vel A */

/* Biblioteca */
#include <stdio.h>
void soma(int *A, int *B);

/* Fun��o principal */ 
int main(void){
	/* Declara��o de vari�veis */
	int A, B;
	printf("Digite o valor de A: \n"); 
	fflush(stdin); /* Limpa o buffer do teclado */
	scanf("%d", &A); /* Guarda o valor digitado em A */ 
	printf("Digite o valor de B: \n");
	fflush(stdin);
	scanf("%d", &B); /* Guarda o valor digitado em B */ 
	soma(&A, &B); /* Passa os endere�os de mem�ria de A e B */ 
	printf("O valor de A seria %d e o valor de B seria %d \n", A, B);
	return 0;
}

/* Fun��o que realiza a soma e armazena na vari�vel A */
void soma(int *A, int *B){ 
	/* Declara a vari�vel soma, realiza a soma dos conte�dos dos ponteiros A e B e guarda em soma */
	int soma = *A + *B;
 	*A = soma; /* Conte�do do ponteiro A recebe o valor de soma */
}
