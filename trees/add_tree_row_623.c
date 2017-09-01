#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* addOneRow(struct TreeNode* root, int v, int d) {
	if(root == NULL) return NULL;
	
	if(d-1 == 0){
		struct TreeNode* newNode = malloc(sizeof(struct TreeNode));
		
		newNode->val = v;
		newNode->left = root;
		newNode->right = NULL;
		
		return newNode;
	}

	if(d-1 != 1) {
		addOneRow(root->left, v, d-1);
		addOneRow(root->right, v, d-1);
	}
	else if(d-1 == 1) {
		struct TreeNode* newLNode = malloc(sizeof(struct TreeNode));
		struct TreeNode* newRNode = malloc(sizeof(struct TreeNode));
		
		newLNode->val = v;
		newLNode->left = root->left;
		newLNode->right = NULL;
		
		newRNode->val = v;
		newRNode->left = NULL;
		newRNode->right = root->right;

		root->left = newLNode;
		root->right = newRNode;
	} 

	return root;
}

int main() {
	struct TreeNode* res = malloc(sizeof(struct TreeNode)); 
	struct TreeNode* left_1 = malloc(sizeof(struct TreeNode));
	struct TreeNode* left_2 = malloc(sizeof(struct TreeNode)); 
	struct TreeNode* right_2 = malloc(sizeof(struct TreeNode)); 

	res->val = 4;
	left_1->val = 2;
	right_2->val = 1;
	left_2->val = 3;

	res->left = left_1;
	res->right = NULL;
	left_1->left = left_2;
	left_1->right = right_2;

	res = addOneRow(res, 1, 3);

	printf("%d\n", (((res->left)->right)->right)->val);

	return 0;
}
