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

  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (auto &x: a) {
    cin >> x;
  }
  int l = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    while (a[l] < a[i] - d) {
      l++;
    }
    ans += (ll)(i - l) * (i - l - 1) / 2;
  }
  cout << ans << "\n";

  return 0;
}

