# 📘 Day 9 - Quick Sort & Merge Sort (CRT Program)

---

## 🌀 Quick Sort

### 🔸 Algorithm (Divide and Conquer)

1. Choose a pivot element.
2. Partition the array such that:
   - Elements smaller than pivot go to the left.
   - Elements greater than pivot go to the right.
3. Recursively apply the same logic to left and right subarrays.

---

### ⏱️ Time Complexity

| Case       | Time Complexity |
|------------|-----------------|
| Best Case  | O(n log n)      |
| Average    | O(n log n)      |
| Worst Case | O(n²)           |

> Worst case occurs when pivot is smallest or largest repeatedly (e.g., sorted array with last element as pivot).

---

### 🔍 Example

Input:  
`arr = [10, 7, 8, 9, 1, 5]`

Process:
💻 C Code for Quick Sort:

#include <stdio.h>

void swap(int* a, int* b) {

    int t = *a;
    *a = *b;
    *b = t;
    
}

int partition(int arr[], int low, int high) {

    int pivot = arr[high];
    
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
    
        if (arr[j] < pivot) {
        
            i++;
            
            swap(&arr[i], &arr[j]);
            
        }
        
    }
    
    swap(&arr[i+1], &arr[high]);
    
    return i+1;
    
}

void quickSort(int arr[], int low, int high) {


    if (low < high) {
    
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        
        quickSort(arr, pi + 1, high);
        
    }
    
}

### 📚 qsort() Notes in C:

Header: stdlib.h

Syntax:

qsort(base, nitems, size, compar_function)

Example:

int compare(const void* a, const void* b) {

    return (*(int*)a - *(int*)b);
    
}

qsort(arr, n, sizeof(int), compare);

### 🧩 Merge Sort
--------------

Algorithm:

1. Divide array into 2 halves
2. Recursively sort each half
3. Merge the two sorted halves

### ⏱️ Time Complexity:

Best Case    : O(n log n)
Average Case : O(n log n)
Worst Case   : O(n log n)
Space        : O(n)

### 🔍 Example:

Input: arr = [12, 11, 13, 5, 6, 7]

→ Divide: [12,11,13] & [5,6,7]
→ Recursively sort both halves
→ Merge sorted halves

### 💻 C Code for Merge Sort:


#include <stdio.h>

void merge(int arr[], int l, int m, int r) {

    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
    
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
            
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {

    if (l < r) {
    
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
        
    }
    
}

int main() {

    int arr[] = {12, 11, 13, 5, 6, 7};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
### ✅ Summary Table:

| Sorting     | Best    | Average | Worst    | Stable | In-place |
|-------------|---------|---------|----------|--------|----------|
| Quick Sort  | O(nlogn)| O(nlogn)| O(n^2)   |   No   |   Yes    |
| Merge Sort  | O(nlogn)| O(nlogn)| O(nlogn) |  Yes   |   No     |

### 📅 Day 9 Completed!
- Quick Sort
- Merge Sort
- qsort() logic
- Time complexity, Examples, Code








