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
int t[110], v[110];
int sum[200010];
int memol[20010], memor[20010];
int tmpl[200010], tmpr[200010];

int main(void) {
	cin >> N;
	rep(i, N) cin >> t[i];
	rep(i, N) cin >> v[i];
	sum[0] = 0;
	rep(i, N) sum[i + 1] += sum[i] + t[i];
	rep(i, 200010) memo[i] = INF;
	memol[0] = memor[0] = memol[sum[N]] = memor[sum[N]] = 0;
	rep(i, N) {
		// reps(j, sum[i], sum[i + 1] + 1) chmin(memo[j], v[i]);
		reps(j, sum[i] + 1, sum[i + 1]) chmin(memol[j], v[i]), chmin(memor[j], v[i]);
		chmin(memor[sum[i]], v[i]), chmin(mmeol[sum[i + 1]], v[i]);

		// reps(j, sum[i], sum[i + 1] + 1) tmp[j] = v[i];
		reps(j, sum[i] + 1, sum[i + 1]) tmpl[j] = tmpr[j] = v[i];
		tmpr[sum[i]] = tmpl[sum[i + 1]] = v[i];
	}
	tmpl[0] = tmpr[0] = tmpl[sum[N]] = tmpr[sum[N]] = 0;


	/*
	printf("sum[N] %d\n", sum[N]);
	rep(i, sum[N] + 1) printf("%d ", memo[i]);
	printf("\n");
	*/

	rep(i, N + 1){
		for (int k = sum[i]; k >= 0; --k) {
			int dist = sum[i] - k;
			int dv = tmpr[sum[i]] + dist;
			if(dv > 100) break;
			chmin(memor[k], dv);
		}
	}
	printf("\n");
	rep(i, sum[N] + 1) printf("%d ", memo[i]);
	printf("\n");
	rep(i, N + 1){
		printf("sum %d tmp %d\n", sum[i], tmpl[sum[i]]);
		for (int k = sum[i]; k <= sum[N]; ++k) {
			int dist = k - sum[i];
			int dv = tmpl[sum[i]] + dist;
			if(dv > 100) break;
			chmin(memo[k], dv);
		}
	}
	rep(i, sum[N] + 1) printf("%d ", memo[i]);
	printf("\n");

	ll ans = 0;
	rep(i, sum[N] + 1) ans += memo[i];
	printf("%lld\n", ans);
	return 0;
}