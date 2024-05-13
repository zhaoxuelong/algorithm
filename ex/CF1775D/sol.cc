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
typedef int64_t ll;
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int s, t;
  cin >> s >> t;
  s--;
  t--;
  unordered_map<int, unordered_set<int, custom_hash>, custom_hash> g;
  auto get = [&](int x) -> vector<int> {
    vector<int> ans;
    for (int i = 2; i <= x / i; i++) {
      while (x % i == 0) {
        x /= i;
        ans.push_back(i);
      }
    }
    if (x > 1) {
      ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
  };
  ll ns = 1000000000LL * s;
  ll nt = 1000000000LL * t;
  for (int i = 0; i < n; i++) {
    int x = a[i];
    auto f = get(x);
    if (i == s) {
      for (int i = 0; i < f.size(); i++) {
        g[ns].insert(f[i]);
        g[f[i]].insert(ns);
      }
    } else if (i == t) {
      for (int i = 0; i < f.size(); i++) {
        g[nt].insert(f[i]);
        g[f[i]].insert(nt);
      }
    } else {
      for (int i = 0; i < f.size(); i++) {
        for (int j = 0; j < f.size(); j++) {
          if (i != j) {
            g[f[i]].insert(f[j]);
            g[f[j]].insert(f[i]);
          }
        }
      }
    }
  }

  return 0;
}
