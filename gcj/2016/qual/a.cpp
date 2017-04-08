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

int T;

int main(void){
	cin >> T;
	int tmpT = T;
	int num = 0;
	vector<ll> ans;
	while(T--){
		// printf("T %d\n", T);
		num++;
		ll N; cin >> N;
		// cout << N << endl;
		if(N == 0)ans.pb(INFF);
		set<char> se;
		reps(i, 1, 100){
			ll d = N * i;
			string t = to_string(d);
			for(auto u : t) se.insert(u);
			if(se.size() >= 10){
				// printf("d %lld\n", d);
				ans.pb(d);
				break;
			}
		}
	}
	rep(i, tmpT){
		if(ans[i] != INFF)printf("Case #%d: %lld\n", i + 1, ans[i]);
		else printf("Case #%d: INSOMNIA\n", i + 1);
	}
	return 0;
}