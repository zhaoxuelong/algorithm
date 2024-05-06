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
using namespace std;

constexpr int mod = (int)1e9 + 07;

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

void solveOne() {
  int n, k;
  cin >> n >> k;
  vector<int> dp(64);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vector<int> new_dp(64);
    new_dp[x]++;
    for (int j = 0; j < 64; j++) {
      add(new_dp[j & x], dp[j]);
    }
    for (int j = 0; j < 64; j++) {
      add(new_dp[j], dp[j]);
    }
    dp = new_dp;
  }
  int ans = 0;
  for (int i = 0; i < 64; i++) {
    if (__builtin_popcount(i) == k) {
      add(ans, dp[i]);
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
