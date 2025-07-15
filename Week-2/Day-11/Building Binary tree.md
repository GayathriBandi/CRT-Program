# 🌳 Day 11 - Building Binary Tree from Inorder and Preorder

## 🔸 Topic: Construct Binary Tree

You are given the preorder and inorder traversal of a binary tree. Construct the binary tree and return its root.

### ✅ Constraints:
- All node values are unique.
- Input arrays will not contain duplicate values.

---

## 📥 Input:
- `preorder[] = {3, 9, 20, 15, 7}`
- `inorder[]  = {9, 3, 15, 20, 7}`

---

## 🔧 Algorithm:

1. The first element in the preorder is always the root.
2. Search the root in inorder — elements on the left are in the left subtree, right are in the right subtree.
3. Recursively build left and right subtrees.

---

## 💡 C Code Implementation

```c
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int search(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == val) return i;
    return -1;
}

struct TreeNode* buildTreeUtil(int* preorder, int* inorder, int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;

    int rootVal = preorder[*preIndex];
    (*preIndex)++;
    struct TreeNode* root = newNode(rootVal);

    if (inStart == inEnd) return root;

    int inIndex = search(inorder, inStart, inEnd, rootVal);

    root->left = buildTreeUtil(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTreeUtil(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preIndex = 0;
    return buildTreeUtil(preorder, inorder, 0, inorderSize - 1, &preIndex);
}

🌳 Binary Tree Visual Explanation:
Given:

Preorder: 3, 9, 20, 15, 7

Inorder: 9, 3, 15, 20, 7

Tree Construction:

        3
       / \
      9   20
          / \
         15  7
Preorder: Root first → 3

Inorder: Left of 3 is {9}, Right is {15, 20, 7}

🔚 Output:
The tree structure returned will be the correct BST as per input traversals. You can write a traversal function to print and verify.


