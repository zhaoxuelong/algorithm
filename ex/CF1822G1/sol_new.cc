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

constexpr int MAXN = 1e6 + 01;
int cnt[MAXN];

void solveOne() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x: a) {
    cin >> x;
  }
  for (auto x: a) {
    cnt[x]++;
  }
  auto b = a;
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  n = a.size();
  int64_t ans = 0;
  for (auto x: a) {
    ans += (int64_t) cnt[x] * (cnt[x] - 1) * (cnt[x] - 2); 
    for (int i = 2; i * i * x <= a.back(); i++) {
      ans += (int64_t) cnt[x] * cnt[i * x] * cnt[i * i * x];
    }
  }
  cout << ans << "\n";
  for (auto x: b) {
    cnt[x]--;
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

