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

  int m;
  cin >> m;
  vector<int> dp(m + 1);
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= m; i++) {
    dp[i] += dp[i - 1] + dp[i - 2];
  }
  cout << dp[m] << "\n";

  return 0;
}