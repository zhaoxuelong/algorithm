#include "head.h"

// https://leetcode.cn/problems/count-complete-subarrays-in-an-array/description/
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int m = unordered_set<int>(nums.begin(), nums.end()).size();
        int ans = 0, l = 0;
        unordered_map<int, int> cnt;
        for (auto x : nums) {
            cnt[x]++;
            while (cnt.size() == m) {
                int v = nums[l++];
                if (--cnt[v] == 0) {
                    cnt.erase(v);
                }
            }
            ans += l;
        }
        return ans;
    }
};