//Exemplo Quick sort

#include <stdio.h>
#include <stdlib.h>

void quicksort(int vetor[], int comeco, int fim){
    int i, j, pivo, aux;
    i = comeco;
    j = fim-1;
    pivo = vetor[(comeco + fim) / 2];
    while(i <= j){
        while(vetor[i] < pivo && i < fim){
            i++;
        }
        while(vetor[j] > pivo && j > comeco){
            j--;
        }
        if(i <= j){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    if(j > comeco)
        quicksort(vetor, comeco, j+1);
    if(i < fim)
        quicksort(vetor, i, fim);
}

int main(){
    int v[] = {2, 5, 4, 1, 3};
    quicksort(v, 0, 5); 
    int i;
    for(i = 0; i < 5; i++)
        printf("%d ", v[i]);
    return 0;
}
