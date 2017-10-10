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

int N; ll K;
int D[200100];
int memo[200100];

int main(void) {
	cin >> N >> K;
	rep(i, N) cin >> D[i];
	rep(i, N) D[i]--;

	rep(i, N) memo[D[i]] = i;
	ll cnt = 0;
	rep(i, N) {
		if(D[i] == i) continue;
		// printf("%d %d\n", D[i], D[memo[i]]);
		int tmp = D[i];
		swap(D[i], D[memo[i]]);
		memo[tmp] = memo[i];
		cnt++;
	}
	// printf("cnt %lld\n", cnt);

	if(K - cnt >= 0 && (K - cnt) % 2 == 0) printf("YES\n");
	else printf("NO\n");

	return 0;
}