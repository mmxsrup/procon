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

int N, M;
int A[1010], B[1010], C[1010];
int K;
int X[410], Y[410], Z[410];
ll dist[410][410];
void solve(void) {
	rep(k, N)rep(i, N)rep(j, N) {
		chmin(dist[i][j], dist[i][k] + dist[k][j]);
	}
}
ll count(void) {
	ll ret = 0;
	rep(i, N)rep(j, N) ret += dist[i][j];
	return ret;
}
void debuf(void) {
	printf("\n");
	rep(i, N){
		rep(j, N) {
			printf("%lld ", dist[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	cin >> N >> M;
	rep(i, M) cin >> A[i] >> B[i] >> C[i];
	cin >> K;
	rep(i, K) cin >> X[i] >> Y[i] >> Z[i];
	rep(i, M) A[i]--, B[i]--;
	rep(i, K) X[i]--, Y[i]--;
	rep(i, N)rep(j, N) dist[i][j] = INFF;
	rep(i, N) dist[i][i] = 0;
	rep(i, M) dist[A[i]][B[i]] = dist[B[i]][A[i]] = C[i];
	// debuf();
	solve();
	// debuf();
	// printf("%lld\n", count());

	rep(i, K) {
		chmin(dist[X[i]][Y[i]], Z[i]), chmin(dist[Y[i]][X[i]], Z[i]);
		rep(s, N)rep(t, N) {
			// s->X[i]->Y[i]->t
			ll d = dist[s][X[i]] + dist[X[i]][Y[i]] + dist[Y[i]][t];
			chmin(dist[s][t], d), chmin(dist[t][s], d);
		}
		printf("%lld\n", count() / 2);
	}
	return 0;
}