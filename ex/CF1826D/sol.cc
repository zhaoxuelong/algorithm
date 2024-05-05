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

// https://codeforces.com/problemset/problem/1826/D
void solveOne() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x: a) {
    cin >> x;
  }
  // max(a[i]+i) + a[j] + max(a[k]-k)
  vector<int> prefix(n + 1), suffix(n + 1, -1e9);
  for (int i = 0; i < n; i++) {
    prefix[i + 1] = max(prefix[i], a[i] + i);
  }
  for (int i = n - 1; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], a[i] - i);
  }
  int ans = -1e9;
  for (int i = 0; i < n; i++) {
    ans = max(ans, prefix[i] + a[i] + suffix[i + 1]);
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

