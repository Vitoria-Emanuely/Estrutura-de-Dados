/* Programa que lê o nome, a idade e o endereço de uma pessoa e imprime esses dados. */

#include <stdio.h>

struct pessoa { //Guarda as interfaces da pessoa
	char nome[100], endereco[100];
    int idade;
};

int main(void){
	struct pessoa p;
	//Cadastra a pessoa (não utilizar espaço entre as informações)
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
