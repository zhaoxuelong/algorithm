#include "head.h"

class Solution {
public:
    bool hasAlternatingBits(int n) {
        uint32_t x = n ^ n >> 1;
        return !(x & x + 1);
    }
};