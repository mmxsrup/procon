#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=n-1;i>=(0);i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

double dp[1000010][10];

int main(void) {
	int N; cin >> N;
	dp[0][0] = 1.0;
	rep(i, N)rep(j, 7) {
		dp[i + 1][j] += dp[i][j] * ((double)j / 6.); // 同じ
		if(j == 6) continue;
		dp[i + 1][j + 1] += dp[i][j] * ((double)(6 - j) / 6.); // 新しいのでる
	}
	printf("%.9f\n", dp[N][6]);
	return 0;
}