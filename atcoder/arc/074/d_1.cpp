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
int a[300010];
vector<ll> memof, memob;

int main(void) {
	cin >> N;
	rep(i, 3 * N) cin >> a[i];
	priority_queue<int, vector<int>, greater<int>> q1;
	ll f = 0;
	rep(i, N) q1.push(a[i]), f += a[i];
	memof.pb(f);
	reps(i, N, 2 * N){
		q1.push(a[i]);
		int mi = q1.top(); q1.pop();
		f = f - mi + a[i];
		memof.pb(f);
	}
	priority_queue<int> q2;
	ll b = 0;
	reps(i, 2 * N, 3 * N) q2.push(a[i]), b += a[i];
	memob.pb(b);
	for (int i = 2 * N - 1; i >= N; --i){
		q2.push(a[i]);
		int ma = q2.top(); q2.pop();
		b = b - ma + a[i];
		memob.pb(b);
	}
	reverse(all(memob));

	/*
	rep(i, N + 1)printf("%lld ", memof[i]);
	printf("\n");
	rep(i, N + 1)printf("%lld ", memob[i]);
	printf("\n");
	*/
	
	ll ans = -INFF;
	rep(i, N + 1) chmax(ans, memof[i] - memob[i]);
	printf("%lld\n", ans);
	return 0;
}