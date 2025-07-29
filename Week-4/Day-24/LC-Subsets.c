#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(int* nums, int numsSize, int** result, int* returnSize,
               int* subset, int subsetSize, int start, int* columnSizes) {
    result[*returnSize] = (int*)malloc(sizeof(int) * subsetSize);
    memcpy(result[*returnSize], subset, sizeof(int) * subsetSize);
    columnSizes[*returnSize] = subsetSize;  // Set size of current subset
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        subset[subsetSize] = nums[i];
        backtrack(nums, numsSize, result, returnSize, subset, subsetSize + 1, i + 1, columnSizes);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int maxSubsets = 1 << numsSize; // 2^n subsets
    int** result = (int**)malloc(sizeof(int*) * maxSubsets);
    int* columnSizes = (int*)malloc(sizeof(int) * maxSubsets);
    int* subset = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = 0;

    backtrack(nums, numsSize, result, returnSize, subset, 0, 0, columnSizes);

    *returnColumnSizes = columnSizes;
    free(subset);
    return result;
}
