Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
  #include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Pair* hash = (Pair*)malloc(numsSize * sizeof(Pair));
    int hashCount = 0;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        // Search for complement in hash table
        for (int j = 0; j < hashCount; j++) {
            if (hash[j].value == complement) {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = hash[j].index;
                result[1] = i;
                *returnSize = 2;
                free(hash);
                return result;
            }
        }

        // Add current number to hash table
        hash[hashCount].value = nums[i];
        hash[hashCount].index = i;
        hashCount++;
    }

    *returnSize = 0;
    free(hash);
    return NULL; // No solution found
}
