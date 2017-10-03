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

int n;
int p[110];
int dp[110][11000];

int main(void) {
	cin >> n;
	rep(i, n) cin >> p[i];
	dp[0] = 0;
	rep(i, n) {
		rep(j, 100000) {
			if(!dp[i]) continue;
			dp[i + 1][j] = 1;
			if(j + p[i] <= 11000) dp[i + 1][j + p[i]] = 1;
		}
	}
	int ans = 0;
	rep(i, 11000) if(dp[n][i]) ans++;
	printf("%d\n", ans);
	return 0;
}