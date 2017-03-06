/*
dp臭
ナップサック問題に商品の個数の制約を追加した問題
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int main() {
  int w, N, K;
  cin >> w >> N >> K;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];

  vector<vector<vector<int>>> dp(
      N + 1, vector<vector<int>>(K + 1, vector<int>(W + 1, -1)));
  dp[0][0][0] = 0;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int k = 0; k < K; ++k) {
      for (int w = 0; w <= W; ++w) {
        if (dp[i][k][w] < 0) continue;
        dp[i + 1][k][w] = max(dp[i + 1][k][w], dp[i][k][w]);
        if (w + A[i] <= W) {
          dp[i + 1][k + 1][w + A[i]] =
              max(dp[i + 1][k + 1][w + A[i]], dp[i][k][w] + B[i]);
          ans = max(ans, dp[i + 1][k + 1][w + A[i]]);
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}