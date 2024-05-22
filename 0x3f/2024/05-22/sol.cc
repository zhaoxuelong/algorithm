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
  vector<vector<int>> t(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    t[u].push_back(v);
    t[v].push_back(u);
  }
  int ans = 0;
  auto dfs = [&](auto self, int u, int p, int dep) -> void {
    int deg = 0;
    for (auto v: t[u]) {
      if (v == p) continue;
      self(self, v, u, dep + 1);
      deg++;
    }
    if (deg < 2) {
      ans = max(ans, n - 2 * dep - 1 - deg);
    }
  };
  dfs(dfs, 0, -1, 0);
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

