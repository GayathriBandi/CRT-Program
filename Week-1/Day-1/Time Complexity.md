## 📘 Day 1: Time Complexity

Welcome to **Day 1** of my DSA Learning Journey!  
Today’s focus: **Time Complexity** – a fundamental concept to evaluate how efficiently an algorithm performs as input size grows.

---

## 🧠 What is Time Complexity?

Time Complexity refers to how the runtime of an algorithm scales with the input size `n`.  
It is expressed using **Big O Notation** and helps compare algorithm efficiency.

### 🔢 Common Notations

- `O(1)` – Constant Time  
- `O(n)` – Linear Time  
- `O(log n)` – Logarithmic Time  
- `O(n log n)` – Linearithmic Time  
- `O(n²)` – Quadratic Time  
- `O(2ⁿ)` – Exponential Time  
- `O(n!)` – Factorial Time  

---

### ✨ Why It's Important

- 🔍 **Compare** algorithm efficiency  
- ⚙️ **Optimize** performance  
- 📈 **Predict** scalability  

---

## 📊 Common Time Complexities

| Big O        | Name         | Description                             | Example                    |
|--------------|--------------|-----------------------------------------|----------------------------|
| `O(1)`       | Constant      | Executes in the same time always        | Access `arr[0]`            |
| `O(log n)`   | Logarithmic   | Halves the input each step              | Binary Search              |
| `O(n)`       | Linear        | Proportional to input size              | Loop through array         |
| `O(n log n)` | Linearithmic  | Log factor on top of linear             | Merge Sort, Quick Sort     |
| `O(n²)`      | Quadratic     | Nested loops                            | Bubble Sort                |
| `O(2ⁿ)`      | Exponential   | Doubles with each additional input      | Recursive Fibonacci        |
| `O(n!)`      | Factorial     | All permutations                        | Traveling Salesman Problem |

---

## 🛍️ Rahul at the Shopping Mall (Analogy)

- 🟢 **O(1)** – Rahul walks into the first store and buys a T-shirt.  
- 🔵 **O(n)** – He visits every store before picking one.  
- 🟡 **O(log n)** – Uses a sorted mall directory and eliminates half the stores each time.  
- 🔴 **O(n²)** – Compares every T-shirt in every store with all others. Way too slow!

---

## 💻 Code Examples in C

### 🔹 O(1) – Constant Time

### 🔹 O(1) – Constant Time
```c
#include <stdio.h>
int getFirst(int arr[]) {
    return arr[0];
}
int main() {
    int arr[] = {10, 20, 30, 40};
    printf("First element: %d\n", getFirst(arr));
    return 0;
}

🔹 O(n) – Linear Time

#include <stdio.h>
void printAll(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    printAll(arr, size);
    return 0;
}

🔹 O(log n) – Logarithmic Time (Binary Search)

#include <stdio.h>
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    int result = binarySearch(arr, size, key);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
    return 0;
}

🔹 O(n²) – Quadratic Time

#include <stdio.h>
void allPairs(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("(%d, %d)\n", arr[i], arr[j]);
        }
    }
}
int main() {
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    allPairs(arr, size);
    return 0;
}
 🧩 Tips to Improve Time Complexity
 ✅ Use hash maps or sets for faster lookups

 🔁 Eliminate unnecessary nested loops

 🔍 Prefer binary search for sorted data

⚙️ Choose efficient algorithms (e.g., Merge Sort over Bubble Sort)

🧠 Time vs Space: Simplified
💡 Definitions
Time Complexity → How long your code takes to run

Space Complexity → How much memory your code uses

🚌 Story: Waiting for a Bus
Imagine you're waiting for a specific bus. Your approach shows different complexities:

🔴 O(n²) – Confused Passenger:
Asks everyone about every bus. Very inefficient.

🟢 O(n) – Careful Observer:
Checks each bus as it comes. Simple and practical.

🟢 O(log n) – Smart Commuter:
Uses a bus tracking app. Skips irrelevant ones. Very efficient.

📋 Comparison Table
Scenario	Time	Space	Technique Used
Brute-force search	O(n²)	O(1)	Nested loops
Hash map for lookups	O(n)	O(n)	Dictionary / Set
Dynamic Programming (Memo)	O(n)	O(n)	Memoization table

✅ Final Thoughts
Focus on writing algorithms with better time complexity

Remember: faster code may use more memory (a space-time tradeoff)

Balance both based on constraints

Think like Rahul or the Smart Commuter, not the confused passenger 😉

yaml
Copy
Edit

---

Let me know if you'd like:
- A downloadable `.md` file  
- A visual diagram or infographic to embed  
- Or to format it for a GitHub Pages website!


