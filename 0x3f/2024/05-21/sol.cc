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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, tot, k;
  cin >> n >> tot >> k;
  tot -= n;
  auto check = [&](int m) -> bool {
    m++;
    ll st = max(m - k + 1, 0);
    ll cnt = (st + m) * (m - st + 1) / 2;
    st = max(m - (n - k), 0);
    cnt += (st + m - 1) * (m - st) / 2;
    return cnt <= tot;
  };
  int l = 0, r = tot;
  while (l < r) {
    int m = (l + r) / 2;
    if (check(m)) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  cout << r + 1 << "\n";

  return 0;
}

