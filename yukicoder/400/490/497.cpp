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
int X[1010], Y[1010], Z[1010];
int dp[1010][1010]; //i番目まで見て最後に使ったのがj

int main(void){
	cin >> N;
	X[0] = Y[0] = Z[0] = 0;
	reps(i, 1, N+1) cin >> X[i] >> Y[i] >> Z[i];
	int ret = 0;
	vector<tuple<int, int, int> > v;
	rep(i, N + 1){
		vector<int> t = {X[i], Y[i], Z[i]};
		sort(all(t));
		v.pb(make_tuple(t[0], t[1], t[2]));
	}
	sort(all(v));
	rep(i, v.size()){
		int x, y, z; tie(x, y, z) = v[i];
		X[i] = x, Y[i] = y, Z[i] = z;
		// printf("%d %d %d\n", X[i], Y[i], Z[i]);
	}
	/*
	int a = 0, b = 0, c = 0;
	rep(i, N){
		int x, y, z; tie(x, y, z) = v[i];
		// printf("%d %d %d\n", x, y, z);
		// printf("%d %d %d\n", a, b, c);
		if(a < x && b < y && c < z){
			ret++;
			a = x, b = y, c = z;
		}
	}
	*/
	rep(i, 1010)rep(j, 1010) dp[i][j] = -1;
	dp[0][0] = 0;
	rep(i, N)rep(j, N){ //j番目を最後に使った
		if(j > i) continue;
		if(dp[i][j] == -1)  continue;
		chmax(dp[i + 1][j], dp[i][j]); //i + 1を使わない
		// printf("%d %d\n", i, j);
		if(X[j] < X[i + 1] && Y[j] < Y[i + 1] && Z[j] < Z[i + 1]){
			// printf("2: %d %d\n", i, j);
			chmax(dp[i + 1][i + 1], dp[i][j] + 1);
		}
	}
	rep(i, 1010){
		chmax(ret, dp[N][i]);
	}
	cout << ret << endl;
	return 0;
}