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
