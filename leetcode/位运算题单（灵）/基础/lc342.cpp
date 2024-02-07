#include "head.h"

class Solution {
public:
    bool isPowerOfFour(int n) {
        int mask = 0;
        for (int i = 1; i < 31; i += 2) {
            mask |= 1 << i;
        }
        return n > 0 && !(n & n - 1) && !(n & mask);
    }
};