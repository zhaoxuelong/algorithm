#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <ctime>
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

// https://codeforces.com/problemset/problem/1416/d
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;
  vector<int> p(n);
  for (auto &x: p) {
    cin >> x;
  }
  vector<pair<int, int>> edges(m);
  for (auto &[u, v]: edges) {
    cin >> u >> v;
    u--; v--;
  }
  // {type, v}
  vector<pair<int, int>> qrys(q);
  vector<bool> del(m);
  for (int i = 0; i < q; i++) {
    cin >> qrys[i].first >> qrys[i].second;
    qrys[i].second--;
    if (qrys[i].first == 2) {
      del[qrys[i].second] = true;
    }
  }
  vector<int> dsu(n * 2);
  iota(dsu.begin(), dsu.end(), 0);
  vector<vector<int>> adj(n * 2);
  auto find = [&](auto self, int x) -> int {
    return x != dsu[x] ? dsu[x] = self(self, dsu[x]) : x;
  };
  auto merge = [&](int x, int y) -> void {
    x = find(find, x); y = find(find, y);
    if (x != y) {
      dsu[x] = dsu[y] = n;
      adj[n].push_back(x);
      adj[n].push_back(y);
      n++;
    }
  };
  for (int i = 0; i < m; i++) {
    if (!del[i]) {
      merge(edges[i].first, edges[i].second);
    }
  }
  for (int i = q - 1; i >= 0; i--) {
    if (qrys[i].first == 1) {
      qrys[i].second = find(find, qrys[i].second);
    } else {
      merge(edges[qrys[i].second].first, edges[qrys[i].second].second);
    }
  }
  vector<int> at(n);
  // {in, out}
  vector<pair<int, int>> nodes(n);
  int _clock_t = -1;
  auto dfs = [&](auto self, int u) -> void {
    _clock_t++;
    if (u < p.size()) {
      at[_clock_t] = p[u];
    }
    nodes[u].first = _clock_t;
    for (auto v: adj[u]) {
      self(self, v);
    }
    nodes[u].second = _clock_t;
  };
  for (int i = 0; i < nodes.size(); i++) {
    if (find(find, i) == i) {
      dfs(dfs, i);
    }
  }
  struct info {
    int mx;
    int i;
  };
  auto merge_info = [&](info a, info b) -> info {
    return a.mx >= b.mx ? a : b;
  };
  struct seg {
    int l;
    int r;
    info val;
  };
  vector<seg> t(2 << (int) log2(n - 1) + 1); 
  auto maintain = [&](int o) -> void {
    t[o].val = merge_info(t[o << 1].val, t[o << 1 | 1].val);
  };
  auto build = [&](auto self, int o, int l, int r) -> void {
    t[o].l = l; t[o].r = r;
    if (l == r) {
      t[o].val = info{at[l], l};
      return;
    }
    int m = (l + r) >> 1;
    self(self, o << 1, l, m);
    self(self, o << 1 | 1, m + 1, r);
    maintain(o);
  };
  auto set0 = [&](auto self, int o, int i) -> void {
    if (t[o].l == t[o].r) {
      t[o].val.mx = 0;
      return;
    }
    int m = (t[o].l + t[o].r) >> 1;
    if (i <= m) {
      self(self, o << 1, i);
    } else {
      self(self, o << 1 | 1, i);
    }
    maintain(o);
  };
  auto query = [&](auto self, int o, int l, int r) -> info {
    if (l <= t[o].l && t[o].r <= r) {
      return t[o].val;
    }
    int m = (t[o].l + t[o].r) >> 1;
    if (r <= m) {
      return self(self, o << 1, l, r);
    }
    if (m < l) {
      return self(self, o << 1 | 1, l, r);
    }
    return merge_info(self(self, o << 1, l, r), self(self, o << 1 | 1, l, r));
  };
  build(build, 1, 0, n - 1);
  for (auto &[type, v]: qrys) {
    if (type == 2) {
      continue;
    }
    auto node = nodes[v];
    auto ans = query(query, 1, node.first, node.second);
    cout << ans.mx << "\n";
    if (ans.mx > 0) {
      set0(set0, 1, ans.i);
    }
  }

  return 0;
}

