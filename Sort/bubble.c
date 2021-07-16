//Exemplo Bubble sort

#include <stdio.h>
void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main(){
    
    int v[] = {5, 4, 2, 3};
    bubble_sort(v, 4); 
    return 0;
}
