#include <stdio.h>
#include <stdlib.h> 

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* getSubTree(int* nums, int start, int end);

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) { 
	int max = 0;
	int max_index = 0;
	struct TreeNode* root = malloc(sizeof(struct TreeNode));

	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > max){
			max = nums[i];
			max_index = i;
		}
	}
	root->val = max;
	root->left = getSubTree(nums, 0, max_index);
	root->right = getSubTree(nums, max_index+1, numsSize);

	return root;
}

struct TreeNode* getSubTree(int* nums, int start, int end){
	if(start == end){
		return 0;
	}

	int m = 0;
	int m_i = 0; 
	for(int i = start; i < end; i++){
		if (nums[i] >= m){
			m = nums[i];
			m_i = i;
		}
	}
	struct TreeNode* res = malloc(sizeof(struct TreeNode));
	
	res->val = m;
	res->left = getSubTree(nums, start, m_i);
	res->right = getSubTree(nums, m_i+1, end);
	return res;
}

int main(){
	int input[] = {3,2,1,6,0,5};
	struct TreeNode* output = constructMaximumBinaryTree(input, 6);
	printf("%d\n", output->val);
	printf("%d\n", (output->left)->val);
	printf("%d\n", (output->right)->val);
	return 0;
}
