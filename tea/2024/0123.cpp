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
#include <vector>
using namespace std;

typedef int64_t ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    vector<int> mn(n, 0x3f3f3f3f);
    for (int i = n - 2; i >= 0; i--) {
        mn[i] = min(mn[i + 1], a[i + 1]);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (mn[i] >= a[i]) {
            ans.push_back(-1);
        } else {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (mn[mid] >= a[i]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans.push_back(l - i - 1);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}