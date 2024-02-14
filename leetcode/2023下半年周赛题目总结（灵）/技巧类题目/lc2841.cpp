#include "head.h"

// https://leetcode.cn/problems/maximum-sum-of-almost-unique-subarray/description/
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size(), r = 0;
        int64_t tot = 0;
        unordered_map<int, int> cnt;
        while (r < k) {
            tot += nums[r];
            cnt[nums[r++]]++;
        }
        int64_t ans = 0;
        if (cnt.size() >= m) {
            ans = tot;
        }
        while (r < n) {
            cnt[nums[r]]++;
            if (--cnt[nums[r - k]] == 0) {
                cnt.erase(nums[r - k]);
            }
            tot -= nums[r - k];
            tot += nums[r++];
            if (cnt.size() >= m) {
                ans = max(ans, tot);
            }
        }
        return ans;
    }
};