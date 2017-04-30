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
long double U;
long double P[100];

void solve(void){
	cin >> N >> K;
	cin >> U;
	rep(i, N) cin >> P[i];
	double tmp = 0;
	rep(i, N){
		tmp += 1.0 - P[i];
	}
	long double ans = 0.0;
	for (long double i = 0; i <= 1.0; i += 0.00001){
		long double sum = 0;
		rep(k, N){
			sum += max((long double)0.0, i - P[k]);
		}
		if(sum <= U){
			chmax(ans, pow(i, N));
		}else{
			break;
		}
	}
	cout << ans << endl;
}

int main(void){
	int T; cin >> T;
	rep(i, T){
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}