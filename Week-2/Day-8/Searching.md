# 📘 Day 8 - Searching (CRT Program)

In today's CRT session, we covered **Searching Algorithms** – particularly **Linear Search** and **Binary Search**.

---

## 🔍 1. Linear Search

**Definition**:  
Linear Search checks each element one-by-one from the beginning until the key is found.

### ✅ Problem:
> Find the **difference between the first and last occurrence** of a given key.

**Input**:
```c
Array: [3, 2, 9, 7, 2, 8, 3, 2, 1, 2, 4]
Key = 2

#include <stdio.h>
int main() {
    int arr[] = {3, 2, 9, 7, 2, 8, 3, 2, 1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 2;
    int first = -1, last = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            if (first == -1)
                first = i;
            last = i;
        }
    }

    if (first != -1)
        printf("Difference = %d\n", last - first);
    else
        printf("Key not found\n");

    return 0;
}

🔎 2. Binary Search
Definition:
Binary Search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing the search interval in half.

Time Complexity: O(log n)

Array must be sorted

✅ Iterative Binary Search Code (C):
c
Copy
Edit
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
🔁 3. Recursive Binary Search
✅ Recursive Binary Search Code (C):
c
Copy
Edit
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, high, key);
    else
        return binarySearchRecursive(arr, low, mid - 1, key);
}
⚖️ 4. Comparison: Linear Search vs Binary Search
Feature	Linear Search	Binary Search
Works on Sorted Array	❌ No	✅ Yes (must be sorted)
Time Complexity	O(n)	O(log n)
Implementation	Simple	Slightly complex
Best Case	O(1)	O(1)
Worst Case	O(n)	O(log n)

✅ Summary
Linear Search is best for unsorted arrays or small data.

Binary Search is more efficient on large, sorted arrays.

Use recursive binary search to practice divide-and-conquer techniques.

For today's problem, Linear Search was best since the array was unsorted.


