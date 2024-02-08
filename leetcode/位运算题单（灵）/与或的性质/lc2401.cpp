#include "head.h"

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0;
        for (int l = 0, r = 0, s_or = 0; r < nums.size(); r++) {
            while (s_or & nums[r]) {
                s_or ^= nums[l++];
            }
            s_or |= nums[r];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};