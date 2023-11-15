#include <stdio.h>

int dividend(int, int);
int remain(int, int);
int mulSum(int, int);
float firstDecimal(int, int);
float mulSumFloat(float, int);

int main(){ 
    int a, b;
    printf("Ingrese el primer numero: ");
    scanf("%d", &a);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &b);
    printf("El resultado es: %.2f", firstDecimal(a, b));

    return 0;
}

int mulSum(int a, int b){
    int sum = 0;
    for(int i = 0; i < b; i++){
        sum = sum + a;
    }
    return sum;
}

int dividend(int a, int b){
    int accu = 0;
    if(a < b) return accu;

    while(a >= b){
        a = a - b;
        accu++;
    }
    return accu;
}

int remain(int a, int b){
    while(a >= b) a = a - b;
    return a;
}

float firstDecimal(int a, int b){
    float first_decimal = 0.1;
    int first_remainder = remain(a, b); //first_remainder = 1
    int first_rest = mulSum(first_remainder, 10); //first_rest = 10
    int first_rem = dividend(first_rest, b);
    float decimal_number = mulSumFloat(first_decimal, first_rem);

    return decimal_number;
}

float mulSumFloat(float a , int b){
    float result = 0.0;
    for(int i = 0; i < b; i++){
        result = result + a;
    }
    return result;
}