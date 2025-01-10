#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <memory>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>
typedef int64_t ll;
using namespace std;

class Solution {
public:
    int countArrangement(int n) {
        vector<int> f(1 << n);
        f[0] = 1;
        for (int i = 1; i < 1 << n; i++) {
            int s = __builtin_popcount(i);
            for (int j = 0; j < n; j++) {
                if ((i >> j & 1) && (s % (j + 1) == 0 || (j + 1) % s == 0)) {
                    f[i] += f[i ^ (1 << j)];
                }
            }
        }
        return f.back();
    }
};
