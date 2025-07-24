# 📘 CRT Day 17 – Dynamic Programming

---

## 🔍 What is Dynamic Programming (DP)?

Dynamic Programming is a method for solving problems by breaking them into smaller subproblems, storing their results (memoization/tabulation), and reusing them to avoid redundant calculations.

---

## ✅ Rules to Apply DP

1. **Optimal Substructure** – Problem can be broken into subproblems.
2. **Overlapping Subproblems** – Subproblems repeat.
3. **Memoization or Tabulation** – Store previous results.
4. **Base Cases** – Know the smallest input answers.

---

## 🧒 Boy and Staircase Problem

### 📝 Problem Statement:
A boy wants to climb `n` stairs. He can take 1 or 2 steps at a time. Find how many distinct ways he can reach the top.

---

### 🔍 Substructure:
- `ways(n) = ways(n-1) + ways(n-2)`
- Base cases:
  - `ways(0) = 1` (no steps to climb)
  - `ways(1) = 1` (only 1 way)
  - `ways(2) = 2` (1+1 or 2)

---

### 💻 C Code:

```c
#include <stdio.h>

int countWays(int n) {
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}

int main() {
    int n;
    printf("Enter number of stairs: ");
    scanf("%d", &n);
    printf("Number of ways to climb: %d\n", countWays(n));
    return 0;
}
```

---

## 💰 Coin Change Problem

### 📝 Problem Statement:
Given coins of denominations and a total, find the number of ways to make that amount.

---

### 🔍 Substructure:
- `ways[i] = ways[i] + ways[i - coin]` for all coins
- Base: `ways[0] = 1`

---

### 💻 C Code:

```c
#include <stdio.h>

int countChange(int coins[], int m, int amount) {
    int dp[amount+1];
    for (int i = 0; i <= amount; i++) dp[i] = 0;
    dp[0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];
}

int main() {
    int coins[] = {1, 2, 5};
    int m = sizeof(coins)/sizeof(coins[0]);
    int amount = 5;
    printf("Number of ways to make change: %d\n", countChange(coins, m, amount));
    return 0;
}
```

---

## 🧵 Cloth Cutting (Rod Cutting)

### 📝 Problem Statement:
Given a cloth (rod) of length `n` and prices for each cut, find the maximum profit.

---

### 🔍 Substructure:
- `dp[i] = max(dp[i], price[j] + dp[i-j-1])`

---

### 💻 C Code:

```c
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int rodCutting(int price[], int n) {
    int dp[n+1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = -1;
        for (int j = 0; j < i; j++) {
            dp[i] = max(dp[i], price[j] + dp[i-j-1]);
        }
    }
    return dp[n];
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    printf("Max profit from cutting: %d\n", rodCutting(price, n));
    return 0;
}
```

---

## 🔡 Longest Increasing Subsequence (LIS)

### 📝 Problem Statement:
Find the length of the longest increasing subsequence in an array.

---

### 💻 C Code:

```c
#include <stdio.h>

int LIS(int arr[], int n) {
    int lis[n];
    for (int i = 0; i < n; i++) lis[i] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    int max = lis[0];
    for (int i = 1; i < n; i++)
        if (lis[i] > max)
            max = lis[i];
    return max;
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LIS: %d\n", LIS(arr, n));
    return 0;
}
```

---

## 🔢 Ways to Translate Number (like Leetcode Q: Decode Ways)

### 📝 Problem Statement:
Each digit from 1–26 maps to a letter. Find number of ways to decode a digit string.

---

### 💻 C Code:

```c
#include <stdio.h>
#include <string.h>

int numDecodings(char* s) {
    int n = strlen(s);
    if (n == 0 || s[0] == '0') return 0;

    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = 0;
        if (s[i-1] != '0')
            dp[i] += dp[i-1];
        if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))
            dp[i] += dp[i-2];
    }

    return dp[n];
}

int main() {
    char s[] = "226";
    printf("Number of decodings: %d\n", numDecodings(s));
    return 0;
}
```

---

## 🔄 Rotate a 3x3 Matrix 90 Degrees Clockwise `n` times

### 💻 C Code:

```c
#include <stdio.h>

void rotate90(int mat[3][3]) {
    int temp[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp[j][2 - i] = mat[i][j];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            mat[i][j] = temp[i][j];
}

void printMatrix(int mat[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int times;
    printf("Enter number of times to rotate: ");
    scanf("%d", &times);

    for (int i = 0; i < times % 4; i++) {
        rotate90(mat);
    }

    printf("Rotated Matrix:\n");
    printMatrix(mat);
    return 0;
}
```

---
