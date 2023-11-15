#include <stdio.h>
#include <limits.h>

int maxSubArraySum(int *, int);

int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("La maxima suma contigua es: %d", maxSubArraySum(arr, size));

    return 0;
}

int maxSubArraySum(int *arr, int size){
    int max_so_far = INT_MIN, max_ending_here = 0;
    for(int i = 0; i < size; i++){
        max_ending_here = max_ending_here + arr[i];
        if(max_so_far < max_ending_here) max_so_far = max_ending_here;
        if(max_ending_here < 0) max_ending_here = 0;
    }

    return max_so_far;
}