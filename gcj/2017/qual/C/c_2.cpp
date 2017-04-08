#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpinAt;
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

void solve(void){
	ll N, K; cin >> N >> K;
	int depth = 0; ll tmpK = K;
	while(tmpK > 0) depth++, tmpK >>= 1;
	depth--;
	// printf("depth %d\n", depth);
	ll d1 = N, d2 = 0, num1 = 1, num2 = 0;
	rep(i, depth){
		// printf("%lld %lld %lld %lld\n", d1, d2, num1, num2);
		if(num1 > 0 && num2 > 0){
			if(d1 % 2){
				d1 /= 2;
				num1 = num1 * 2 + num2;
				d2 = max(d2 / 2 - 1, 0ll);
				num2 = num2;
			}else{
				d1 /= 2;
				d2 /= 2;
				num2 = num2 * 2 + num1;
			}
		}else{
			if(d1 % 2){
				d1 /= 2;
				num1 = num1 * 2;
				num2 = 0;
			}else{
				d2 = max(d1 / 2 - 1, 0ll);
				num2 = num1;
				d1 /= 2;
				num1 = num1;
			}
		}
	}
	// printf("%lld %lld %lld %lld\n", d1	, d2, num1, num2);
	ll index = K - pow(2, depth) + 1;
	// printf("%lld\n", index);
	if(index <= num1){
		if(d1 % 2){
			printf("%lld %lld\n", d1 / 2, d1 / 2);
		}else{
			printf("%lld %lld\n", d1 / 2, max(d1 / 2 - 1, 0ll));
		}
	}else{
		if(d2 % 2){
			printf("%lld %lld\n", d2 / 2, d2 / 2);
		}else{
			printf("%lld %lld\n", d2 / 2, max(d2 / 2 - 1, 0ll));
		}
	}

	return;
}

int main(void){
	int T; cin >> T;
	rep(i, T){
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}