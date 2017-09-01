#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// SOLUTION 1 - my solution, straight forward, O(n^2) time
int* singleNumber1(int* nums, int numsSize, int* returnSize) {
	int* res = (int *) malloc(sizeof(int) * numsSize);

	// int foo = 0;
	int count;
	int index = 0;

	for(int i = 0; i < numsSize; i++) {
		// foo ^= nums[i];

		count = 0;

		for(int j = 0; j < numsSize; j++) {
			if (nums[i] == nums[j] && i != j) {
				count = 1;
				break;
			}
		}

		if (count != 1) {
			res[index] = nums[i];
			index++;
		}
	}
	*returnSize = index;
	return res;
}

//SOLTION 2 - bit manipulations solution, O(n) time
int* singleNumber2(int* nums, int numsSize, int* returnSize) {
	int* res = (int *) malloc(sizeof(int) * numsSize);

	//XOR all the elements, at the end you would be left with 
	//the 2 numbers xored to eachother, and we just have to seperate them
	int foo = 0;
	for(int i = 0; i < numsSize; i++) {
		foo ^= nums[i];
	}

	//get the posistion of the last one
	int x = foo & ~(foo - 1);

	//get one of the numbers in foo which has the bit in it
	int bar = 0;
	for(int i = 0; i < numsSize; i++) {
		if(nums[i] & x) {
			bar ^= nums[i];
		}
	}

	res[0] = bar;
	res[1] = foo ^ bar; //get the other number
	*returnSize = 2;
	return res;
}

int main() {
	int input[] = {1,2,1,3,2,5};
	int* rS = (int*) malloc(sizeof(int));
	int* output = singleNumber2(input, 6, rS);

	for(int i = 0; i < *rS; i++) {
		printf("%d\n", output[i]);
	}
}