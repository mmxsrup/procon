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
ll T;
ll t[200010];
int main(void){
	cin >> N >> T;
	rep(i, N) cin >> t[i];

	ll ans = T;
	ll now = T;
	reps(i, 1, N){
		if(t[i] - t[i - 1] > T){
			// printf("k %d\n", t[i]);
			now = t[i] + T;
			ans += T;
		}else{
			ll now1 = t[i] + T;
			ans += now1 - now;
			now = now1;
		}
		// printf("%lld %lld\n", now, ans);
	}
	cout << ans << endl;
	return 0;
}