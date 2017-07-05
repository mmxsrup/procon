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


int N, W;
int w[210];
int sum[210];
ll dp[10010];

int main(void) {
	scanf("%d %d", &N, &W);
	rep(i, N) scanf("%d", &w[i]);
	sort(w, w + N);
	rep(i, N) sum[i + 1] = sum[i] + w[i];

	ll ans = 0;
	for (int i = 0; i < N - 2; ++i) { // i番目までをすべて選ぶ
		rep(j, 10010) dp[j] = 0;
		dp[0] = 1;
		for (int j = i + 2; j < N; ++j) { // i + 1番目を選ばないで, i + 2番目以降を任意で選ぶ
			for (int k = W; k >= 0; --k) {
				if(k - w[j] < 0) continue;
				(dp[k] += dp[k - w[j]]) %= MOD;
			}
		}

		ll nokori = W - sum[i + 1];
		if(nokori < 0) continue;
		printf("nokori %lld\n", nokori);
		ll mi = w[i + 1]; // 選ばない奴の最小値
		for (int j = nokori - mi + 1; j <= nokori; ++j) {
			(ans += dp[j]) %= MOD;
		}
	}


	printf("%lld\n", ans % MOD);
	return 0;
}