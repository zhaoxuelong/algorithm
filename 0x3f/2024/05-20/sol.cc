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
typedef int64_t ll;
using namespace std;

void solveOne() {
  string s;
  cin >> s;
  int n = s.size();
  int a = 0, b = 0, c = 0;
  auto f = [&](char ch, int v) -> void {
    if (ch == '1') {
      a += v;
    } else if (ch == '2') {
      b += v;
    } else if (ch == '3') {
      c += v;
    } else {
      assert(false);
    }
  };
  auto d = [&](char ch) -> bool {
    return ch == '1' && a - 1 >= 1 || ch == '2' && b - 1 >= 1 ||
           ch == '3' && c - 1 >= 1;
  };
  int l = 0, ans = -1;
  for (int r = 0; r < n; r++) {
    f(s[r], 1);
    while (d(s[l])) {
      f(s[l], -1);
      l++;
    }
    if (a && b && c) {
      if (ans == -1) {
        ans = r - l + 1;
      } else {
        ans = min(ans, r - l + 1);
      }
      // cerr << "(" << l << " " << r << ")\n";
    }
  }
  cout << max(ans, 0) << "\n";
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
