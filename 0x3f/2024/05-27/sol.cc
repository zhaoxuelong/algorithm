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

void solveOne() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x: a) {
    cin >> x;
  }
  ll ans = 0;
  for (int i = 0; i < n; ) {
    int mx = a[i];
    for (i++; i < n && mx > 0 == a[i] > 0; i++) {
      mx = max(mx, a[i]);
    }
    ans += mx;
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

