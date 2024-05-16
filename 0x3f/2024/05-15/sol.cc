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

const int mod = 998244353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x: a) {
    cin >> x;
  }
  vector<int> b(n);
  for (auto &x: b) {
    cin >> x;
  }
  vector<ll> al(n);
  for (int i = 0; i < n; i++) {
    al[i] = (ll)a[i] * (i + 1) * (n - i);
  }
  sort(al.begin(), al.end(), greater<>());
  sort(b.begin(), b.end());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += al[i] % mod * b[i] % mod;
    ans %= mod;
  }
  if (ans < 0) {
    ans += mod;
  }
  cout << ans << "\n";

  return 0;
}

