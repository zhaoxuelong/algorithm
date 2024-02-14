#include "head.h"

// https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0, cnt = 0, mx = *max_element(nums.begin(), nums.end());
        int64_t ans = 0;
        while (r < n) {
            cnt += nums[r++] == mx;
            while (cnt == k) {
                cnt -= nums[l++] == mx;
            }
            ans += l;
        }
        return ans;
    }
};