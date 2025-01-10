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

int getFactorsSum(int num) {
  int factorsSum = 1;
  for (int i = 2; i <= num / i; i++) {
    if (num % i == 0) {
      factorsSum += i;
      if (i != num / i) {
        factorsSum += num / i;
      }
    }
  }
  return factorsSum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> realNumber;
  for (int i = 1; i <= 10000; i++) {
    if (i == getFactorsSum(i)) {
      cout << i << " ";
      realNumber.push_back(i);
    }
  }
  cout << "\n";

  int bit = 0;
  while (1 << bit < 10000) {
    bit++;
  }
  for (auto x: realNumber) {
    for (int p = 0; p < bit; p++) {
      if (((1 << p) - 1) * (1 << (p - 1)) == x) {
        cout << p << " " << x << "\n";
      }
    }
  }

  return 0;
}

