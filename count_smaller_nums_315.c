#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize) {
	*returnSize = numsSize;
	int* ans = (int* ) malloc(numsSize * sizeof(int));
	
	int count;
	for(int i = 0; i < numsSize; i++) {
		count = 0;
		for(int j = i+1; j < numsSize; j++) {
			if(nums[j] < nums[i]) {
				count++;
			}
		}
		ans[i] = count;
	}
	return ans;
}

int main() {
	int nums[] = {5,2,6,1,1};
	int* retSize = malloc(sizeof(int));
	*retSize = 0;
	int* res = countSmaller(nums, 5, retSize);

	for(int i = 0; i < 5; i++){
		printf("%d\n", res[i]);
	}
	free(res);
	return 0;
}