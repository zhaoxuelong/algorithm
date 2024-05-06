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
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
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
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

void solveOne() {
  int n, a, b;
  cin >> n >> a >> b;
  a--;
  b--;
  vector<vector<pair<int, int>>> t(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    t[u].emplace_back(v, w);
    t[v].emplace_back(u, w);
  }
  unordered_set<int, custom_hash> seen;
  auto dfs_a = [&](auto self, int u, int fa, int s) -> bool {
    if (u == b) {
      return !s;
    }
    seen.insert(s);
    for (auto &[v, w] : t[u]) {
      if (v != fa) {
        if (self(self, v, u, s ^ w)) {
          return 1;
        }
      }
    }
    return 0;
  };
  if (dfs_a(dfs_a, a, -1, 0)) {
    cout << "YES\n";
    return;
  }
  auto dfs_b = [&](auto self, int u, int fa, int s) -> bool {
    if (u != b && seen.contains(s)) {
      return 1;
    }
    for (auto &[v, w] : t[u]) {
      if (v != fa) {
        if (self(self, v, u, s ^ w)) {
          return 1;
        }
      }
    }
    return 0;
  };
  cout << (dfs_b(dfs_b, b, -1, 0) ? "YES" : "NO") << "\n";
}

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
