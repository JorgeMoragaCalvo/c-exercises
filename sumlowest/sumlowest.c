#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 40

/*Sum of two lowest positive integers*/

int sum_two_smalles_numbers(int, int[]);

int main(){
    srand(time(NULL));
    // int numbers[] = {46, 468, 292, 80, 669, 225, 666, 991, 689, 300, 777, 755, 855, 883, 697, 335, 595, 
    //     614, 640, 423, 120, 332, 534, 423, 894, 96, 258, 180, 344, 390, 124, 108};
    int numbers[LEN];

    for(int i = 0; i < LEN; i++){
        int r = rand() % 100;
        numbers[i] = r;
    }

    int length = sizeof(numbers) / sizeof(numbers[0]);
    printf("Largo: %d\n", length);

    for(int i = 0; i < length; i++) printf("%d - ", numbers[i]);
    
    printf("\nSuma menores: %d", sum_two_smalles_numbers(length, numbers));

    return 0;
}


int sum_two_smalles_numbers(int length, int numbers[]){
    int min1 = numbers[0], index = 0, min2, min3;

    /* looks for the smallest number */
    for(int i = 1; i < length; i++){
        if(min1 > numbers[i]){
            min1 = numbers[i];
            index = i;
        }
    }


    /* if index == 0 smallest number is the first number of array */
    if(index == 0){
        min2 = numbers[index + 1];
        for(int i = index + 2; i < length; i++){
            if(min2 > numbers[i]) min2 = numbers[i];
        }
    }

    /* Smallest number is the last of array */
    else if(index == length - 1){
        min2 = numbers[0];
        for(int i = 1; i < index; i++){
            if(min2 > numbers[i]) min2 = numbers[i];
        }
    }

    /* looks for small number from 0 to index and from index to final
       and then compares both numbers     
     */
    else {
        min2 = numbers[0];
        for(int i = 1; i < index; i++){
            if(min2 > numbers[i]) min2 = numbers[i];
        }

        min3 = numbers[index + 1];
        for(int i = index + 2; i < length; i++){
            if(min3 > numbers[i]) min3 = numbers[i];
        }

        if(min2 > min3) min2 = min3;
    }

    //return index;
    return min1 + min2;
}