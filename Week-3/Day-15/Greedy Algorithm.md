# Day 15 - Greedy Algorithms

## 🌟 What is a Greedy Algorithm?

A **Greedy Algorithm** builds up a solution piece by piece, always choosing the next piece that offers the most immediate benefit (greedy choice), with the hope that this choice leads to an optimal solution.

## 🧠 Assumptions for Greedy Strategy
1. **Greedy Choice Property** – A global optimum can be arrived at by choosing a local optimum.
2. **Optimal Substructure** – A problem exhibits optimal substructure if an optimal solution to the problem contains optimal solutions to the sub-problems.

---

## 💰 Greedy Coin Change Problem

### Problem:
Given denominations of coins and a total amount, find the minimum number of coins to make the amount using a greedy strategy.

### Assumption:
- The denominations are such that greedy choice gives the optimal result (e.g., Indian coins: 1, 2, 5, 10, 20, 50, 100, 200, 500).

### C Code:

```c
#include <stdio.h>

void coinChange(int coins[], int n, int amount) {
    printf("Coins used to make %d: ", amount);
    for (int i = n - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            printf("%d ", coins[i]);
        }
    }
    printf("\n");
}

int main() {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 93;

    coinChange(coins, n, amount);
    return 0;
}
```

---

## 🕒 Activity Selection Problem (Start-End Time)

### Problem:
Given `n` activities with start and end times, select the maximum number of activities that don't overlap.

### Strategy:
1. Sort activities by **end time**.
2. Select activity if its start time is >= end time of last selected activity.

### C Code:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Activity;

int compare(const void *a, const void *b) {
    return ((Activity *)a)->end - ((Activity *)b)->end;
}

void selectActivities(Activity arr[], int n) {
    qsort(arr, n, sizeof(Activity), compare);
    printf("Selected activities: \n");

    int i = 0;
    printf("(%d, %d)\n", arr[i].start, arr[i].end);

    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].end) {
            printf("(%d, %d)\n", arr[j].start, arr[j].end);
            i = j;
        }
    }
}

int main() {
    Activity activities[] = {{1, 3}, {2, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    int n = sizeof(activities) / sizeof(activities[0]);

    selectActivities(activities, n);
    return 0;
}
```

---

## ✨ Other Classic Greedy Problems:
- **Huffman Encoding**
- **Job Sequencing**
- **Fractional Knapsack** (uses greedy, while 0/1 uses dynamic programming)

---

## 📌 Conclusion

Greedy algorithms are easy to implement and fast, but only work optimally when the problem satisfies:
- Greedy choice property
- Optimal substructure

Always check these conditions before using greedy!

