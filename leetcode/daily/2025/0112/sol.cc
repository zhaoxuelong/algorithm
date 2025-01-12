#include "../head.h"

// https://leetcode.cn/problems/largest-combination-with-bitwise-and-greater-than-zero/submissions/592582685/?envType=daily-question&envId=2025-01-12
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> cnt(31);
        for (int x: candidates) {
            for (int i = 0; i < 31; i++) {
                if (x >> i & 1) {
                    cnt[i]++;
                }
            }
        }
        return *max_element(cnt.begin(), cnt.end());
    }
};