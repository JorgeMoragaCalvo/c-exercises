#include <stdio.h>

void swap(int *, int *);
void bubbleRec(int *, int);
void printArray(int *, int);

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Array original: \n");
    printArray(arr, size);
    bubbleRec(arr, size);
    printf("Array ordenado: \n");
    printArray(arr, size);
    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleRec(int *arr, int size){
    if(size == 1) return;
    int count = 0;
    for(int i = 0; i < size - 1; i++){
        if(arr[i] > arr[i + 1]){
            swap(&arr[i], &arr[i + 1]);
            count++;
        }
    }
    if(count == 0) return;

    bubbleRec(arr, size - 1);
}

void printArray(int *arr, int size){
    for(int i = 0; i < size; i++) printf("%d - ", arr[i]);
    printf("\n");
}