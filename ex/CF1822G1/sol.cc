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

constexpr int MAXN = 1e6 + 01;
vector<vector<int>> ds(MAXN);
int init = []() {
  for (int i = 1; i < MAXN; i++) {
    for (int j = i; j < MAXN; j += i) {
      ds[j].push_back(i);
    }
  }
  return 0;
}();

void solveOne() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x: a) {
    cin >> x;
  }
  unordered_map<int64_t, int, custom_hash> cnt;
  // int m = *max_element(a.begin(), a.end());
  // vector<int> cnt(m + 1);
  for (auto x: a) {
    cnt[x]++;
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  n = a.size();
  // for (auto x: a) {
  //   cerr << x << " " << cnt[x] << "\n";
  // } cerr << "-----------\n";
  int64_t ans = 0;
  for (auto x: a) {
    if (cnt[x] >= 3) {
      ans += (int64_t) cnt[x] * (cnt[x] - 1) * (cnt[x] - 2); 
    }
    for (auto o: ds[x]) {
      if (x != o && o % (x / o) == 0) {
        auto p = o / (x / o);
        // cerr << x << " " << o << " " << p << "\n";
        if (cnt.contains(x) && cnt.contains(o) && cnt.contains(p)) {
          ans += (int64_t) cnt[x] * cnt[o] * cnt[p];
        }
      } 
    }
  }
  cout << ans << "\n";
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

