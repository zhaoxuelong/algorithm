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

  int commodity_num;
  cin >> commodity_num;
  vector<int> p(commodity_num);
  for (int i = 0; i < commodity_num; i++) {
    cin >> p[i];
  }
  int price;
  cin >> price;
  vector<int> dp(price + 1);
  dp[0] = 1;
  for (int i = 0; i < commodity_num; i++) {
    for (int j = price; j >= p[i]; j--) {
      dp[j] += dp[j - p[i]];
    }
  }
  cout << dp[price] << "\n";

  return 0;
}

