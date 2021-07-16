//Exemplo Insertion Sort

#include <stdio.h>
void insertion_sort(int vetor[], int n){
	int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave){
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

int main(){
    int v[] = {5, 4, 2, 3};
    insertion_sort(v, 4); 
    return 0;
}
