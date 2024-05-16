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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<bool> not_prime(n + 1);
  vector<int> ans;
  for (int i = 2; i <= n; i++) {
    if (not_prime[i]) {
      continue;
    }
    for (int j = i; j <= n; j *= i) {
      ans.push_back(j);
    }
    for (int j = i * i; j <= n; j += i) {
      not_prime[j] = true;
    }
  }
  cout << ans.size() << "\n";
  for (auto x: ans) {
    cout << x << " ";
  }
  cout << "\n";

  return 0;
}

