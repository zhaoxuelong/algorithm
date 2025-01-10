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

int n, c;
vector<int> s;
vector<int> path;
vector<bool> visited;
// 爆搜
void dfs(int i, int sum) {
  if (sum > c) return;
  if (i == n) {
    if (sum == c) {
      for (int x: path) {
        cout << x << " ";
      }
      cout << "\n";
    }
    return;
  }
  for (int nxt = i; nxt < n; nxt++) {
    if (!visited[nxt]) {
      visited[nxt] = true;
      path.push_back(nxt);
      dfs(nxt, sum + s[nxt]);
      path.pop_back();
      visited[nxt] = false;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> c;
  s.resize(n);
  visited.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  dfs(0, 0);

  return 0;
}