#include <stdio.h>

float raiz(int n){
    if (n == 0){
        return 0;
    }else{
        return 1 / (2 + raiz(n - 1));
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%.10f\n", raiz(n) + 1.0);
    
    return 0;
}
