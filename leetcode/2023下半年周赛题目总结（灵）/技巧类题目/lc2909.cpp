#include "head.h"

// https://leetcode.cn/problems/minimum-sum-of-mountain-triplets-ii/description/
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        auto prefix_min = nums;
        for (int i = 1; i < n; i++) {
            prefix_min[i] = min(prefix_min[i], prefix_min[i - 1]);
        }
        auto suffix_min = nums;
        for (int i = n - 2; i >= 0; i--) {
            suffix_min[i] = min(suffix_min[i], suffix_min[i + 1]);
        }
        int ans = -1;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > prefix_min[i - 1] && nums[i] > suffix_min[i + 1]) {
                int x = prefix_min[i - 1] + nums[i] + suffix_min[i + 1];
                if (ans == -1) {
                    ans = x;
                }
                else if (ans > x) {
                    ans = x;
                }
            }
        }
        return ans;
    }
};