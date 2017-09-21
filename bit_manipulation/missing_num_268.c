#include <stdio.h>
#include <stdlib.h>

int missingNumber(int* nums, int numsSize) {
	int total = (numsSize + 1)*(numsSize*1.0/2); 
	int partial_sum = 0;
	for(int i = 0; i < numsSize; i++){
		partial_sum += nums[i];
	}
	return total - partial_sum;
}

int main() {
	int input[] = {1,5,3,2,0};
	printf("%d\n", missingNumber(input, 5));
}