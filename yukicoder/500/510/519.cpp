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
int F[30][30];
int dp[(1 << 26)];
int main(void){
	cin >> n;
	rep(i, n)rep(j, n) cin >> F[i][j];
	rep(i, (1<<26)) dp[i] = -1;
	dp[0] = 0;
	for (int mask = 0; mask < (1<<n) - 1; ++mask){
		if(dp[mask] == -1) continue;
		int tmpmask = mask;
		int p1;
		rep(i, n)if((mask & (1<<i)) == 0){
			p1 = i; break;
		}
		tmpmask |= (1<<p1);
		rep(p2, n)if((tmpmask & (1<<p2)) == 0){
			chmax(dp[tmpmask | (1<<p2)], dp[mask] + F[p1][p2]);
		}
	}
	printf("%d\n", dp[(1<<n) - 1]);
	return 0;
}