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
// #define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

ll N, K;
ll a[100010];
ll sum;
ll up[100010];
ll down[100010];
int main(void){
	cin >> N >> K;
	reps(i, 1, N + 1) cin >> a[i];
	reps(i, 1, N + 1)if(a[i] > 0)sum += a[i];
	reps(i, 1, N + 1) if(a[i] > 0) up[i] = a[i];
	reps(i, 1, N) up[i + 1] += up[i];
	reps(i, 1, N + 1) if(a[i] < 0) down[i] = a[i];
	reps(i, 1, N) down[i + 1] += down[i];

	// printf("sum %ld\n", sum);
	ll ans = 0;
	reps(i, 1, N - K + 2){
		ll black = down[i + K - 1] - down[i - 1];
		chmax(ans, sum + black);
		ll white = up[i + K - 1] - up[i - 1];
		chmax(ans, sum - white);
		// printf("%lld %lld\n", black, white);
	}
	printf("%lld\n", ans);
	return 0;
}