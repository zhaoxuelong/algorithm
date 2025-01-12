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
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int, custom_hash> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        long long y;
        cin >> x >> y;
        // -a^2+a*x-y=0
        long long delta = (long long)x * x - 4 * y;
        long long sq = sqrtl(delta);
        long long ans = 0;
        if (sq * sq == delta) {
            if (delta == 0) {
                ans += (long long)cnt[x / 2] * (cnt[x / 2] - 1) / 2;
            } else {
                ans += (long long)cnt[(x - sq) / 2] * cnt[(x + sq) / 2];
            }
        }
        cout << ans << " \n"[i == q - 1];
    }
}

// https://codeforces.com/problemset/problem/1857/F
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}