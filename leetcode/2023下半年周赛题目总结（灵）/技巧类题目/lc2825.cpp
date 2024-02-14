#include "head.h"

// https://leetcode.cn/problems/make-string-a-subsequence-using-cyclic-increments/description/
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int i1 = 0, i2 = 0;
        while (i1 < n && i2 < m) {
            char a = str1[i1], b = str2[i2];
            if (a == b || (a + 1 == 'z' + 1) && b == 'a' || a + 1 == b) {
                i2++;
            }
            i1++;
        }
        return i2 == m;
    }
};