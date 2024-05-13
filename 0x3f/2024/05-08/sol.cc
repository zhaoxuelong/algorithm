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
  string t;
  cin >> t;
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto &s: a) {
    cin >> s;
  }
  n = t.size();
  vector<int> dp(n + 1);
  struct pr {
    int ti;
    int ai;
  };
  vector<pr> from(n + 1);
  for (int i = 1; i <= n; i++) {
    dp[i] = 1e9;
    for (int j = 0; j < a.size(); j++) {
      string &s = a[j];
      int m = s.size();
      for (int k = max(i - m, 0); k < i && k <= n - m; k++) {
        if (t.substr(k, m) == s && dp[k] + 1< dp[i]) {
          dp[i] = dp[k] + 1;
          from[i] = pr{k, j + 1};
        }
      }
    }
  }
  if (dp[n] == 1e9) {
    cout << "-1\n";
    return;
  }
  cout << dp[n] << "\n";
  int i = n;
  for (; from[i].ti > 0; i = from[i].ti) {
    cout << from[i].ai << " " << from[i].ti + 1 << "\n";
  }
  cout << from[i].ai << " " << 1 << "\n";
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

