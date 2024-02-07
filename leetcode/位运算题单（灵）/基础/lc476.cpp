#include "head.h"

class Solution {
public:
    int findComplement(int num) {
        int highest_bit = 31 - __builtin_clz(num);
        return ~num & (1 << highest_bit) - 1;
    }
};