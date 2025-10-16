#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        if (value < 0) value = -value;
        if (value == 0) {
            unordered_set<int> s(nums.begin(), nums.end());
            int k = 0;
            while (s.count(k)) ++k;
            return k;
        }
        vector<int> cnt(value, 0);
        for (int x : nums) {
            int r = ((x % value) + value) % value;
            ++cnt[r];
        }
        int k = 0;
        while (true) {
            int r = k % value;
            if (cnt[r] > k / value) ++k;
            else return k;
        }
    }
};
