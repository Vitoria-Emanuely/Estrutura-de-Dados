/* Programa que lê dois valores inteiros e retorna na primeira variável o maior valor passado e na segunda 
variável o menor valor passado */

/* Biblioteca */
#include <stdio.h>
void troca(int *p1, int *p2);

/* Função principal */ 
int main(void){
	/* Declaração de variáveis do tipo inteiro */
	int a, b;
	printf("Digite o valor da variavel a: \n");
	fflush(stdin); /* Limpa buffer do teclado */
	scanf("%d", &a); 
	printf("Digite o valor da variavel b: \n");
	fflush(stdin);
	scanf("%d", &b);
	/* Função que faz a troca de valores de acordo com a condição (se é maior ou menor)*/
	troca(&a, &b); /* Passa os endereços de memória de a e b*/
	/* Printa na tela os valores de a e b */
	printf("O valor da primeira variavel seria %d e da segunda variavel seria %d \n", a, b);
	return 0;
}

/* Função que realiza a troca de valores */
void troca(int *p1, int *p2){ 
	int temp; /* Declara a variável do tipo inteiro */
	/* Se o conteúdo do ponteiro p1 (primeira variável) for maior que o conteúdo do ponteiro p2 (segunda variável) */
	if (*p1 > *p2){
		*p1 = *p1; /* O conteúdo do ponteiro p1 recebe ele mesmo (não muda) */
	}else{ /* Se não */
		temp = *p2; /* temp guarda temporariamente o conteúdo do ponteiro p2 */
		*p2 = *p1; /* O conteúdo do ponteiro p2 recebe o conteúdo do ponteiro p1 */
		*p1 = temp; /* O conteúdo do ponteiro p1 recebe o valor de temp */
	}
}
