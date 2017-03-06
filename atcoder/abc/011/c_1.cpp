/*
貪欲法やメモ化再帰などで解くことができる。
貪欲法で解いたほうがシンプルかと思われる。
NGな値を避けつつ各試行でなるべく大きな値を引いていくようにしていけばよい。

メモ化再帰では現在の数と何回目の試行かを持たせておけばよい。

下のコードでコメントアウトしてるほうがメモ化再帰による解法。
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <sstream>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cctype>
#include <cassert>
#include <cstring>

using namespace std;

#define REP(i, x, n) for(int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back

typedef pair<int,int> P;
typedef long long int lli;

int N;
bool NG[301];

string solve() {
  if(!NG[N]) {
    rep(i, 100) {
      if(N - 3 >= 0 && !NG[N - 3]) N -= 3;
      else if(N - 2 >= 0 && !NG[N - 2]) N -= 2;
      else if(N - 1 >= 0 && !NG[N - 1]) N -= 1;
      else break;
    }
  }
  return N ? "NO" : "YES";
}

int main() {
  cin >> N;
  rep(i, 3) {
    int idx;
    cin >> idx;
    NG[idx] = true;
  }
  cout << solve() << endl;
}

// int N;
// int NG[3];
// bool used[301][101];

// void dfs(int n, int count) {
//   rep(i, 3) if(n == NG[i]) return;
//   used[n][count] = true;
  
//   if(count == 100) return;
  
//   rep(i, 3) {
//     int v = n - 1 - i;
//     if(v >= 0 && !used[v][count + 1]) {
//       dfs(v, count + 1);
//     }
//   }
// }

// int main() {
//   // ios_base::sync_with_stdio(false);
//   cin >> N;
//   rep(i, 3) cin >> NG[i];
//   dfs(N, 0);
//   bool flag = false;
//   rep(i, 101) if(used[0][i]) flag = true;
//   if(flag) cout << "YES" << endl;
//   else cout << "NO" << endl;
//   return 0;
// }