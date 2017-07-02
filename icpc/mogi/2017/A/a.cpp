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
#define chmax(a, b) a = max(a, b);
#define chmin(a, b) a = min(a, b);
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int main(void) {
	while(1){
		int N, M; cin >> N >> M;
		if(N == 0 && M == 0) break;
		int memo[110];
		rep(i, 110) memo[i] = 0;
		rep(i, N){
			int d, v; cin >> d >> v;
			chmax(memo[d], v);
		}
		ll ans = 0;
		reps(i, 1, M + 1) ans += memo[i];
		cout << ans << endl;
	}
	return 0;
}