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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void solveOne() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto &x: a) {
    cin >> x;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'B') {
        for (int k = 0; k < 4; k++) {
          int ni = i + dx[k], nj = j + dy[k];
          if (0 <= ni && ni < n && 0 <= nj && nj < m) {
            if (a[ni][nj] == 'G') {
              cout << "No\n";
              return;
            }
            if (a[ni][nj] == '.') {
              a[ni][nj] = '#';
            }
          }
        }
      } else if (a[i][j] == 'G') {
        cnt++;
      }
    }
  }
  if (a[n - 1][m - 1] == '#' && cnt) {
    cout << "No\n";
    return;
  }
  vector visited(n, vector<bool>(m));
  visited[n - 1][m - 1] = true;
  auto dfs = [&](auto self, int i, int j) -> void {
    if (a[i][j] == 'G') {
      cnt--;
    }
    for (int k = 0; k < 4; k++) {
      int ni = i + dx[k], nj = j + dy[k];
      if (0 <= ni && ni < n && 0 <= nj && nj < m && (a[ni][nj] == 'G' || a[ni][nj] == '.') && !visited[ni][nj]) {
        visited[ni][nj] = true;
        self(self, ni, nj);
      }
    }
  };
  dfs(dfs, n - 1, m - 1);
  cout << (cnt == 0 ? "Yes" : "No") << "\n";
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

