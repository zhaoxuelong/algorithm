#include "head.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 0, freq = 0;
        for (int i = 0; i < nums.size(); i++) {
            int j = i;
            while (j < nums.size() && nums[j] == mx) {
                j++;
            }
            ans = max(ans, j - i);
            i = j;
        }
        return ans;
    }
};