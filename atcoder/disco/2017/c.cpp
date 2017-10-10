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
ll C;
ll L[100010];
int main(void) {
	cin >> N >> C;
	rep(i, N)cin >> L[i];
	sort(L, L + N);
	ll ans = N;
	int l = 0, r = N - 1;
	while(r  > l) {
		// printf("l %d r %d\n", l, r);
		if(L[r] + L[l] + 1 <= C) {
			ans--;
			r--;
			l++;
		}else {
			r--;
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}