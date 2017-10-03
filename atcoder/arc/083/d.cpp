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
int A[310][310];

int main(void) {
	cin >> N;
	rep(i, N)rep(j, N) cin >> A[i][j];
	ll ans = 0;
	bool flag = true;
	rep(i, N)reps(j, i + 1, N) {
		// i -> jが隣り合う頂点かしらべる
		ll mi = INFF;
		// printf("i %d j %d\n", i, j);
		rep(k, N) {
			if(i == k || j == k) continue;
			chmin(mi, A[i][k] + A[k][j]);
		}
		// printf("mi %lld\n", mi);
		if(A[i][j] < mi) ans += A[i][j];
		else if(A[i][j] > mi)flag = false;
	}
	if(!flag) printf("-1\n");
	else printf("%lld\n", ans);
	return 0;
}