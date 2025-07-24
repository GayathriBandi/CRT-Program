# 📘 CRT Day 18 – Dynamic Programming (Grid-Based Problems)

---

## 📌 Key Idea of Grid-Based DP

Dynamic programming on grids involves solving problems by breaking them into cells, typically using a 2D DP table, where each cell represents a subproblem.

---

## 🚶‍♂️ Shortest Path in a Grid

### 📝 Problem Statement:
Find the minimum cost path from the top-left to bottom-right in a `m x n` grid. You can move only right or down.

---

### 📊 Grid Explanation:

Let `dp[i][j]` be the minimum cost to reach cell `(i,j)`.

```
dp[i][j] = cost[i][j] + min(dp[i-1][j], dp[i][j-1])
```

- Base case:
  - `dp[0][0] = cost[0][0]`

---

### 💻 C Code:

```c
#include <stdio.h>
#define INF 9999

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int cost[3][3] = {
        {1, 3, 5},
        {2, 1, 2},
        {4, 3, 1}
    };
    int dp[3][3];
    dp[0][0] = cost[0][0];

    for (int i = 1; i < 3; i++)
        dp[i][0] = dp[i-1][0] + cost[i][0];
    for (int j = 1; j < 3; j++)
        dp[0][j] = dp[0][j-1] + cost[0][j];

    for (int i = 1; i < 3; i++) {
        for (int j = 1; j < 3; j++) {
            dp[i][j] = cost[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    printf("Minimum path cost: %d\n", dp[2][2]);
    return 0;
}
```

---

## 🎒 0/1 Knapsack Problem

### 📝 Problem Statement:
Given weights and values of `n` items and a knapsack capacity `W`, find the maximum value you can carry.

---

### 📊 Grid Explanation:

Let `dp[i][w]` be the max value for first `i` items and weight `w`.

```
if wt[i-1] > w: dp[i][w] = dp[i-1][w]
else: dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w - wt[i-1]])
```

---

### 💻 C Code:

```c
#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("Max value in knapsack: %d\n", knapsack(W, wt, val, n));
    return 0;
}
```

---

## 🍬 Max Candies on a Trip

### 📝 Problem Statement:
Find the maximum candies that can be collected from top-left to bottom-right in a grid.

---

### 📊 Grid Explanation:
Same as shortest path, but take **maximum** instead of minimum.

```
dp[i][j] = candies[i][j] + max(dp[i-1][j], dp[i][j-1])
```

---

### 💻 C Code:

```c
#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int grid[3][3] = {
        {1, 2, 3},
        {0, 4, 6},
        {7, 4, 2}
    };
    int dp[3][3];

    dp[0][0] = grid[0][0];
    for (int i = 1; i < 3; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
    for (int j = 1; j < 3; j++) dp[0][j] = dp[0][j-1] + grid[0][j];

    for (int i = 1; i < 3; i++)
        for (int j = 1; j < 3; j++)
            dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1]);

    printf("Max candies collected: %d\n", dp[2][2]);
    return 0;
}
```

---

## 🔁 Longest Common Substring

### 📝 Problem Statement:
Find the longest substring (continuous) common to two strings.

---

### 📊 Grid Explanation:
Use 2D DP table `dp[i][j]`, update if characters match.

```
if s1[i-1] == s2[j-1]:
    dp[i][j] = dp[i-1][j-1] + 1
else:
    dp[i][j] = 0
```

---

### 💻 C Code:

```c
#include <stdio.h>
#include <string.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    char s1[] = "abcde", s2[] = "abfce";
    int n = strlen(s1), m = strlen(s2);
    int dp[n+1][m+1];
    int result = 0;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                result = max(result, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }

    printf("Length of Longest Common Substring: %d\n", result);
    return 0;
}
```

---

## 🔡 Longest Common Subsequence (LCS)

### 📝 Problem Statement:
Find the longest subsequence (not necessarily continuous) common to two strings.

---

### 📊 Grid Explanation:

```
if s1[i-1] == s2[j-1]:
    dp[i][j] = 1 + dp[i-1][j-1]
else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
```

---

### 💻 C Code:

```c
#include <stdio.h>
#include <string.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    char X[] = "AGGTAB", Y[] = "GXTXAYB";
    int m = strlen(X), n = strlen(Y);
    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    printf("Length of LCS: %d\n", dp[m][n]);
    return 0;
}
```

---

## 📝 Minimum Edit Distance

### 📝 Problem Statement:
Convert string `A` to string `B` with minimum operations: Insert, Delete, Replace.

---

### 📊 Grid Explanation:

```
if A[i-1] == B[j-1]: dp[i][j] = dp[i-1][j-1]
else:
dp[i][j] = 1 + min(dp[i-1][j],    // delete
                   dp[i][j-1],    // insert
                   dp[i-1][j-1])  // replace
```

---

### 💻 C Code:

```c
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    else if (b <= a && b <= c) return b;
    else return c;
}

int main() {
    char A[] = "kitten", B[] = "sitting";
    int m = strlen(A), n = strlen(B);
    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }

    printf("Minimum Edit Distance: %d\n", dp[m][n]);
    return 0;
}
```

---
