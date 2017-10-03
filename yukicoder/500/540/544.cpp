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

bool check(ll k) {
	bool f = true;
	for(auto d : to_string(k)) {
		if(d == '7') f = false;
	}
	return f;
}

int main(void) {
	ll n; cin >> n;
	ll a, b;
	while(1) {
		a = rand() % (2 * INF - 1) -INF;
		b = n - a;
		if(a > INF or b > INF) continue;
		if(check(a) && check(b)) {
			printf("%lld %lld\n", a, b);
			break;
		}
		a++, b--;
	}
	return 0;
}