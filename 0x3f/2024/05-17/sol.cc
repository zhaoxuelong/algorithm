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

void solveOne() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  vector<int> cnt(n + 1);
  for (auto &x : a) {
    cnt[x]++;
  }
  vector<bool> has_d(n + 1);
  vector<ll> res(n + 1);
  for (int i = n; i > 0; i--) {
    ll c = 0;
    for (int j = i; j <= n; j += i) {
      if (cnt[i] > 0) {
        has_d[j] = true;
      }
      c += cnt[j];
      res[i] -= res[j];
    }
    res[i] += c * (c - 1) / 2;
  }
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    if (!has_d[i]) {
      ans += res[i];
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
