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
	// printf("X %lld\n",X );
	ll L = 1;
	ll cnt = 0;
	bool flag = true;
	int prev = 0;
	while(flag){ // O(N)
		ll up = 1;


		if(L + X > s[N - 1]){
			cnt++;
			flag = false;
			break; // 最強倒した
		}

		bool f = true;
		// printf("i %d\n",i );
		if(s[prev] > L) {
			ll d1 = X - abs(L - s[prev]);
			ll d2 = X - abs(L - s[max(0, prev - 1)]);
			if(L + X <= s[prev]) d1 = 1;

			if(d1 > d2){
				// printf("1: d1 %d\n",prev );
				chmax(up, d1);
			}else{
				// printf("1: d2 %d\n",prev );
				prev--;
				if(prev < 0) prev = 0;
				chmax(up, d2);
			}
			cnt++;
		}else{
			// printf("2:\n");
			f = false;
			prev++;
		}
		// printf("prev %d up %d\n", prev, up);
		// printf("%lld up %lld\n", cnt, up);
		if(f)L += up;
		// printf("L %d\n", L);
	}
	if(cnt >= M){
		// printf("ok\n");
		return true;
	}
	else return false;
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
		// printf("k\n");
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