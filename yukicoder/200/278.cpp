#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
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

int main(void){
	ll n; cin >> n;
	ll ma;
	if(n % 2 == 0){
		ma = n / 2;
	}else{
		ma = n;
	}

	ll ans = 0;

	for (ll i = 1; i <= sqrt(ma) + 1; ++i){
		if(ma % i == 0){
			if(i == ma / i) ans += i;
			else ans += i + ma / i;
		}
	}
	//(sqrt(n)以上の素数は1or0)

	printf("%lld\n", ans);
	return 0;
}