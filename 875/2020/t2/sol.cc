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

int reverseNumber(int num) {
  int reverseNum = 0;
  while (num > 0) {
    int d = num % 10;
    num /= 10;
    reverseNum = reverseNum * 10 + d;
  }
  return reverseNum;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  bool isNone = true;
  while (n--) {
    int a, b;
    cin >> a >> b;
    int reverseA = reverseNumber(a);
    int reverseB = reverseNumber(b);
    int reverseAB = reverseNumber(a + b);
    if (reverseA + reverseB == reverseAB) {
      isNone = false;
      cout << a << " " << b << "\n";
    }
  }
  if (isNone) {
    cout << "none" << "\n";
  }

  return 0;
}

