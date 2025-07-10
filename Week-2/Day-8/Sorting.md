# 📘 CRT Program - Day 8: Sorting Algorithms

Welcome to Day 8 of the Campus Recruitment Training (CRT) Program!  
Today’s focus is on **Sorting Algorithms**, which are fundamental to data manipulation and problem-solving in technical interviews.

---

## 📚 Topics Covered

1. ✅ Bubble Sort  
2. ✅ Insertion Sort  
3. ✅ Selection Sort  

Each sorting algorithm is explained below with logic, code, and a sample problem.

---

### 🔁 1. Bubble Sort

**🧠 Logic:**  
Repeatedly swap adjacent elements if they are in the wrong order. After each pass, the largest element “bubbles” to the end.

**💻 C Code:**
```c
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
📝 Problem Example:
Sort an array of N integers using Bubble Sort.
Input: 5 4 2 1 3
Output: 1 2 3 4 5

📌 2. Insertion Sort
🧠 Logic:
Build the sorted array one item at a time by comparing and shifting elements.

💻 C Code:

c
Copy
Edit
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
📝 Problem Example:
Sort a list of marks using Insertion Sort.
Input: 50 30 20 10 40
Output: 10 20 30 40 50

📍 3. Selection Sort
🧠 Logic:
Select the minimum element from the unsorted part and swap it with the first unsorted element.

💻 C Code:

c
Copy
Edit
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}
📝 Problem Example:
Sort the weights of students using Selection Sort.
Input: 45 25 35 20 50
Output: 20 25 35 45 50

📦 Folder Structure
Day8-Sorting/
├── bubble_sort.c
├── insertion_sort.c
├── selection_sort.c
└── README.md
✅ Summary
All three algorithms sort an array in O(n^2) time in worst-case.

Prefer Insertion Sort for small or nearly sorted arrays.

Selection Sort makes minimum number of swaps.

Bubble Sort is conceptually simplest but not efficient.
