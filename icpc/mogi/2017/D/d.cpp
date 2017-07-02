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
#define chmax(a, b) a = max(a, b);
#define chmin(a, b) a = min(a, b);
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int N, M;
ll s[100010];
bool solve(ll X){
	// printf("X %lld\n", X);
	ll L = 1;
	ll cnt = 0;
	bool flag = true;
	while(flag){
		cnt++;
		

		if(L + X > s[N - 1]){
			flag = false;
			break; // 最強倒した
		}

		int idx = lower_bound(s, s + N, L) - s;
		vector<ll> v;
		for (int i = max(0, idx - 100); i <= min(idx + 100, N - 1); ++i) {
			// printf("add %d\n", X - abs(L - s[i]));
			if(L + X > s[i]){
				v.pb(X - abs(L - s[i]));
				// printf("add %d\n", X - abs(L - s[i]));
			}
		}
		// printf("size %d\n", v.size());

		sort(all(v)); reverse(all(v));
		if(v.size() < 1) break;
		 
		/*
		rep(i, N){
			// printf("i %d\n",i );
			if(L + X <= s[i]) break;

			if(i == N - 1){
				flag = false;
				break; // 最強倒した
			}
			chmax(up, X - abs(L - s[i]));
		}
		*/
		// printf("%lld up %lld\n", cnt, up);
		
		// printf("%lld up %lld size %d \n", cnt, v[0], v.size());
		// if(cnt > 10) break;
		L += max(1ll, v[0]);
		// printf("L %d\n", L);
	}
	if(cnt >= M){	
		// printf("k\n");
		return true;
	}else return false;
}

int main(void) {
	while(1){
		scanf("%d %d", &N, &M);
		if(N == 0 && M == 0) break;


		rep(i, N) scanf("%d", &s[i]);
		// printf("inputfin\n");

		// check
		
		if(!solve(s[0])) {
			printf("-1\n");
			continue;
		}
		
		
		

		ll l = s[0], r = s[N - 1] + 1;
		while(r - l > 1) {
			ll m = (l + r) / 2;
			// printf("m %lld\n", m);
			if(solve(m)){
				l = m;
			}else{
				r = m;
			}
			// printf("m:%lld %lld %lld\n", m, l, r);
		}

		printf("%lld\n", l);
	}
	return 0;
}