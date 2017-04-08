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
	priority_queue<ll> que;
	que.push(N);
	rep(i, K - 1){
		ll d = que.top(); que.pop();
		// printf("%lld\n", d);
		if(d % 2) que.push(d / 2), que.push(d / 2);
		else que.push(d / 2), que.push(max(0ll, d / 2 - 1));
	}
	ll ret = que.top();
	if(ret % 2){
		printf("%lld %lld\n", ret / 2, ret / 2);
	}else{
		printf("%lld %lld\n", ret / 2, max(0ll, ret / 2 - 1));
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