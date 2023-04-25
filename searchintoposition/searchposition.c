#include <stdio.h>

int searchInsert(int *, int, int);

int main(){
    int nums[] = {1, 3, 5, 6}, target = 2;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Indice: %d", searchInsert(nums, numsSize, target));

    return 0;
}

int searchInsert(int *nums, int numsSize, int target){
    int index;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == target){
            index = i;
            return index;
        }
    }

    if(target > nums[numsSize]) return index = numsSize;

    for(int i = 0; i < numsSize; i++){
        if(target < nums[i]) return index = i;
    }
}