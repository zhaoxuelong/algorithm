#include "head.h"

class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int inf = ~(1 << 30), ans = 0, s = inf;
        for (auto x : nums) {
            s &= x;
            if (s == 0) {
                ans++;
                s = inf;
            }
        }
        return ans == 0 ? 1 : ans;
    }
};