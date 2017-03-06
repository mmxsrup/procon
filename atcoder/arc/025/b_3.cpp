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

int H, W;
int C[100][100];
int sum[100][100];

int solve() {
  rep(i, H) rep(j, W) {
    if(i > 0) sum[i][j] += sum[i - 1][j];
    if(j > 0) sum[i][j] += sum[i][j - 1];
    if(i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];
    sum[i][j] += ((i + j) % 2 ? 1 : -1) * C[i][j];
  }

  for (int i = 0; i < H; ++i){
    for (int j = 0; j < W; ++j){
      printf("%d ", sum[i][j]);
    }
    printf("\n");
  }

  int ans = 0;
  rep(i, H) rep(j, W) REP(ii, i, H) REP(jj, j, W) {
    int total = sum[ii][jj];
    if(i > 0) total -= sum[i - 1][jj];
    if(j > 0) total -= sum[ii][j - 1];
    if(i > 0 && j > 0) total += sum[i - 1][j - 1];
    if(total == 0) ans = max(ans, (ii - i + 1) * (jj - j + 1));
  }

  return ans;
}

int main() {
  // ios_base::sync_with_stdio(false);
  cin >> H >> W;
  rep(i, H) rep(j, W) cin >> C[i][j];
  cout << solve() << endl;
  return 0;
}