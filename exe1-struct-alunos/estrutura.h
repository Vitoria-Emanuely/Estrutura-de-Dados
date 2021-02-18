#include <stdlib.h>
#include <stdio.h>

/* TAD: Aluno (matricula, nome, nota_p1, nota_p2, nota_p3 */
struct aluno{ //Guarda as interfaces do aluno
	int matricula;
	char nome[100];
	float nota_p1, nota_p2, nota_p3;
};

/* Tipo exportado*/
typedef struct aluno Aluno;

/* Funções exportadas*/
//Função cria: Aloca dinamicamente o número de alunos para cadastramento
Aluno* cria(int n);

//Função cadastra: Cadastra os dados dos alunos
void cadastra(Aluno *v, int qtd);

//Função maiorNota_p1: Devolve o aluno com a maior nota da primeira prova e a nota respectiva
void maiorNota_p1(Aluno *v, int qtd);

//Função maiorMedia: Devolve o aluno com a maior média geral e a média respectiva
void maiorMedia(Aluno *v, int qtd);

//Função menorMedia: Devolve o aluno com a menor média geral e a média respectiva
void menorMedia(Aluno *v, int qtd);

//Função aprovacao: Devolve se o aluno foi aprovado ou reprovado com suas respectivas notas e media
void aprovacao(Aluno *v, int qtd);

//Função libera: Libera a memória
void libera(Aluno *a);
