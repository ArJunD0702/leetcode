// Problem: 231. Power of Two
// Link: https://leetcode.com/problems/power-of-two/
// Time Complexity: O(1)
// Memory Complexity; O(1)

#include <stdbool.h>

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
