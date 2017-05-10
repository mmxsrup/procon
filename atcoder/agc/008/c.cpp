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

ll a[7];

int main(void){
	rep(i, 7) cin >> a[i];
	ll ans = 0;
	ans += 2 * (a[0] / 2);
	ans += 1 * a[1];
	ans += 2 * (a[3] / 2);
	ans += 2 * (a[4] / 2);
	
	ll ans1 = 0;
	if(a[0] > 0 && a[3] > 0 && a[4] > 0){
		ans1 += 3;
		a[0]--; a[3]--; a[4]--;
	}
	ans1 += 2 * (a[0] / 2);
	ans1 += 1 * a[1];
	ans1 += 2 * (a[3] / 2);
	ans1 += 2 * (a[4] / 2);
	printf("%lld\n", max(ans1, ans));
	return 0;
}