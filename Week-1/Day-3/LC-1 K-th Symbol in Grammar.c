We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.
For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.
Example 1:

Input: n = 1, k = 1
Output: 0
Explanation: row 1: 0
Example 2:

Input: n = 2, k = 1
Output: 0
Explanation: 
row 1: 0
row 2: 01

#include <stdio.h>

int complement(int bit) {
    return bit == 0 ? 1 : 0;
}

int kthGrammar(int n, int k) {
    if (n == 1) return 0;

    int parent = kthGrammar(n - 1, (k + 1) / 2);

    if (k % 2 == 0)
        return complement(parent);
    else
        return parent;
}
