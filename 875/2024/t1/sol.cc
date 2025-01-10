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

vector<int> getFactors(int num) {
  vector<int> factors{1};
  for (int i = 2; i <= num / i; i++) {
    if (num % i == 0) {
      factors.push_back(i);
      if (num / i != i) {
        factors.push_back(num / i);
      }
    }
  }
  return factors;
}
int getFactorsSum(int num) {
  auto factors = getFactors(num);
  return accumulate(factors.begin(), factors.end(), 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i <= 10000; i++) {
    int a = i, b = getFactorsSum(a);
    if (a == getFactorsSum(b)) {
      cout << a << ": ";
      auto factors = getFactors(a);
      for (auto x: factors) {
        cout << x << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}