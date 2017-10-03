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

int A, B, C, D, E, F;
int dp[3010][3010]; // dp[i][j] := 水i, 砂糖jを作れれば1

int main(void) {
	cin >> A >> B >> C >> D >> E >> F;
	dp[0][0] = 1;
	rep(i, 3001)rep(j, 3001) {
		if(i + j > F) continue;
		if(!dp[i][j]) continue;
		reps(k, 1, 3001) {
			if(i + (100 * A) * k <= F) dp[i + (100 * A) * k][j] = 1;
			else break;
		}
		reps(k, 1, 3001) {
			if(i + (100 * B) * k <= F) dp[i + (100 * B) * k][j] = 1;
			else break;
		}
		reps(k, 1, 3001) {
			if(j + C * k <= F)dp[i][j + C * k] = 1;
			else  break;
		}
		reps(k, 1, 3001){
			if(j + D * k <= F)dp[i][j + D * k] = 1;
			else break;
		}

	}

	double ma = 0;
	pint ans;
	rep(i, 3001)rep(j, 3001) {
		if(i + j > F) continue;
		if(dp[i][j]) {
			// printf("%d %d\n", i, j);
			if(i / 100 * E < j) continue;
			if(ma < (double)j / (double)(i + j)) {
				ma = (double)j / (double)(i + j);
				ans = mp(i + j, j);
			}
		}
	}
	cout << ans.fi << " " << ans.se << endl;
	return 0;
}