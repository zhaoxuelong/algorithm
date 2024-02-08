#include "head.h"

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            int freq = 0;
            for (auto x : nums) {
                freq += x >> i & 1;
            }
            ans |= (freq >= k) << i;
        }
        return ans;
    }
};