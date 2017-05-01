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

int N, K;
double U;
double P[100];

void solve(void){
	cin >> N >> K;
	cin >> U;
	rep(i, N) cin >> P[i];

	double tmp = 0;
	rep(i, N){
		tmp += 1.0 - P[i];
	}
	if(tmp <= U){
		printf("1.000000\n");
		return;
	}

	double l = 0.0, r = 1.0;
	rep(i, 1000){
		double m = (l + r) / 2.0;
		double sum = 0;
		rep(k, N) sum += max(0.0, m - P[k]);
		if(sum <= U) l = m;
		else r = m;
	}

	// printf("%f %f\n", l, r);	
	double ans = 0.0;
	for (double i = min(1.0, l); i <= min(1.0, r); i += 0.0000001){
		double sum = 0;
		rep(k, N) sum += max(0.0, i - P[k]);
		double tmp = 1;
		if(sum <= U){
			rep(k1, N)tmp *= max(i, P[k1]);
		}
		chmax(ans, tmp);
	}
	printf("%.9f\n", ans);
}

int main(void){
	int T; cin >> T;
	rep(i, T){
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}