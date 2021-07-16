#include <stdio.h>

int fib(int n, int *c){
    (*c)++;
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }else{
        return fib(n - 1, c) + fib(n - 2, c);
    }
}

int main(){
    int x, i, n, c;
    scanf("%d", &x);
    for (i = 0; i < x; i++){
        int c = 0;
        scanf("%d", &n);
        printf("fib(%d) = %d calls = %d\n", n, c - 1, fib(n, &c));
    }
    return 0;
}
