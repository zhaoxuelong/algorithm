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

int countChar[256];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t;
  cin >> s >> t;
  for (auto c: s) {
    countChar[c]++;
  }
  for (auto c: t) {
    countChar[c]--;
  }
  for (int i = 0; i < 256; i++) {
    if (countChar[i] != 0) {
      cout << false << "\n";
      return 0;
    }
  }
  cout << true << "\n";

  return 0;
}