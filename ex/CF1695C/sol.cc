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

void solveOne() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  if ((n + m - 1) & 1) {
    cout << "NO\n";
    return;
  }
  vector<vector<int>> o(n + 1, vector<int>(m + 1));
  auto p = o;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      o[i + 1][j + 1] = max(o[i + 1][j], o[i][j + 1]) + (a[i][j] == 1);
      p[i + 1][j + 1] = max(p[i + 1][j], p[i][j + 1]) + (a[i][j] == -1);
    }
  }
  int r = o[n][m], l = n + m - 1 - p[n][m];
  int d = (n + m - 1) / 2;
  if (l <= d && d <= r) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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
