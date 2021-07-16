/*  Programa que calcula o n�mero de competidores classificados para a pr�xima fase e a imprime. Foi utilizado o m�todo de ordena��o Insertion */

#include <stdio.h>

/* Fun��o ordenacao que ordena o vetor v em ordem decrescente, imprimindo no final o n�mero de competidores classificados */
void ordenacao(int v[], int n, int k){
    int i, j, chave; //Declara as vari�veis i, j, chave do tipo inteiro
    int count = k; //Declara a vari�vel count do tipo inteiro que recebeo valor de k (contador)
    for (i = 1; i < n; i++){ //Percorre o vetor
        chave = v[i]; //Vari�vel chave recebe o valor de v na posi��o i
        j = i - 1; //Vari�vel j recebe o valor de i - 1
        while (j >= 0 && v[j] < chave){ //Enquanto j for maior ou igual a 0 e v na posi��o j for menor que chave
            v[j + 1] = v[j]; //Vari�vel v na posi��o j + 1 recebe o valor de v na posi��o j
            j = j - 1; //Vari�vel j recebe o valor de j - 1
        }
        v[j + 1] = chave; //Vari�vel v na posi��o j + 1 recebe o valor de chave
    }
    for (i = k; i < n; i++){ //Percorre o vetor partindo de v[k]
		if (v[k - 1] == v[i]){ //Se v na posi��o k - 1 for igual a v na posi��o i (se o valor anterior for igual ao atual)
			count ++; //Count adiciona + 1			
		}
	}
	printf("%d\n", count); //Imprime na tela
}

/* Fun��o principal */
int main(void){	
	int n, i, k; //Declara as vari�veis n, i, k do tipo inteiro
	scanf("%d", &n); //Guarda o valor digitado no endere�o de n
	if (n < 1 || n > 1000){ //Se n for menor que 1 ou maior que 1000 -> respeitando N (1 <= N <= 1000)
		scanf("%d", &n); //Guarda o valor digitado no endere�o de n
	}
	scanf("%d", &k); //Guarda o valor digitado no endere�o de k
	if (k < 1 || k > n){ //Se k for menor que 1 ou maior que n -> respeitando K (1 <= K <= N)
		scanf("%d", &k); //Guarda o valor digitado no endere�o de k
	}
	int v[n]; //Declara vari�vel do vetor v do tipo inteiro
	for (i = 0; i < n; i++){ //Percorre o vetor 
		scanf("%d", &v[i]); //Guarda o valor digitado no endere�o do vetor v na posi��o i 
		if (v[i] < 1 || v[i] > 1000){ //Se v na posi��o i for menor que 1 ou maior que 1000 -> respeitando N (1 <= N <= 1000)
			scanf("%d", &v[i]); //Guarda o valor digitado no endere�o do vetor v na posi��o i
		}
	}
	ordenacao(v, n, k); //Chama a fun��o ordenacao passando o vetor v, n e k
    return 0; //Encerra o programa
}
