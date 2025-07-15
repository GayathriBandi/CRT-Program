Given the root of a binary tree, return the postorder traversal of its nodes' values.
Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]
  
#include <stdio.h>
#include <stdlib.h>

void postorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;
    postorder(root->left, result, index);
    postorder(root->right, result, index);
    result[(*index)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;
    postorder(root, result, returnSize);
    return result;
}
