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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }
    int ans = a[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        auto b = a;
        int t = k;
        for (int j = i + 1; j < n && t > 0; j++) {
            if (b[j] >= b[j - 1]) {
                int add = min<long long>(t, 1ll * (b[j] - b[j - 1] + 1) * (j - i));
                t -= add;
                b[i] += add / (j - i);
            } else {
                t -= b[j - 1] - b[j] - 1;
                b[j] = b[j - 1] - 1;
            }
            ans = max(ans, b[i]);
        }
    }
    cout << ans << "\n";
}

// https://codeforces.com/problemset/problem/1856/C
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