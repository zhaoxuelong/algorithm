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

auto factorize(int x) {
  unordered_map<int, int, custom_hash> cnt;
  for (int i = 2; i * i <= x; i++) {
    if (x % i) {
      continue;
    }
    int e = 1;
    for (x /= i; x % i == 0; x /= i) {
      e++;
    }
    cnt[i] = e;
  }
  if (x > 1) {
    cnt[x] = 1;
  }
  return cnt;
}

void solveOne() {
  int n, q;
  cin >> n >> q;
  auto cnt = factorize(n);
  while (q--) {
    int k;
    cin >> k;
    if (k == 2) {
      cnt = factorize(n);
      continue;
    }
    int x;
    cin >> x;
    for (auto &[p, e]: factorize(x)) {
      cnt[p] += e;
    }
    int d = 1;
    for (auto &[_, e]: cnt) {
      d *= e + 1;
    }
    bool ok = true;
    for (auto &[p, e]: factorize(d)) {
      if (e > cnt[p]) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << "\n";
  }
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

