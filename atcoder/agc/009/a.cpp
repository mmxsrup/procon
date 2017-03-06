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

int n;
ll a[100010], b[100010];
int main(void){
	cin >> n;
	rep(i, n){
		scanf("%lld %lld", &a[i], &b[i]);
	}
	ll ans = 0;
	for (int i = n - 1; i >= 0; --i){
		a[i] += ans;
		if(a[i] % b[i] != 0){
			ll d = b[i] - (a[i] % b[i]);
			ans += d;
		}
	}
	printf("%lld\n", ans);
	return 0;
}