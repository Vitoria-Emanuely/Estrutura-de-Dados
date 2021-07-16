/*  Programa que calcula o número de competidores classificados para a próxima fase e a imprime. Foi utilizado o método de ordenação Insertion */

#include <stdio.h>

/* Função ordenacao que ordena o vetor v em ordem decrescente, imprimindo no final o número de competidores classificados */
void ordenacao(int v[], int n, int k){
    int i, j, chave; //Declara as variáveis i, j, chave do tipo inteiro
    int count = k; //Declara a variável count do tipo inteiro que recebeo valor de k (contador)
    for (i = 1; i < n; i++){ //Percorre o vetor
        chave = v[i]; //Variável chave recebe o valor de v na posição i
        j = i - 1; //Variável j recebe o valor de i - 1
        while (j >= 0 && v[j] < chave){ //Enquanto j for maior ou igual a 0 e v na posição j for menor que chave
            v[j + 1] = v[j]; //Variável v na posição j + 1 recebe o valor de v na posição j
            j = j - 1; //Variável j recebe o valor de j - 1
        }
        v[j + 1] = chave; //Variável v na posição j + 1 recebe o valor de chave
    }
    for (i = k; i < n; i++){ //Percorre o vetor partindo de v[k]
		if (v[k - 1] == v[i]){ //Se v na posição k - 1 for igual a v na posição i (se o valor anterior for igual ao atual)
			count ++; //Count adiciona + 1			
		}
	}
	printf("%d\n", count); //Imprime na tela
}

/* Função principal */
int main(void){	
	int n, i, k; //Declara as variáveis n, i, k do tipo inteiro
	scanf("%d", &n); //Guarda o valor digitado no endereço de n
	if (n < 1 || n > 1000){ //Se n for menor que 1 ou maior que 1000 -> respeitando N (1 <= N <= 1000)
		scanf("%d", &n); //Guarda o valor digitado no endereço de n
	}
	scanf("%d", &k); //Guarda o valor digitado no endereço de k
	if (k < 1 || k > n){ //Se k for menor que 1 ou maior que n -> respeitando K (1 <= K <= N)
		scanf("%d", &k); //Guarda o valor digitado no endereço de k
	}
	int v[n]; //Declara variável do vetor v do tipo inteiro
	for (i = 0; i < n; i++){ //Percorre o vetor 
		scanf("%d", &v[i]); //Guarda o valor digitado no endereço do vetor v na posição i 
		if (v[i] < 1 || v[i] > 1000){ //Se v na posição i for menor que 1 ou maior que 1000 -> respeitando N (1 <= N <= 1000)
			scanf("%d", &v[i]); //Guarda o valor digitado no endereço do vetor v na posição i
		}
	}
	ordenacao(v, n, k); //Chama a função ordenacao passando o vetor v, n e k
    return 0; //Encerra o programa
}
