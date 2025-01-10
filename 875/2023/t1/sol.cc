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
  vector<int> countAge(51);
  for (int i = 0; i < n; i++) {
    int age;
    cin >> age;
    countAge[age]++;
  }
  for (int i = 0; i < 51; i++) {
    if (countAge[i] > 0) {
      cout << i << ":" << countAge[i] << "\n";
    }
  }

  return 0;
}