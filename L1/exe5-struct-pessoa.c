/* Programa que l� o nome, a idade e o endere�o de uma pessoa e imprime esses dados. */

#include <stdio.h>

struct pessoa { //Guarda as interfaces da pessoa
	char nome[100], endereco[100];
    int idade;
};

int main(void){
	struct pessoa p;
	//Cadastra a pessoa (n�o utilizar espa�o entre as informa��es)
	printf("Informe o nome: \n");
	scanf("%s", &p.nome); 
	fflush(stdin);
	printf("Informe a idade: \n");
	scanf("%d", &p.idade);
	fflush(stdin);
	printf("Informe o endereco: \n");
	scanf("%s", &p.endereco); 
	//Imprime a pessoa
	printf("Nome: %s \nIdade: %d anos \nEndereco: %s \n", p.nome, p.idade, p.endereco);
	return 0;
}
