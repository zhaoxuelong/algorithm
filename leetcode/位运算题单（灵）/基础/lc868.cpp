#include "head.h"

class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, last = -1;
        for (int i = 0; i < 30; i++) {
            if (n >> i & 1) {
                if (last != -1) {
                    ans = max(ans, i - last);
                }
                last = i;
            }
        }
        return ans;
    }
};