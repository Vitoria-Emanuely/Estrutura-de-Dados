/* Programa que repete a leitura de uma senha até que ela seja válida */

#include <stdio.h>

/* Função senha que verifica se a senha digitada é válida */
int senha(int s){
    if (s == 2002){ //Se s for igual a 2002 (senha válida)
        printf("Acesso Permitido\n"); //Imprime na tela
        return 0; //Encerra o algoritmo
    }
    printf("Senha Invalida\n"); //Imprime na tela
    scanf("%d", &s); //Guarda o valor digitado no endereço de s
    return senha(s); //Retorna recursivamente a função para repetir a leitura da senha até que seja válida (s == 2002)
}

/* Função principal */
int main(void){
    int s; //Declara variável s do tipo inteiro
    scanf("%d", &s); //Guarda o valor digitado no endereço de s
    senha(s); //Faz a primeira chamada para a função senha
    return 0; //Encerra o programa
}
