/**
 * Problem: 15 3sum
 * Link: https://leetcode.com/problems/3sum/
 *
 * Approach:
 *   Sort the array. Starting from i = 0, scan the array using two pointers
 *   to find pairs that sum to -nums[i]. Skip duplicates to avoid same triplets.
 *
 * Time Complexity:  O(n^2)
 * Space Complexity: O(1) extra space (excluding the result)
 */


#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] > 0) {
                break;
            }

            int l = i + 1, r = n - 1;
            if ((long long)nums[i] + nums[i+1] + nums[i+2] > 0) {
                break;
            }
            if ((long long)nums[i] + nums[n-2] + nums[n-1] < 0) {
                continue;
            }
            
            while (l < r) {
                long long sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});

                    int last_l = nums[l], last_r = nums[r];
                    while (l < r && nums[l] == last_l) {
                        l++;
                    }
                    while (l < r && nums[r] == last_r) {
                        r--;
                    }
                }
                else if (sum < 0) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }
        
        return res;
    }
};