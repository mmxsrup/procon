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

int N, K;
int a[20];

int main(void){
	cin >> N >> K;
	rep(i, N) cin >> a[i];

	ll ret = INFF;
	for (int mask = 0; mask < (1 << N); ++mask){
		int cnt = 0;
		for (int pos = 0; pos < N; ++pos){
			if((mask & (1 << pos)) != 0) cnt++;
		}
		if(cnt != K) continue;
		int ma = 0;
		ll ans = 0;
		bool ff = true;
		for (int pos = 0; pos < N; ++pos){
			if((mask & (1 << pos)) != 0){
				if(ff){
					ma = a[pos];
					ff = false;
				}else{
					// ans += max(0, (ma + 1) - a[pos]);
					if(ma < a[pos]){
						ma = a[pos];
					}else{
						ans += (ma + 1) - a[pos];
						ma++;
					}
					// printf("ma %d\n", ma);
				}
			}else{
				ff = false;
				chmax(ma, a[pos]);
			}
		}
		chmin(ret, ans);
	}
	printf("%lld\n", ret);
	return 0;
}