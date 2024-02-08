#include "head.h"

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto nums = arr;
        for (auto& x : arr) {
            x = __builtin_popcount(x);
        }
        int n = nums.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            if (arr[i] == arr[j]) {
                return nums[i] < nums[j];
            }
            else {
                return arr[i] < arr[j];
            }
            });
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = nums[order[i]];
        }
        return ans;
    }
};