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
	ll cnt = 0;
	priority_queue<pair<ll, ll>> que; // atai kazu
	que.push(mp(N, 1));
	while(1){
		// printf("cnt %lld\n", cnt);
		if(cnt <= K - 1){
			auto d = que.top(); que.pop();
			ll atai = d.fi, num = d.se;
			// printf("atai %lld num %lld cnt %lld\n", atai,  num, cnt);
			if(cnt + num >= K){
				if(atai % 2){
					printf("%lld %lld\n", atai / 2, atai / 2);
				}else{
					printf("%lld %lld\n", atai / 2, max(0ll, atai / 2 - 1));
				}
				return;
			}else{
				cnt += num;
				if(atai % 2){
					que.push(mp(atai / 2, num * 2));
				}else{
					que.push(mp(atai / 2, num));
					que.push(mp(min(atai / 2 - 1, 0ll), num));
				}
			}
		}else{
			printf("jaa\n");
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