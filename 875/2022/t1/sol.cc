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
  // {分数、颜色}
  vector<pair<int, char>> team(n);
  int countB = 0, countG = 0, countP = 0, countR = 0;
  for (int i = 0; i < n; i++) {
    cin >> team[i].first >> team[i].second;
    if (team[i].second == 'b') {
      countB++;
    } else if (team[i].second == 'g') {
      countG++;
    } else if (team[i].second == 'P') {
      countP++;
    } else if (team[i].second == 'r') {
      countR++;
    }
  }
  sort(team.begin(), team.end());
  cout << "blue" << " " << countB << "\n";
  cout << "green" << " " << countG << "\n";
  cout << "purple" << " " << countP << "\n";
  cout << "red" << " " << countR << "\n";
  for (int i = 0; i < n; i++) {
    cout << team[i].first << " " << team[i].second << "\n";
  }

  return 0;
}