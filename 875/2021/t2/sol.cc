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

  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;
  for (int i = 4; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 3];
  }
  cout << dp[n] << "\n";

  return 0;
}

