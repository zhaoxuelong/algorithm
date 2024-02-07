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

void solve() {
    int n; string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> freq(10);
        int maxF = 0, f = 0;
        for (int j = i; j < n; j++) {
            char x = int(s[j] - '0');
            if (freq[x] == 10) {
                break;
            }
            if (freq[x] == 0) {
                f++;
            }
            freq[x]++;
            maxF = max(maxF, freq[x]);
            if (maxF <= f) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}