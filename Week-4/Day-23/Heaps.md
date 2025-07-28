# 📚  Day-23 Heaps

## 🔸 What is a Heap?
A **heap** is a special **binary tree** that satisfies the **heap property**:
- In a **Max-Heap**, for any node `i`, the value of `i` is **greater than or equal to** its children.
- In a **Min-Heap**, for any node `i`, the value of `i` is **less than or equal to** its children.

✅ It's a **complete binary tree**: all levels are completely filled except possibly the last, which is filled from left to right.

## 🔸 Types of Heaps
- **Max-Heap**: Root is the maximum element.
- **Min-Heap**: Root is the minimum element.

## 🔸 Applications of Heaps
- Priority Queues
- Heap Sort
- Dijkstra’s Shortest Path Algorithm
- Huffman Coding

## 🔸 Heap Representation
Heaps are commonly implemented using **arrays**.

For node at index `i`:
- Left Child  → `2 * i + 1`
- Right Child → `2 * i + 2`
- Parent      → `(i - 1) / 2`

## 🔸 Heapify Algorithm

### 📌 Definition:
**Heapify** is the process of converting a binary tree into a heap.

### ▶️ Max-Heapify Steps:
1. Check the left and right child of the node.
2. Find the largest among root, left child, and right child.
3. If root is not the largest, **swap** it with the largest and recursively heapify the affected subtree.

## 🔸 Example – Max-Heapify

### Initial Array:
```
Index:      0   1   2   3   4   5   6
Value:      10  20  15  30  40  50  100
```

### Binary Tree:
```
           10
         /    \
       20      15
      /  \    /  \
    30   40  50  100
```

Apply `heapify` at index 0:

- Current node = 10
- Left child = 20 (index 1)
- Right child = 15 (index 2)
- Largest = 20 → Swap 10 and 20

Now heapify index 1:

- Current node = 10
- Left = 30 (index 3), Right = 40 (index 4)
- Largest = 40 → Swap 10 and 40

Heapify index 4 — No children → Done

### Final Heap Tree:
```
           20
         /    \
       40      15
      /  \    /  \
    30   10  50  100
```

### Final Array:
```
[20, 40, 15, 30, 10, 50, 100]
```

## 🔸 Max-Heapify C Code
```c
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;           // Initialize largest as root
    int left = 2 * i + 1;      // left = 2*i + 1
    int right = 2 * i + 2;     // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);  // Recursively heapify the affected sub-tree
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 20, 15, 30, 40, 50, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildMaxHeap(arr, n);

    printf("Max-Heap array: ");
    printArray(arr, n);

    return 0;
}
```

## 🔸 Time & Space Complexity

| Operation      | Time Complexity |
|----------------|------------------|
| Build Heap     | O(n)             |
| Heapify        | O(log n)         |
| Insert         | O(log n)         |
| Delete         | O(log n)         |

- Space Complexity: **O(1)** (in-place using arrays)

---

