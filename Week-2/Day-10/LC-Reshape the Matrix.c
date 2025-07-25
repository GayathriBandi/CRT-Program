In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

 

Example 1:
Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]
    
Example 2:
Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]
 
#include <stdio.h>
#include <stdlib.h>

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int m = matSize, n = *matColSize;
    if (m * n != r * c) {
        *returnSize = m;
        *returnColumnSizes = malloc(m * sizeof(int));
        int** res = malloc(m * sizeof(int*));
        for (int i = 0; i < m; i++) {
            (*returnColumnSizes)[i] = n;
            res[i] = malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) {
                res[i][j] = mat[i][j];
            }
        }
        return res;
    }
    *returnSize = r;
    *returnColumnSizes = malloc(r * sizeof(int));
    int** res = malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        res[i] = malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }
    for (int i = 0; i < m * n; i++) {
        res[i / c][i % c] = mat[i / n][i % n];
    }
    return res;
}
