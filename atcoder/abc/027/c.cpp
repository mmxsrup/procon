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

int dfs(ll now, int cnt, int f, ll n){
	// printf("%lld %d %d %lld \n", now, cnt, f, n);
	if(now > n) return cnt;
	if(f){
		if(cnt % 2 == 0) return dfs(now * 2, cnt + 1, f, n);
		else dfs(now * 2 + 1, cnt + 1, f, n);
	}else{
		if(cnt % 2 == 1) return dfs(now * 2, cnt + 1, f, n);
		else dfs(now * 2 + 1, cnt + 1, f, n);
	}
}

int main(void){
	ll n, _n;
	cin >> n; _n = n;
	if(n == 1){
		printf("Aoki\n"); return 0;
	}
	int depth = 1;
	/*
	ll d = 2;
	while(_n > 0){
		_n /= d;
		d *= 2;
		depth++;
	}
	*/
	for (int N = n; N > 0; N /= 2){
		depth++;
	}
	// printf("depth %d\n", depth);
	int ret;
	if(depth % 2 == 1){
		//takahashi hidari / aoki migi
		ret = dfs(1, 0, 1, n);
	}else{
		//takahashi migi / aoki hidari
		ret = dfs(1, 0, 0, n);
	}
	if(ret % 2) printf("Aoki\n");
	else printf("Takahashi\n");
	return 0;
}