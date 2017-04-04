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

/*
K=2 0, 1, 3, 7
K=3 0, 1, 2, 4, 7, 11, 17
K=4 0, 1, 2, 3, 5, 7, 10, 14, 19
*/
int N, k;
bool slv(ll x){
	bool f = true;
	rep(i, N - 1){
		x -= x / k + 1;
		if(x < 0){
			f = false; break;
		}
	}
	return f ? true : false;
}

bool ok(ll x){
	rep(i, N - 1){
		x -= x / k + 1;
		if(x < 0){
			break;
		}
	}
	return (x == 0) ? true : false;
}

int main(void){
	cin >> N >> k;
	ll l = 0, r = INFF + 1;
	while(r - l > 1){
		ll m = (l + r) / 2;
		if(slv(m)) r = m; //大きすぎた
		else l = m; // 小さすぎた
	}
	while(1){
		if(ok(l)){
			printf("%lld\n", l); break;
		}
		l++;
	}

	return 0;
}