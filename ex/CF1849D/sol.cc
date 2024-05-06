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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  vector<int> prv(n + 1);
  for (int i = 0; i < n; i++) {
    prv[i + 1] = a[i] ? prv[i] : i;
  }
  vector<vector<int>> dp(n + 1, vector<int>(3, 0x3f3f3f3f));
  dp[0] = {0, 0, 0};
  dp[1][a[0]] = 1;
  for (int i = 1; i < n; i++) {
    dp[i + 1][a[i]] = min({dp[i][0] + 1, dp[i][1], dp[i][2]});
    if (a[i]) {
      dp[i + 1][a[i] - 1] = *min_element(dp[prv[i]].begin(), dp[prv[i]].end()) + 1;
    }
  }
  cout << *min_element(dp[n].begin(), dp[n].end()) << "\n";

  return 0;
}
