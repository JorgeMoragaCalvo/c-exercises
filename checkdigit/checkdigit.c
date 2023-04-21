#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
    PROGRAM THAT DETERMINES IF THE VERIFIER CODE OF THE NATIONAL IDENTITY NUMBER (RUT IN CHILE) IS TRUE
*/


/*PROTOTYPE FUNCTIONS*/
int function1(char *);
int digit(char *);
int checkDigit(int);

/*DRIVE CODE*/
int main(){
    char *str;
    int result;
    
    printf("\nIngrese su Rut SIN puntos y CON guion: ");
    scanf("%[^\n]s", str);

    //printf("Digito verificador: %d\n", digit(str));

    result = function1(str);
    printf("***********************************");
    if(digit(str) == 10 && checkDigit(result) == 10) printf("\nEl digito verificador es correcto\n");
    else if(digit(str) == 11 && checkDigit(result) == 11) printf("\nEl digito verificador es correcto\n");
    else if(digit(str) == checkDigit(result)) printf("\nEl digito verificador es correcto\n");
    else printf("\nEl digito verificador es incorrecto\n");
    printf("***********************************\n");
    return 0;
}

/*FUNCTIONS*/
int function1(char *str){
    int length = 0, i = 0, accum = 0, mul = 2;

    /*Ciclo que calcula la cantidad de digitos hasta el guion "-" */
    while(str[i] != '-'){
        length++;
        i++;
    }

    /*arreglo dinamico de largo = length*/
    char *arr = (char *)malloc(length * sizeof(char));
    i = length - 1;

    /*Ciclo que invierte el arreglo str guardandolo en el arreglo arr*/
    while(i >= 0){
        arr[length - 1 - i] = str[i];
        i--;
    }

    /*Arreglo dinamico de enteros de largo = length*/
    int *arrNum = (int *)malloc(length * sizeof(int));

    i = 0;
    /*Ciclo que transforma char a int*/
    for(i = 0; i < length; i++) arrNum[i] = arr[i] - '0';

    free(arr);

    /*Ciclo que realiza calculo arrNum[k] * 2, arrNum[k + 1] * 3...*/
    for(int k = 0; k < length; k++){
        accum += arrNum[k] * mul;
        if(mul == 7) mul = 1;
        mul++;
    }

    free(arrNum);
    return accum;
}

int checkDigit(int n){
    int digit;
    digit = 11 - (n - ((n / 11) * 11));
    return digit;
}

int digit(char *str){
    int length = strlen(str);
    char checkD = ' ';
    for(int i = 0; i < length; i++){
        if(str[i] == '-') checkD = str[i + 1];
    }

    if(checkD == 'k') return 10;
    else{
        int check = checkD - '0';
        if(check == 0) return 11;
        else return check;
    }
}
