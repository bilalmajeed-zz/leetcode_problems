//Given an array of integers, every element appears twice except for one. Find that single one.

//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize) {
    int x = 0;
    for(int i = 0; i < numsSize; i++){
        x = x ^ nums[i];   
    }
    return x;
}

int main(){
    int numbers[] = {4,4,5,7,8,5,8};
    printf("%d\n", singleNumber(numbers, 7));
    return 0;
}
