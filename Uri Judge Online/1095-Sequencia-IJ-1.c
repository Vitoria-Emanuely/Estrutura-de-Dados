#include <stdio.h>

void ij(int i, int j);

int main(){
    ij(1, 60);
    
    return 0;
}

void ij(int i, int j){
    if (j >= 0){
        printf("I=%d J=%d\n", i, j);
        ij(i + 3, j - 5);
    }   
}
