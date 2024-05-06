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

const int MAXN = 3 * (int)ceil(sqrt(1e9));

void solveOne() {
  int a, b;
  cin >> a >> b;
  if (a > b) {
    swap(a, b);
  }
  int ans = 1e9;
  for (int i = 1; i <= MAXN; i++) {
    ans = min(ans, i - 1 + (a + i - 1) / i + (b + i - 1) / i); 
  }
  cout << ans << "\n";
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
