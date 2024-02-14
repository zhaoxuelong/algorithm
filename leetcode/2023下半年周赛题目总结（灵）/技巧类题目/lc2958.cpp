#include "head.h"

// https://leetcode.cn/problems/length-of-longest-subarray-with-at-most-k-frequency/description/
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0, ans = 0;
        unordered_map<int, int> freq;
        while (r < n) {
            freq[nums[r]]++;
            while (freq[nums[r]] > k) {
                freq[nums[l++]]--;
            }
            ans = max(ans, ++r - l);
        }
        return ans;
    }
};