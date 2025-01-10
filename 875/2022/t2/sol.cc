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

  int w = 0;
  vector<int> a;
  for (int i = 0; i < 5; i++) {
    string s;
    cin >> s;
    int num;
    if (s == "W") {
      w++;
      continue;
    } else if (s == "A") {
      num = 1;
    } else if (s == "J") {
      num = 11;
    } else if (s == "Q") {
      num = 12;
    } else if (s == "K") {
      num = 13;
    } else if (s == "10") {
      num = 10;
    } else {
      num = s[0] - '0';
    }
    a.push_back(num);
  }
  sort(a.begin(), a.end());
  int m = a.size();
  for (int i = 1; i < m; i++) {
    if (a[i] == a[i - 1] || a[i] - a[i - 1] - 1 > w) {
      cout << false << "\n";
      return 0;
    }
    w -= a[i] - a[i - 1] - 1;
  }
  cout << true << "\n";

  return 0;
}