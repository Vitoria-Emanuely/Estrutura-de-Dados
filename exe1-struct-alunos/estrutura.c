#include "estrutura.h" //Inclui cabeçalho para usar as funções propostas no arquivo

/* Aloca dinamicamente o número de alunos no vetor a */
Aluno* cria(int n){
	Aluno *a = (Aluno*)malloc(n * sizeof(Aluno));
	if (a == NULL){
		printf("Memoria insuficiente \n");
		exit(1);
	}
	return a;
}

/* Cadastra os dados dos alunos no vetor */
void cadastra(Aluno *v, int qtd){
	int i;
	for (i = 0; i < qtd; i++){
		printf("\nInforme a matricula do aluno %d: \n", i);
		scanf("%s", &v[i].matricula);
		printf("Informe o nome do aluno %d: \n", i);
		scanf("%s", &v[i].nome);
		fflush(stdin);
		printf("Informe a nota da primeira prova do aluno %d: \n", i);
		scanf("%f", &v[i].nota_p1);
		fflush(stdin);
		printf("Informe a nota da segunda prova do aluno %d: \n", i);
		scanf("%f", &v[i].nota_p2);
		fflush(stdin);
		printf("Informe a nota da terceira prova do aluno %d: \n", i);
		scanf("%f", &v[i].nota_p3);
	}
}

 /* Imprime o nome do aluno com a maior nota da primeira prova e a nota respectiva */ 
void maiorNota_p1(Aluno *v, int qtd){
	int i, c;
	if (qtd > 1){ //Se for cadastrado mais de um aluno
		for (i = 0; i < (qtd - 1); i++){
		if (v[i].nota_p1 > v[i + 1].nota_p1){ //Se a nota da p1 do aluno atual for maior que a do próximo aluno
				c = i; //Guarda a posição em c
			}else{ //Se a nota da p1 do aluno atual for menor que a do próximo aluno
			c = i + 1; //Guarda a posição em c (do próximo)
			}
		}
	}else{
		c = 0; //Se for cadastrado somente um, automaticamente ele possui a maior nota
	}
	printf("\nAluno com a maior nota da primeira prova: %s, com a nota %.2f \n", v[c].nome, v[c].nota_p1);
	
}

/* Imprime o nome do aluno com a maior média geral e a média respectiva */
void maiorMedia(Aluno *v, int qtd){
	int i, c;
	float media;
	if (qtd > 1){ //Se for cadastrado mais de um aluno
		for (i = 0; i < (qtd - 1); i++){
			/* Se a média (soma das 3 provas dividido por 3) do aluno atual for maior que a do próximo aluno */
			if ((v[i].nota_p1 + v[i].nota_p2 + v[i].nota_p3) / 3 > (v[i + 1].nota_p1 + v[i + 1].nota_p2 + v[i + 1].nota_p3) / 3){
				c = i; //Guarda a posição em c
				media = ((v[i].nota_p1 + v[i].nota_p2 + v[i].nota_p3) / 3); //Guarda a media
			}else{ //Se a média do aluno atual for menor que a do próximo aluno
			c = i + 1; //Guarda a posição em c (do próximo)
			media = ((v[i + 1].nota_p1 + v[i + 1].nota_p2 + v[i + 1].nota_p3) / 3);
			}
		}
	}else{
		c = 0; //Se for cadastrado somente um, automaticamente ele possui a maior média
		media = ((v[c].nota_p1 + v[c].nota_p2 + v[c].nota_p3) / 3); //Guarda a media
	}
	printf("\nAluno com a maior media geral: %s, com a media de %.2f \n", v[c].nome, media);
}

/* Imprime o nome do aluno com a menor média geral e a média respectiva */
void menorMedia(Aluno *v, int qtd){
	int i, c;
	float media;
	if (qtd > 1){ //Se for cadastrado mais de um aluno
		for (i = 0; i < (qtd - 1); i++){
			/* Se a média (soma das 3 provas dividido por 3) do aluno atual for menor que a do próximo aluno */
			if ((v[i].nota_p1 + v[i].nota_p2 + v[i].nota_p3) / 3 < (v[i + 1].nota_p1 + v[i + 1].nota_p2 + v[i + 1].nota_p3) / 3){
				c = i; //Guarda a posição em c
				media = ((v[i].nota_p1 + v[i].nota_p2 + v[i].nota_p3) / 3); //Guarda a media
			}else{ //Se a média do aluno atual for maior que a do próximo aluno
			c = i + 1; //Guarda a posição em c (do próximo)
			media = ((v[i + 1].nota_p1 + v[i + 1].nota_p2 + v[i + 1].nota_p3) / 3); //Guarda a media
			}
		}
	}else{
		c = 0; //Se for cadastrado somente um, automaticamente ele possui a menor média
		media = ((v[c].nota_p1 + v[c].nota_p2 + v[c].nota_p3) / 3); //Guarda a media
	}
	printf("\nAluno com a menor media geral: %s, com a media de %.2f \n", v[c].nome, media);
}

/* Imprime se o aluno foi aprovado ou reprovado com suas respectivas notas e média */
void aprovacao(Aluno *v, int qtd){
	int i;
	float media;
	for (i = 0; i < qtd; i++){
		/* Se a média (soma das 3 provas dividido por 3) for maior ou igual a 6 (critério de aprovação) */
		if ((v[i].nota_p1 + v[i].nota_p2 + v[i].nota_p3) / 3 >= 6){
			media = ((v[i].nota_p1 + v[i].nota_p2 + v[i].nota_p3) / 3); //Guarda a media
			printf("\nO aluno %s foi APROVADO, com as seguintes notas: \n Primeira prova: %.2f \n Segunda prova: %.2f \n Terceira prova: %.2f \n Com uma media de: %.2f \n", v[i].nome, v[i].nota_p1, v[i].nota_p2, v[i].nota_p3, media);
		}else{ //Se a média (soma das 3 provas dividido por 3) for menor a 6 (é reprovado)
			media = ((v[i].nota_p1 + v[i].nota_p2 + v[i].nota_p3) / 3); //Guarda a media
			printf("\nO aluno %s foi REPROVADO, com as seguintes notas: \n Primeira prova: %.2f \n Segunda prova: %.2f \n Terceira prova: %.2f \n Com uma media de: %.2f \n", v[i].nome, v[i].nota_p1, v[i].nota_p2, v[i].nota_p3, media);
		}
	}
}
 /* Libera a memória do vetor */
void libera(Aluno *a){
	free(a);
	printf("\nMemoria liberada com sucesso \n");
}

