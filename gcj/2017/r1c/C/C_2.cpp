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
	priority_queue<double, vector<double>, greater<double> > p; // 小さい順
	rep(i, N){
		p.push(P[i]);
	}
	while(U >= 0.0001){
		auto d = p.top(); p.pop();
		p.push(d + 0.0001);
		U -= 0.0001;
	}
	double ans = 1.0;
	while(!p.empty()){
		auto d = p.top(); p.pop();
		// printf("%f\n", d);
		ans *= d;
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