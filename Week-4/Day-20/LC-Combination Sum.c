Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []

#include <stdio.h>
#include <stdlib.h>

void backtrack(int* candidates, int candidatesSize, int target, int* combination, int combSize,
               int** result, int* returnSize, int* returnColumnSizes, int start) {
    if (target == 0) {
        result[*returnSize] = (int*)malloc(sizeof(int) * combSize);
        for (int i = 0; i < combSize; i++)
            result[*returnSize][i] = combination[i];
        returnColumnSizes[*returnSize] = combSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] <= target) {
            combination[combSize] = candidates[i];
            backtrack(candidates, candidatesSize, target - candidates[i], combination, combSize + 1,
                      result, returnSize, returnColumnSizes, i);
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * 200);
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * 200);
    int* combination = (int*)malloc(sizeof(int) * target);

    backtrack(candidates, candidatesSize, target, combination, 0, result, returnSize, *returnColumnSizes, 0);

    free(combination);
    return result;
}

 
