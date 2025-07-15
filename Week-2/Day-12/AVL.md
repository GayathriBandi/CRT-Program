# 🌳 CRT Day 12 – AVL Tree Notes

## 🧠 What is an AVL Tree?
An **AVL Tree** is a type of **self-balancing Binary Search Tree (BST)** where the difference between heights of left and right subtrees (called the **balance factor**) for every node is **at most 1**.

Named after its inventors **Adelson-Velsky and Landis**, it's one of the earliest self-balancing trees.

---

## 📏 AVL Tree Properties

- It follows all BST properties.
- The **balance factor** of every node must be -1, 0, or +1.
- It ensures **O(log n)** time complexity for insertion, deletion, and search.

---

## 🧮 Balance Factor Formula

For any node `N`:

Balance Factor (BF) = Height(Left Subtree) - Height(Right Subtree)

### Allowed Balance Factor Values:

- `-1`: Right-heavy
- `0` : Perfectly balanced
- `+1`: Left-heavy

If BF is **outside** this range (`<-1` or `>1`), the tree needs to be **rotated** (rebalanced).

---

## 🔄 AVL Tree Rotations

### ✅ 4 Types of Rotations

1. **Single Right Rotation (LL Rotation)**
2. **Single Left Rotation (RR Rotation)**
3. **Left-Right Rotation (LR Rotation)**
4. **Right-Left Rotation (RL Rotation)**

---

### 🔁 1. LL Rotation (Right Rotation)

Occurs when a node is inserted into the **left subtree of the left child**.

/*
Before LL Rotation:

       z
      /
     y
    /
   x

After Right Rotate (LL Rotation):

       y
      / \
     x   z

Explanation:
- 'z' is unbalanced (left-heavy)
- 'y' is z's left child
- 'x' is y's left child
- Perform right rotation at 'z'
*/
✅ RR Rotation (Left Rotation)
/*
Before RR Rotation:

     z
      \
       y
        \
         x

After Left Rotate (RR Rotation):

       y
      / \
     z   x

Explanation:
- 'z' is unbalanced (right-heavy)
- 'y' is z's right child
- 'x' is y's right child
- Perform left rotation at 'z'
*/
✅ LR Rotation (Left Right Rotation)
/*
Before LR Rotation:

       z
      /
     x
      \
       y

Step 1: Left Rotate x
Step 2: Right Rotate z

After LR Rotation:

       y
      / \
     x   z

Explanation:
- 'z' is left-heavy
- But inserted into right of left child (x → y)
- So, perform left rotate on x, then right rotate on z
*/
✅ RL Rotation (Right Left Rotation)
/*
Before RL Rotation:

     z
      \
       x
      /
     y

Step 1: Right Rotate x
Step 2: Left Rotate z

After RL Rotation:

       y
      / \
     z   x

Explanation:
- 'z' is right-heavy
- But inserted into left of right child (x ← y)
- So, perform right rotate on x, then left rotate on z
*/

---

## 🌲 AVL Insertion Logic

1. Insert the node like in a BST.
2. Update the height of ancestors.
3. Check balance factor of each node.
4. If unbalanced, apply the correct rotation type.

---

## 💡 AVL Deletion Logic

1. Delete node like in BST.
2. Update heights going back to the root.
3. Check balance factor for imbalance.
4. Apply rotations as needed.

---

## 📐 Time Complexities

| Operation | Time Complexity |
|-----------|-----------------|
| Search    | O(log n)        |
| Insert    | O(log n)        |
| Delete    | O(log n)        |

---

## ✨ Why AVL Tree?

- Ensures **fast operations** due to strict balancing.
- Used where **lookups and updates are frequent**.
- Better than plain BSTs in worst-case scenarios.

---

## 📌 Example: Insert 50, 40, 60, 30, 45, 42

- Inserting 50, 40, 60: balanced.
- Insert 30 → Left-heavy → LL Rotation at 50
- Insert 45 → fine.
- Insert 42 → LR Rotation at 40.

Final Preorder Traversal: `45 40 30 42 50 60`

---
