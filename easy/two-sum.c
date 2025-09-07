// Problem: 1. Two Sum
// Link: https://leetcode.com/problems/two-sum/
// Time Complexity: O(N^2) 
// Memory Complexity: O(1) 

#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if ((nums[i] + nums[j]) == target) {
                int *result = malloc(2 * sizeof(int));

                if (result == NULL) { // if malloc fails
                    *returnSize = 0;
                    return NULL;
                }

                *returnSize = 2;

                result[0] = i;
                result[1] = j;

                return result;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}
