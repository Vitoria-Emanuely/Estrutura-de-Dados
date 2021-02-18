/* Programa que lê um número inteiro (entre 1 e 12) e escreve o mês correspondente. */

#include <stdio.h>

/* Função que lê um número inteiro e imprime o mês correspondente */
int mes(int n){
	int c; //Variável que define se o usuário quer sair do programa ou não
	if (n == 1){
		printf("Janeiro \n\n");
		return c = 1;
	}else if (n == 2){
		printf("Fevereiro \n\n");
		return c = 1;
	}else if (n == 3){
		printf("Marco \n\n");
		return c = 1;
	}else if (n == 4){
		printf("Abril \n\n");
		return c = 1;
	}else if (n == 5){
		printf("Maio \n\n");
		return c = 1;
	}else if (n == 6){
		printf("Junho \n\n");
		return c = 1;
	}else if (n == 7){
		printf("Julho \n\n");
		return c = 1;
	}else if (n == 8){
		printf("Agosto \n\n");
		return c = 1;
	}else if (n == 9){
		printf("Setembro \n\n");
		return c = 1;
	}else if (n == 10){
		printf("Outubro \n\n");
		return c = 1;
	}else if (n == 11){
		printf("Novembro \n\n");
		return c = 1;
	}else if (n == 12){
		printf("Dezembro \n\n");
		return c = 1;
	}else if (n == 0){ //Encerra o programa
		return c = 0;
	}else{
		printf("\nNao existe mes com esse numero. Digite novamente! \n");	
		return c = 1;								
	}							
}

int main(void){
	int n, c = 1;
	while (c != 0){ //Enquanto o usuário não pedir pra sair (0) poderá continuar digitando os meses
		printf("Digite o numero do mes que deseja que apareca de forma escrita: \n");
		printf("Para sair, digite 0 \n");
		scanf("%d", &n);
		c = mes(n);
	}
	return 0;
}
