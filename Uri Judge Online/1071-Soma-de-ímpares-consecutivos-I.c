#include <stdio.h>

int somaImpares(int x, int y);

int main(){
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    if (y < x){
        int z = y;
        y = x;
        x = z;
    }
    int soma = somaImpares(x + 1, y);
    printf("%d\n", soma);
    return 0;
}

int somaImpares(int x, int y){
    if (x < y){
        if (x % 2 == 1 || x % 2 == -1)
            return x + somaImpares(x + 1, y);
        else
            return somaImpares(x + 1, y);
    }   
    return 0;
}
