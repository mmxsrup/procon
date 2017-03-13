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

int n, c, k;
int main(void){
	cin>> n >> c >> k;
	vint t(n);
	rep(i, n) cin >> t[i];
	sort(all(t));
	ll ans = 0;
	int l = 0, r = 1; //[l, r)
	while(l < n){
		// printf("1 : %d %d\n", l, r);
		while(r - l < c and r < n and t[l] + k >= t[r]) r++;
		// printf("2 : %d %d\n", l, r);
		ans++;
		l = r;
		r++;
		// printf("3 : %d %d\n", l, r);

	}
	printf("%lld\n", ans);
	return 0;
}