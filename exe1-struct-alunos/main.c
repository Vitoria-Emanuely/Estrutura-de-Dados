#include "estrutura.h" //Inclui cabeçalho para utilizar as funções do módulo 

int main(void){
	int qtd, r = 1;
	printf("Bem vindo(a) ao cadastro e consulta de alunos \nQuantos alunos deseja cadastrar? \n");
	scanf("%d", &qtd);
	Aluno *v = cria(qtd); //Cria o vetor
	cadastra(v, qtd); //Cadastra os dados no vetor
	
	/* Menu simples com suas respectivas utilidades */
	while (r != 0){
		printf("\n\nAs opcoes sao as seguintes: \n 1. Encontre o aluno com a maior nota da primeira prova; \n 2. Encontre o aluno com a maior media geral; \n 3. Encontre o aluno com a menor media geral; \n 4. Visualize os alunos que foram aprovados e reprovados com suas respectivas notas; \n 5. Sair. \n ");
		scanf("%d", &r);
		if (r == 1){
			maiorNota_p1(v, qtd);
		}
		if (r == 2){
			maiorMedia(v, qtd);
		}
		if (r == 3){
			menorMedia(v, qtd);
		}
		if (r == 4){
			aprovacao(v, qtd);
		}
		if (r == 5){
			libera(v);
			r = 0;
		}
	}
	
	return 0;
}
