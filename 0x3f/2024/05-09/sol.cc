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
#include <limits>
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

  int n, m;
  cin >> n >> m;
  struct edge {
    int v;
    ll w;
    bool operator<(const edge &rhs) const {
      return w > rhs.w;
    }
  };
  vector<vector<edge>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    w *= 2;
    g[u].push_back(edge{v, w});
    g[v].push_back(edge{u, w});
  }
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    g[0].push_back({i, a[i]});
  }
  vector<ll> dis(n + 1, numeric_limits<ll>::max());
  dis[0] = 0;
  priority_queue<edge> q;
  q.push(edge{0, 0});
  while (!q.empty()) {
    auto [u, ex] = q.top();
    q.pop();
    if (ex != dis[u]) {
      continue;
    }
    for (auto [v, w]: g[u]) {
      if (ex + w < dis[v]) {
        dis[v] = ex + w;
        q.push(edge{v, dis[v]});
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << dis[i] << " \n"[i == n];
  }

  return 0;
}

