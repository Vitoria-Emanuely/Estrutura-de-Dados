/* Programa que imprime o valor da d�vida para cada motorista, o total de recursos arrecadados e o n�mero
da carteira do motorista que obteve o maior n�mero de multas. */

#include <stdio.h>

/* Fun��o que imprime a carteira com o maior n�mero de multas e o total de recursos arrecadados */
void imprime(float *r, int *m, int *j){
	printf("\nO maior numero de multas foi da carteira numero %d com %d multas \n", *j, *m);
	printf("O total de recursos arrecadados foi de: %2.f reais ", *r);
}

/* Fun��o que cadastra as informa��es de cada motorista e imprime o valor da d�vida de cada motorista */
int cadastra(int *m, float *r, int *c, int *j){
	int carteira, multas, i;
	float valor, total;
	/* Cadastra o n�mero da carteira */
	printf("Digite o numero da carteira do motorista: \nDigite 0 para sair\n"); 
	scanf("%d", &carteira);
	if (carteira == 0){ //Se a carteira for 0
		*c = 0;
		return 0; //Encerra ao ler a carteira de motorista de valor 0
	}
	/* Cadastra o n�mero total de multas */
	printf("Digite o numero total de multas do motorista: \n");
	scanf("%d", &multas);
	for (i = 0; i < multas; i++){
		printf("Digite o valor da multa %d: \n", i); //Cadastra o valor de cada multa
		scanf("%f", &valor);
		total += valor;
	}
	*r += total;
	printf("O valor total da divida das multas: %2.f reais \n\n", total); //Imprime valor total das multas
	total = 0;
	if (multas > *m){
		*m = multas;
		*j = carteira;
	}
}

int main(void){
	int n, j, m = 0, c = 1;
	float r;
	
	while (c != 0){
		cadastra(&m, &r, &c, &j);
	}
	imprime(&r, &m, &j);
	return 0;
}
