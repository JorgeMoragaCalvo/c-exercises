#include <stdio.h>

/*From LeetCode 
    The program return total number of elements not repeated
*/


/*FUNCTION PROTOTYPE*/
int removeElement(int *, int, int);


/*DRIVE CODE*/
int main(){
    int nums[] = {3, 2, 2, 5, 6, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 2;

    printf("%d\n", removeElement(nums, numsSize, val));
}


/*FUNCTION*/
int removeElement(int *nums, int numsSize, int val){
    int count = 0, temp;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != val){
            temp = nums[i];
            nums[i] = nums[count];
            nums[count] = temp;
            count++;
        }
    }
    return count;
}
