// Problem: Find Most Frequent Vowel and Consonant
// Link: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/
// Time Complexity: O(n)
// Memory Complexity: O(1) 

#include <string.h>

int maxFreqSum(char* s) {
    int freq[26] = {0};

    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (c >= 'a' && c <= 'z') {
            freq[c - 'a']++;
        }
    }

    int max_v = 0, max_c = 0;
    for (int i = 0; i < 26; i++) {
        if (i == ('a' - 'a') || i == ('e' - 'a') || 
            i == ('i' - 'a') || i == ('o' - 'a') || 
            i == ('u' - 'a')) {
                if (freq[i] > max_v) {
                    max_v = freq[i];
                }
        }
        else {
            if (freq[i] > max_c) {
                max_c = freq[i];
            }
        }
    }

    return max_c + max_v;
}