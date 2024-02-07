#include "head.h"

class Solution {
public:
    int xorOperation(int n, int start) {
        // start^(start+2)^(start+4)^(start+2*(n-1))
        // 4i^(4i+1)^(4i+2)^(4i+3)==0
        auto f = [](int x) {
            return x % 4 == 0 ? x :
                x % 4 == 1 ? 1 :
                x % 4 == 2 ? x + 1 :
                0;
            };
        int e = n & start & 1;
        start >>= 1;
        return (f(start - 1) ^ f(start + n - 1)) << 1 | e;
    }
};