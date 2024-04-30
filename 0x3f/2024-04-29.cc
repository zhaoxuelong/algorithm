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

// https://codeforces.com/problemset/problem/1365/c
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n), b(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x - 1] = i;
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b[(i - a[x - 1] + n) % n]++;
  }
  cout << *max_element(b.begin(), b.end()) << "\n";

  return 0;
}

