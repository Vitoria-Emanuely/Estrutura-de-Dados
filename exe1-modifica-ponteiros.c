/* Programa que declara variáveis e ponteiros que apontam para essas varíaveis, modifica os valores 
delas através dos ponteiros e imprime as variáveis antes e após a medição */


/* Biblioteca */
#include <stdio.h>

/* Função principal */
int main(void){
	
	/* Declaração de variáveis com suas tipagens e armazenamento de valores */
	int a = 5;
	float b = 3.2;
	char c = 'v';
	/* Declaração de variáveis (ponteiros) com suas tipagens e "apontamentos"/associações para os 
	endereços de memória das variáveis a, b e c */
	/* ponteiro p1 aponta para o endereço de memória da variável a */ 
	int *p1 = &a;
	/* ponteiro p2 aponta para o endereço de memória da variável b */ 
	float *p2 = &b;
	/* ponteiro p3 aponta para o endereço de memória da variável c */ 
	char *p3 = &c;
	
	/* Imprime os valores das variáveis a, b e c antes da medição */
	printf("Valores das variaveis antes da medicao: a = %d, b = %f e c = %c \n", a, b, c);
	
	/* Alteração do conteúdo dos endereços de memória associados a cada ponteiro */
	/* ponteiro p1 aponta para a variável a, altera o conteúdo de a */
	*p1 = 3;
	/* ponteiro p2 aponta para a variável b, altera o conteúdo de b */
	*p2 = 15.3;
	/* ponteiro p3 aponta para a variável c, altera o conteúdo de c */
	*p3 = 'x';
	
	/* Imprime os valores das variáveis a, b e c após da medição */
	printf("Valores das variaveis apos da medicao: a = %d, b = %f e c = %c \n", a, b, c);

}
