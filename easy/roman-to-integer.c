// Problem: 13. Roman to Integer
// Link: https://leetcode.com/problems/roman-to-integer/
// Time Complexity: O(n)
// Memory Complexity: O(1)

#include <stdio.h>
#include <string.h>

int getValue(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char *s) {
    int len = strlen(s);
    int total = getValue(s[len - 1]);

    for (int i = len - 2; i >= 0; i--) {
        int curr_val = getValue(s[i]);
        int next_val = getValue(s[i + 1]);

        if (curr_val >= next_val) {
            total += curr_val;
        }
        else {
            total -= curr_val;
        }
    }

    return total;
}