#include "head.h"

class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y, ans = 0;
        while (s) {
            s &= s - 1;
            ans++;
        }
        return ans;
    }
};