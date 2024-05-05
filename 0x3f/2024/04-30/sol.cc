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

// https://codeforces.com/problemset/problem/1029/C
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &[l, r]: a) {
    cin >> l >> r;
  }
  auto merge = [](pair<int, int> o, pair<int, int> p) -> pair<int, int> {
    return {max(o.first, p.first), min(o.second, p.second)};
  };
  vector<pair<int, int>> suffix(n + 1);
  suffix[n].second = 1e9;
  for (int i = n - 1; i > 0; i--) {
    suffix[i] = merge(suffix[i + 1], a[i]);
  }
  int64_t ans = 0;
  pair<int, int> prefix = {0, 1e9};
  for (int i = 0; i < n; i++) {
    auto m = merge(prefix, suffix[i + 1]);
    ans = max<int64_t>(ans, m.second - m.first);
    prefix = merge(prefix, a[i]);
  }
  cout << ans << "\n";

  return 0;
}

