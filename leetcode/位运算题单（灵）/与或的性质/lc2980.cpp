#include "head.h"

class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int freq = 0;
        for (auto x : nums) {
            freq += ~x & 1;
        }
        return freq >= 2;
    }
};