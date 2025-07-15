# 🌲 Day 12 - Binary Search Tree (BST)

## 📚 Topics Covered:
- What is a BST?
- Insertion in BST (Recursive & Iterative)
- Constructing Unique BST from Postorder Traversal
- Code Examples & Visualizations

---

## 🔸 What is a Binary Search Tree?

A **Binary Search Tree (BST)** is a binary tree where:
- Left subtree of a node contains only nodes with **values less than the node’s key**.
- Right subtree of a node contains only nodes with **values greater than the node’s key**.
- No duplicate nodes allowed.

---

## 🌿 Example BST:

    8
   / \
  3   10
 / \    \
1   6    14
   / \   /
  4   7 13

---

## ✨ Insertion in BST

### 🔁 Iterative Approach

```c
struct TreeNode* insertIterative(struct TreeNode* root, int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;

    if (root == NULL) return newNode;

    struct TreeNode* parent = NULL;
    struct TreeNode* curr = root;

    while (curr != NULL) {
        parent = curr;
        if (val < curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (val < parent->val)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}
Recursive Approach
c
Copy
Edit
struct TreeNode* insertRecursive(struct TreeNode* root, int val) {
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (val < root->val)
        root->left = insertRecursive(root->left, val);
    else
        root->right = insertRecursive(root->right, val);

    return root;
}
🔄 Unique BST Construction from Postorder
🔸 Given Postorder Traversal:
csharp
Copy
Edit
[1, 7, 5, 50, 40, 10]
✅ Constructed BST:
markdown
Copy
Edit
        10
       /  \
      5    40
     / \     \
    1   7    50
💡 Logic:
Last element of postorder is the root.

Values less than root → Left subtree

Values greater than root → Right subtree

Recur on left and right parts of postorder array.

🔧 C Code to Build BST from Postorder
c
Copy
Edit
int idx;

struct TreeNode* constructBST(int* post, int min, int max) {
    if (idx < 0) return NULL;

    int val = post[idx];
    if (val < min || val > max)
        return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = root->right = NULL;

    idx--;

    root->right = constructBST(post, val, max);
    root->left = constructBST(post, min, val);

    return root;
}

struct TreeNode* buildBSTFromPostorder(int* postorder, int size) {
    idx = size - 1;
    return constructBST(postorder, INT_MIN, INT_MAX);
}
