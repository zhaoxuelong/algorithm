#include "head.h"

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int s = start ^ goal, ans = 0;
        while (s) {
            s &= s - 1;
            ans++;
        }
        return ans;
    }
};