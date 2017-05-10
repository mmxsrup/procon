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

int N, P;
int R[55];

void solve(void){
	vector<int> Q[55];
	cin >> N >> P;
	rep(i, N) cin >> R[i];
	rep(i, N){
		rep(j, P){
			int d; cin >> d;
			// printf("d %d\n",d );
			Q[i].pb(d);
		}
		sort(all(Q[i]));
		// for(auto u : Q[i]) printf("%d ", u);
		// printf("\n");	
	}

	int dp[10][10];
	rep(i, 10)rep(j, 10) dp[i][j] = 0;

	rep(i, P)rep(j, P){
		// printf("ij %d %d\n", i, j);
		int d1 = Q[0][i] / R[0];
		for (int k = max(1, d1 - 100); k <= d1 + 1; ++k){ // k ko tukuru
			/*
			double c1 = k * R[0], c2 = k * R[1];
			double left1 = c1 * 0.9, right1 = c1 * 1.1;
			double left2 =  c2 * 0.9, right2 = c2 * 1.1;
			// cout << left1 << " " << Q[0][0] << " " << right1 << endl;
			chmax(dp[i + 1][j + 1], max(dp[i + 1][j], dp[i][j + 1]));
			if(left1 <= Q[0][i] && Q[0][i] <= right1 && left2 <= Q[1][j] && Q[1][j] <= right2){
				// printf("k\n");
				chmax(dp[i + 1][j + 1], dp[i][j] + 1);
			}
			*/
			bool flag = true;
			rep(num, N){
				double c = k * R[num];
				double l = c * 0.9, r = c * 1.1;
				if(!(l <= Q[num][i] && Q[num][i] <= r)){
					flag = false;
					break;
				}
			}
			chmax(dp[i + 1][j + 1], max(dp[i + 1][j], dp[i][j + 1]));
			if(flag){
				chmax(dp[i + 1][j + 1], dp[i][j] + 1);
			}
		}
	}
	printf("%d\n", dp[P][P]);
	return;
}

int main(void){
	int T; cin >> T;
	rep(i, T){
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}