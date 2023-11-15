#include <stdio.h>

int factorial_recursivo(int);
int factorial_iterativo(int);

int main(){
    int num = 15;

    printf("Resultado Recursivo: %d\n", factorial_recursivo(num));
    //printf("Resultado Iterativo: %d\n", factorial_iterativo(num));
    return 0;
}

int factorial_recursivo(int num){
    if(num == 0) return 1;
    else return num * factorial_recursivo(num - 1);
}

int factorial_iterativo(int num){
    int fact = 1;
    for(int i = 1; i <= num; i++){
        fact = fact * i;
    }
    return fact;
}