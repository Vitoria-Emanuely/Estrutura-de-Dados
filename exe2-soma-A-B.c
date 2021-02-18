/* Programa que faz a soma de dois números inteiros e salva na variável A */

/* Biblioteca */
#include <stdio.h>
void soma(int *A, int *B);

/* Função principal */ 
int main(void){
	/* Declaração de variáveis */
	int A, B;
	printf("Digite o valor de A: \n"); 
	fflush(stdin); /* Limpa o buffer do teclado */
	scanf("%d", &A); /* Guarda o valor digitado em A */ 
	printf("Digite o valor de B: \n");
	fflush(stdin);
	scanf("%d", &B); /* Guarda o valor digitado em B */ 
	soma(&A, &B); /* Passa os endereços de memória de A e B */ 
	printf("O valor de A seria %d e o valor de B seria %d \n", A, B);
	return 0;
}

/* Função que realiza a soma e armazena na variável A */
void soma(int *A, int *B){ 
	/* Declara a variável soma, realiza a soma dos conteúdos dos ponteiros A e B e guarda em soma */
	int soma = *A + *B;
 	*A = soma; /* Conteúdo do ponteiro A recebe o valor de soma */
}
