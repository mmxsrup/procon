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

int n, c, v;
ll dp[100010]; // dp[i] := 文字数をiとするために必要なコストの最小値

int main(void) {
	cin >> n >> c >> v;
	rep(i, 100010) dp[i] = INFF;
	dp[1] = 0;
	for (int i = 0; i < 30; ++i) {
		// printf("i %d\n", i);
		for (int j = n - 1; j >= 1; --j) {
			if(dp[j] == INFF) continue;
			int d = j, now = j, cnt = 1;
			while(now <= n) {
				chmin(dp[now + d], dp[d] + c + cnt * v);
				now += d;
				cnt++;
			}
		}
		/*
		rep(i, 8) {
			printf("dp[%d] = %lld\n", i, dp[i]);
		}
		*/
	}

	ll ans = INFF;
	for (int i = n; i <= 2 * n; ++i) {
		chmin(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}