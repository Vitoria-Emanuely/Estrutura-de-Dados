/* Programa que declara vari�veis e ponteiros que apontam para essas var�aveis, modifica os valores 
delas atrav�s dos ponteiros e imprime as vari�veis antes e ap�s a medi��o */


/* Biblioteca */
#include <stdio.h>

/* Fun��o principal */
int main(void){
	
	/* Declara��o de vari�veis com suas tipagens e armazenamento de valores */
	int a = 5;
	float b = 3.2;
	char c = 'v';
	/* Declara��o de vari�veis (ponteiros) com suas tipagens e "apontamentos"/associa��es para os 
	endere�os de mem�ria das vari�veis a, b e c */
	/* ponteiro p1 aponta para o endere�o de mem�ria da vari�vel a */ 
	int *p1 = &a;
	/* ponteiro p2 aponta para o endere�o de mem�ria da vari�vel b */ 
	float *p2 = &b;
	/* ponteiro p3 aponta para o endere�o de mem�ria da vari�vel c */ 
	char *p3 = &c;
	
	/* Imprime os valores das vari�veis a, b e c antes da medi��o */
	printf("Valores das variaveis antes da medicao: a = %d, b = %f e c = %c \n", a, b, c);
	
	/* Altera��o do conte�do dos endere�os de mem�ria associados a cada ponteiro */
	/* ponteiro p1 aponta para a vari�vel a, altera o conte�do de a */
	*p1 = 3;
	/* ponteiro p2 aponta para a vari�vel b, altera o conte�do de b */
	*p2 = 15.3;
	/* ponteiro p3 aponta para a vari�vel c, altera o conte�do de c */
	*p3 = 'x';
	
	/* Imprime os valores das vari�veis a, b e c ap�s da medi��o */
	printf("Valores das variaveis apos da medicao: a = %d, b = %f e c = %c \n", a, b, c);

}
