# 📘 CRT Program – Day 10: Non-Linear Data Structures & Trees

## 🧮 Why Not Just Linear Structures?

**Limitations of Linear Data Structures:**
- Inefficient for representing **hierarchical relationships**
- Poor performance in searching and sorting in large data sets (e.g., O(n) for arrays)
- Difficult to model complex relationships like **social networks**, **maps**, etc.

---

## 🌳 Why Use Non-Linear Data Structures?

**Non-linear structures** provide:
- Better representation for hierarchical and complex relationships
- Optimized searching, insertion, and deletion in many use cases
- Used in real-life applications like **file systems**, **game trees**, **network routing**, etc.

---

## 🧠 Types of Non-Linear Data Structures

### 1. **Trees**
- Hierarchical structure with nodes
- One root, multiple children

**Applications:**
- File systems
- Decision trees in AI
- Expression trees in compilers

---

### 2. **Graphs**
- Set of nodes (vertices) and edges
- Can be **directed** or **undirected**

**Applications:**
- Maps and GPS
- Social networks
- Dependency resolution

---

### 3. **Heaps**
- Special kind of tree-based DS
- Used to maintain priority queues

**Applications:**
- Heap sort
- Scheduling processes in OS

---

### 4. **Hash Tables**
- Key-value pair storage
- Offers average-case **O(1)** access time

**Applications:**
- Caching
- Symbol tables in compilers
- Dictionary implementations

---

## 🌴 In-Depth: Trees

### 🔸 Tree Terminology

- **Root**: Top-most node in the tree
- **Leaf**: Node with no children
- **Height**: Longest path from a node to a leaf
- **Depth**: Distance from root to a node

### 🧩 Example Tree:

        A
       / \
      B   C
     / \    \
    D   E    F


- Root: A  
- Leaf nodes: D, E, F  
- Height of tree: 2 (longest path: A → C → F)  
- Depth of E: 2

### 👪 Relationships:
- **Parent**: B is parent of D & E  
- **Sibling**: D and E are siblings  
- **Uncle**: C is uncle of D  
- **Ancestor**: A is ancestor of every node

---

## 🔄 Storing Undirected Trees

### 🔹 Using Adjacency List
```c
int tree[MAX][MAX];
🔹 Pros:
- Efficient space for sparse trees
- Easy traversal with DFS/BFS

🔹 Cons:
- More overhead for tree-specific queries
- Harder to manage if structure changes dynamically

🌿 Binary Trees
A binary tree is a tree in which each node has at most two children.

Parts of Binary Tree:
- Root: First node
- Internal Node: A node with at least one child
- Leaf Node: Node with no children

🌲 Types of Binary Trees

1. **Full (Strict) Binary Tree**
   - Every node has either 0 or 2 children

2. **Complete Binary Tree**
   - All levels are completely filled except the last
   - Last level nodes are as far left as possible

3. **Perfect Binary Tree**
   - All internal nodes have two children and all leaf nodes are at the same level

4. **Balanced Binary Tree**
   - Height is kept minimal (e.g., AVL, Red-Black Tree)

🚶 Binary Tree Traversals

1. **Inorder Traversal (LNR)**  
Left → Node → Right  
Example:

void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

Preorder Traversal (NLR)
Node → Left → Right
Example:

void preorder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}
Postorder Traversal (LRN)
Left → Right → Node
Example:
void postorder(struct TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->val);
    }
}
Level Order (Breadth First Search)
Visit nodes level by level using a queue.

void levelOrder(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* curr = queue[front++];
        printf("%d ", curr->val);

        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }
}

