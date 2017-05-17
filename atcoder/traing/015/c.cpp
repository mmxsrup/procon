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
int v[210], w[210];
ll dp[210000];
int main(void){
	cin >> N >> W;
	rep(i, N){
		cin >> v[i] >> w[i];
	}
	if(N <= 30){
		ll ans = 0;
		for (int mask = 0; mask < (1<<N); ++mask){
			ll sum = 0, tmp;
			rep(p, N)if(mask & (1<<p)) sum += w[p], tmp += v[p];
			if(sum <= W) chmax(ans, tmp);
		}
		cout << ans << endl;
		return 0;
	}
	
	rep(i, 210000) dp[i] = -1;
	dp[0] = 0;
	rep(i, N){
		for (int j = W; j >= 0; --j){
			if(dp[j] == -1) continue;
			if(j + w[i] <= W){
				chmax(dp[j + w[i]], dp[j] + v[i]);
			}
		}
	}
	ll ma = 0;
	rep(i, W + 1) chmax(ma, dp[i]);
	cout << ma << endl;
	return 0;
}