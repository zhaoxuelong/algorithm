#include "head.h"

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int highest_bit = 31 - __builtin_clz(n);
        vector<int> ans(2);
        for (int i = 0; i <= highest_bit; i++) {
            ans[i & 1] += n >> i & 1;
        }
        return ans;
    }
};