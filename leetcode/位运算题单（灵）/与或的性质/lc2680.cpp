#include "head.h"

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffix_or(n + 1);
        for (int i = n - 1; ~i; i--) {
            suffix_or[i] = suffix_or[i + 1] | nums[i];
        }
        int prefix_or = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max<long long>(ans, prefix_or | suffix_or[i + 1] | (long long)nums[i] << k);
            prefix_or |= nums[i];
        }
        return ans;
    }
};