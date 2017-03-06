#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;

int n, k;
ll a[100010];
int main(void){
	cin >> n >> k;
	rep(i, n) cin >> a[i];

	ll sum = 0;
	ll ans = 0;
	rep(i, k) sum += a[i];
	ans += sum;
	int l = 0, r = k;
	while(r < n){
		sum -= a[l];
		sum += a[r];
		ans += sum;
		l++;
		r++;
	}
	printf("%lld\n", ans);
	return 0;
}