#include "head.h"

// https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-ii/description/
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        auto prefix_max = nums;
        auto suffix_max = nums;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            prefix_max[i] = max(prefix_max[i], prefix_max[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            suffix_max[i] = max(suffix_max[i], suffix_max[i + 1]);
        }
        int64_t ans = 0;
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, (int64_t)(prefix_max[i - 1] - nums[i]) * suffix_max[i + 1]);
        }
        return ans;
    }
};