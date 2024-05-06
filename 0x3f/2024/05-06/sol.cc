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

// https://codeforces.com/problemset/problem/1759/D
void solveOne() {
  int n, m;
  cin >> n >> m;
  int c2 = 0, c5 = 0;
  auto calc = [](int x, int d) -> int {
    int ans = 0;
    while (x && x % d == 0) {
      x /= d;
      ans++;
    }
    return ans;
  };
  c2 = calc(n, 2);
  c5 = calc(n, 5);
  int k = 1;
  while (c2 < c5 && k * 2 <= m) {
    k *= 2;
    c2++;
  }
  while (c2 > c5 && k * 5 <= m) {
    k *= 5;
    c5++;
  }
  while ((int64_t)k * 10 <= m) {
    k *= 10;
  }
  cout << (int64_t)n * (m - m % k) << "\n";
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
