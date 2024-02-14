#include "head.h"

// https://leetcode.cn/problems/maximum-beauty-of-an-array-after-applying-operation/description/
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            while (nums[r] - nums[l] > k * 2) {
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};