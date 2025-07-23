# CRT Day - 18: Dynamic Programming Notes

## 1. Backtracking

Backtracking is a method for building up to a solution incrementally and abandoning a path as soon as we know it won’t work.

### Example Problem: N-Queens, Rat in a Maze, Sudoku Solver

**Key Idea**:
- Explore all possibilities
- If it fails, backtrack and try another path

```c
// Example: Generate all binary strings of length n
#include <stdio.h>

void generate(int n, char *str, int i) {
    if (i == n) {
        str[i] = '\0';
        printf("%s\n", str);
        return;
    }
    str[i] = '0';
    generate(n, str, i + 1);
    str[i] = '1';
    generate(n, str, i + 1);
}

int main() {
    int n = 3;
    char str[4];
    generate(n, str, 0);
    return 0;
}

```

---

## 2. 0/1 Knapsack Problem
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value.

### Recurrence Relation:
```
dp[i][w] = max(dp[i-1][w], dp[i-1][w - wt[i]] + val[i]) if wt[i] <= w
```

```c
#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("Maximum value in Knapsack = %d\n", knapsack(W, wt, val, n));
    return 0;
}
```

---

## 3. Max Candies on a Trip (Grid Based Problem)

You are given a 2D grid of candies. You can only move right or down. Find the maximum candies that can be collected from (0,0) to (m-1,n-1).

```c
#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int maxCandies(int grid[3][3], int m, int n) {
    int dp[3][3];
    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    for (int j = 1; j < n; j++)
        dp[0][j] = dp[0][j - 1] + grid[0][j];

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    int grid[3][3] = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    printf("Max candies collected: %d\n", maxCandies(grid, 3, 3));
    return 0;
}
```

---

## 4. Longest Common Substring

### Definition:
Given two strings, find the longest string that appears as a **contiguous block** in both.

```c
#include <stdio.h>
#include <string.h>

int longestCommonSubstring(char* X, char* Y) {
    int m = strlen(X), n = strlen(Y), result = 0;
    int dp[m+1][n+1];

    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (result < dp[i][j])
                    result = dp[i][j];
            } else
                dp[i][j] = 0;
        }
    }
    return result;
}

int main() {
    char X[] = "abcde";
    char Y[] = "abfce";
    printf("Length of Longest Common Substring: %d\n", longestCommonSubstring(X, Y));
    return 0;
}
```

---

## 5. Longest Common Subsequence (LCS)

### Definition:
Find the longest sequence that appears in the same relative order but not necessarily contiguous.

```c
#include <stdio.h>
#include <string.h>

int max(int a, int b) { return (a > b) ? a : b; }

int lcs(char* X, char* Y) {
    int m = strlen(X), n = strlen(Y);
    int dp[m+1][n+1];

    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
            if (i==0 || j==0)
                dp[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    printf("Length of LCS: %d\n", lcs(X, Y));
    return 0;
}
```

---

## 6. Minimum Edit Distance

### Definition:
Convert string X to Y using minimum operations: insert, delete, replace.

```c
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int editDistance(char* str1, char* str2) {
    int m = strlen(str1), n = strlen(str2);
    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1],    // Insert
                                   dp[i-1][j],    // Remove
                                   dp[i-1][j-1]); // Replace
        }
    }
    return dp[m][n];
}

int main() {
    char str1[] = "sunday";
    char str2[] = "saturday";
    printf("Minimum Edit Distance: %d\n", editDistance(str1, str2));
    return 0;
}
```

---
```
