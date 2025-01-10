#include "../head.h"

// https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/?envType=daily-question&envId=2025-01-10
class Solution {
public:
    long long validSubstringCount(string s, string t) {
        if (s.size() < t.size()) {
            return 0;
        }
        vector<int> diff(26);
        for (char c: t) {
            diff[c - 'a']++;
        }
        int less = 0;
        for (int d: diff) {
            less += d > 0;
        }
        long long ans = 0;
        int left = 0;
        for (char c: s) {
            if (--diff[c - 'a'] == 0) {
                less--;
            }
            while (!less) {
                int i = s[left++] - 'a';
                if (!diff[i]) {
                    less++;
                }
                diff[i]++;
            }
            ans += left;
        }
        return ans;
    }
};