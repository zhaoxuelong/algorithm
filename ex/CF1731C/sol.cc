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

void solveOne() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x: a) {
    cin >> x;
  }
  vector<int> safe_map(2 * n + 1);
  safe_map[0]++;
  int64_t ans = 1LL * n * (n + 1) / 2;
  int prefix = 0;
  for (int i = 0; i < n; i++) {
    prefix ^= a[i];
    for (int j = 0; (prefix ^ j * j) <= 2 * n; j++) {
      ans -= safe_map[prefix ^ j * j];
    }
    safe_map[prefix]++;
  }
  cout << ans << "\n";
}

// https://codeforces.com/problemset/problem/1731/C
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solveOne();
  }

  return 0;
}

