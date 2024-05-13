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

#define int ll
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int n0 = n;
  struct nb {
    int to;
    int wt;
  };
  vector<vector<nb>> g(1e6);
  auto add = [&](int v, int w, int x) -> void {
    for (; x > 9; x /= 10) {
      g[n].push_back(nb{w, x % 10});
      w = n;
      n++;
    }
    g[v].push_back(nb{w, x});
  };
  for (int i = 1; i <= m; i++) {
    int v, w;
    cin >> v >> w;
    v--; w--;
    add(v, w, i);
    add(w, v, i);
  }
  vector<int> dis(n);
  vector<bool> vis(n);
  vis[0] = true;
  queue<vector<int>> q;
  q.push({0});
  while (!q.empty()) {
    auto vs = q.front();
    q.pop();
    struct edge {
      int from;
      int to;
    };
    vector<vector<edge>> nxt(10);
    for (auto v: vs) {
      for (auto e: g[v]) {
        nxt[e.wt].push_back(edge{v, e.to});
      }
    }
    for (int wt = 0; wt < 10; wt++) {
      auto es = nxt[wt];
      vector<int> vs;
      for (auto e: es) {
        auto w = e.to;
        if (!vis[w]) {
          vis[w] = true;
          dis[w] = (dis[e.from] * 10 + wt) % ((int)1e9 + 7);
          vs.push_back(w);
        }
      }
      if (vs.size() > 0) {
        q.push(vs);
      }
    }
  }
  for (int i = 1; i < n0; i++) {
    cout << dis[i] << "\n";
  }

  return 0;
}

