// Problem: 9. Palindrome Number
// Link: https://leetcode.com/problems/palindrome-number/
// Time Complexity: O(logn)
// Memory Complexity: O(1)

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    long reversed = 0;
    long temp = x;

    while (temp > 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }

    return x == reversed;
}