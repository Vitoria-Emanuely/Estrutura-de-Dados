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

/* Fun��es exportadas*/
//Fun��o cria: Aloca dinamicamente o n�mero de alunos para cadastramento
Aluno* cria(int n);

//Fun��o cadastra: Cadastra os dados dos alunos
void cadastra(Aluno *v, int qtd);

//Fun��o maiorNota_p1: Devolve o aluno com a maior nota da primeira prova e a nota respectiva
void maiorNota_p1(Aluno *v, int qtd);

//Fun��o maiorMedia: Devolve o aluno com a maior m�dia geral e a m�dia respectiva
void maiorMedia(Aluno *v, int qtd);

//Fun��o menorMedia: Devolve o aluno com a menor m�dia geral e a m�dia respectiva
void menorMedia(Aluno *v, int qtd);

//Fun��o aprovacao: Devolve se o aluno foi aprovado ou reprovado com suas respectivas notas e media
void aprovacao(Aluno *v, int qtd);

//Fun��o libera: Libera a mem�ria
void libera(Aluno *a);
