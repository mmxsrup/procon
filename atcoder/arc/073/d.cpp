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

int N;
ll W, w[110];
ll v[110];

// int dp[110][1000000000]
map<ll, ll> dp[110];

int main(void){
	cin >> N >> W;
	rep(i, N) cin >> w[i] >> v[i];
	dp[0][0] = 0;
	rep(i, N){
		for(auto tmp : dp[i]){
			//dp[i][weight] = value
			ll weight = tmp.fi, value = tmp.se; //今までの重さと価格の最大値
			if(dp[i + 1].count(weight + w[i]) == 0 || dp[i + 1][weight + w[i]] < dp[i][weight] + v[i]){
				// printf("%lld\n", dp[i][weight] + v[i]);
				dp[i + 1][weight + w[i]] = dp[i][weight] + v[i];
			}
			if(dp[i + 1].count(weight) == 0 || dp[i + 1][weight] < dp[i][weight]){
				// printf("%lld\n", dp[i][weight] + v[i]);
				dp[i + 1][weight] = dp[i][weight];
			}
		}
	}
	ll ans = 0;
	for(auto tmp : dp[N]){
		ll weight = tmp.fi, value = tmp.se; //今までの重さと価格の最大値
		if(weight > W) continue;
		chmax(ans, value);
	}
	cout << ans << endl;
	return 0;
}