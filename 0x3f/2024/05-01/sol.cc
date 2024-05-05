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

template <typename T>
std::vector<T> discretization(std::vector<T> &a) {
    auto sorted = a;
    std::ranges::sort(sorted);
    sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
    return sorted;
}

const int MAXN = 100001;
vector<vector<int>> ds(MAXN);
int init = []() {
  for (int i = 1; i < MAXN; i++) {
    for (int j = i; j < MAXN; j += i) {
      ds[j].push_back(i);
    }
  }
  return 0;
}();

void solveOne() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &x: a) {
    cin >> x;
  }
  a = discretization(a);
  int ans = 1e9, todo = m, l = 0;
  vector<int> cnt(m + 1);
  for (auto x: a) {
    for (auto d: ds[x]) {
      if (d > m) {
        break;
      }
      if (cnt[d] == 0) {
        todo--;
      }
      cnt[d]++;
    }
    while (todo == 0) {
      ans = min(ans, x - a[l]);
      for (auto d: ds[a[l]]) {
        if (d > m) {
          break;
        }
        cnt[d]--;
        if (cnt[d] == 0) {
          todo++;
        }
      }
      l++;
    }
  }
  cout << (ans == 1e9 ? -1 : ans) << "\n";
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

