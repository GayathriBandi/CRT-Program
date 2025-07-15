Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]
#include <stdlib.h>

void preorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;
    result[(*index)++] = root->val;
    preorder(root->left, result, index);
    preorder(root->right, result, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;
    preorder(root, result, returnSize);
    return result;
}
