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


int X, Y, Z;
ll A[100010], B[100010], C[100010];

signed main(void) {
	cin >> X >> Y >> Z;
	rep(i, X + Y + Z) cin >> A[i] >> B[i] >> C[i];

	vector<pair<ll, int>> v;
	rep(i, X + Y + Z) {
		v.pb(make_pair(A[i] - B[i], i));
	}
	sort(all(v)); reverse(all(v));


	ll sumF = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int> >> pA;
	vector<ll> memoF;
	rep(i, X) {
		int idx = v[i].se;
		sumF += A[idx];
		pA.push(mp(A[idx] - C[idx], idx));
	}
	memoF.pb(sumF);
	reps(i, X, X + Z) {
		int idx = v[i].se;
		pA.push(mp(A[idx] - C[idx], idx));
		int minidx = pA.top().se; pA.pop();
		sumF += A[idx] - A[minidx] + C[minidx];
		memoF.pb(sumF);
	}

	ll sumB = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int> >> pB;
	vector<ll> memoB;
	for (int i = X + Y + Z - 1; i > X + Z - 1; --i) {
		int idx = v[i].se;
		sumB += B[idx];
		pB.push(mp(B[idx] - C[idx], idx));
	}
	memoB.pb(sumB);
	for (int i = X + Z - 1; i >= X; --i) {
		int idx = v[i].se;
		pB.push(mp(B[idx] - C[idx], idx));
		int minidx = pB.top().se; pB.pop();
		sumB += B[idx] - B[minidx] + C[minidx];
		memoB.pb(sumB);
	}
	reverse(all(memoB));

	ll ans = 0;
	rep(i, memoF.size()) {
		chmax(ans, memoF[i] + memoB[i]);
	}
	printf("%lld\n", ans);
	return 0;
}