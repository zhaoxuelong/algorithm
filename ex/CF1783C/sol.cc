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

void solveOne() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &x: a) {
    cin >> x;
  }
  auto b = a;
  sort(b.begin(), b.end());
  int cnt = 0;
  for (int i = 0; i < n && m >= b[i]; i++) {
    m -= b[i];
    cnt++;
  }
  if (0 < cnt && cnt < n && m + b[cnt - 1] >= a[cnt]) {
    cnt++;
  }
  cout << n - cnt + 1 << "\n";
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

