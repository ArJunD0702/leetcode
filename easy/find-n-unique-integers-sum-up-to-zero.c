// Problem: 1304. Find N Unique Integers Sum up to Zero
// Link: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
// Time Complexity: O(n)
// Memory Complexity: O(n)
#include <stdlib.h>

int *sumZero(int n, int *returnSize) {
    int *arr = malloc(n * sizeof(int)); 
    if (arr == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int i = 0;

    if ((n % 2) != 0){
        arr[i++] = 0;
    }
    
    for(int k = 1; i < n; k++) {
        arr[i++] = k;
        
        if (i < n) {
            arr[i++] = -k;
        }
    }

    *returnSize = n;
    return arr;
}