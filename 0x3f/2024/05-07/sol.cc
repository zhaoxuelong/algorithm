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

  ll n;
  cin >> n; 
  auto check = [&](ll k) -> bool {
    ll m = n, s = 0;
    while (m > k) {
      s += k;
      m -= k;
      m -= m / 10;
    }
    return (s + m) * 2 >= n;
  };
  ll l = 1, r = n / 2;
  while (l < r) {
    ll m = (l + r) / 2;
    if (check(m)) {
      r = m;
    } else {
      l = m + 1;
    }
    // cerr << "(" << l << " " << m << " " << r << ")\n";
  }
  cout << l << "\n";

  return 0;
}

