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
int a[2500], b[2500];

int main(void) {
	cin >> N >> M;
	rep(i, N) cin >> a[i] >> b[i];
	set<pair<int, int>> st;
	rep(i, N) st.insert(mp(a[i], b[i]));

	int ans = 0;
	int size = N / 2;
	for (int mask = 0; mask < (1 << size); ++mask) {
		int add = 0;
		for (int i = 0; i < size; ++i) {
			bool f = true;
			for (int j = size; j < N; ++j) {
				if(st.count(mp(i, j))) f = false;
			}
			if(f) add++;
		}
		chmax(ans, add + __builtin_popcount(mask));
	}
	printf("%lld\n", ans);
	return 0;
}