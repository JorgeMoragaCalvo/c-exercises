#include <stdio.h>

int dividend(int, int);
int remain(int, int);
int mulSum(int, int);
float mulSumFloat(float, int);
float decimals(int, int);


int main(){ 
    int a, b;
    printf("Ingrese el primer numero: ");
    scanf("%d", &a);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &b);
    printf("El resultado es: %.2f", dividend(a, b) + decimals(a, b));

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

float mulSumFloat(float a , int b){
    float result = 0.0;
    for(int i = 0; i < b; i++){
        result = result + a;
    }
    return result;
}

float decimals(int a, int b){
    float first_decimal = 0.1, decimal_number = 0.0;
    float second_decimal = 0.01, f = 0.0;

    if(dividend(a, b) == 0){
        int first_remainder = remain(a, b); //first_remainder = 1
        int first_rest = mulSum(first_remainder, 10); //first_rest = 10
        int first_rem = dividend(first_rest, b);
        decimal_number = mulSumFloat(first_decimal, first_rem);

        int c = remain(first_rest, b);
        int d = mulSum(c, 10);
        int e = dividend(d, b);
        f = mulSumFloat(second_decimal, e);
    } else {
        int first_remainder = remain(a, b); //first_remainder = 1
        int first_rest = mulSum(first_remainder, 10); //first_rest = 10
        int first_rem = dividend(first_rest, b);
        decimal_number = mulSumFloat(first_decimal, first_rem);

        int c = remain(first_rest, b);
        int d = mulSum(c, 10);
        int e = dividend(d, b);
        f = mulSumFloat(second_decimal, e);
    }

    return decimal_number + f;
}