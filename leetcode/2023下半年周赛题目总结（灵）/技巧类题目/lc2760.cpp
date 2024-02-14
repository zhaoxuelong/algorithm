#include "head.h"

// https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold/description/
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size(), ans = 0, i = 0;
        while (i < n) {
            if (nums[i] % 2 || nums[i] > threshold) {
                i++;
                continue;
            }
            int j = i++;
            while (i < n && nums[i] <= threshold && nums[i] % 2 != nums[i - 1] % 2) {
                i++;
            }
            ans = max(ans, i - j);
        }
        return ans;
    }
};