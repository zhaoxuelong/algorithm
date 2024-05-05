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

// https://codeforces.com/contest/213/problem/C
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector a(n, vector<int>(n));
  for (auto &i: a) {
    for (auto &j: i) {
      cin >> j;
    }
  }
  const int m = n * 2 - 1;
  vector dp(n, vector<int>(n, -1e9));
  dp[0][0] = a[0][0];
  for (int tot = 1; tot < m; tot++) {
    for (int i = min(tot, n - 1); i >= max(0, tot - n + 1); i--) {
      for (int j = min(n - 1, tot); j >= i; j--) {
        auto &f = dp[i][j];
        f = max(f, dp[i][j]);
        if (i) f = max(f, dp[i - 1][j]);
        if (j) f = max(f, dp[i][j - 1]);
        if (i && j) f = max(f, dp[i - 1][j - 1]);
        f += a[tot - i][i];
        if (i != j) {
          f += a[tot - j][j];
        }
      }
    }
  }
  cout << dp[n - 1][n - 1] << "\n";

  return 0;
}

