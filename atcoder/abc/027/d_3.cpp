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

string s;
int plus1[100010], minus1[100010];

int main(void){
	cin >> s;
	rep(i, s.size()){
		if(s[i] == '+')plus1[i + 1]++;
		else if(s[i] == '-') minus1[i + 1]++;
	}
	int M = 0;
	for(auto u : s) if(u == 'M') M++;

	reps(i, 1, s.size() + 1) plus1[i] += plus1[i - 1];
	reps(i, 1, s.size() + 1) minus1[i] += minus1[i - 1];
	// rep(i, s.size() + 1) printf("%d ", plus1[i]);
	// printf("\n");
	// rep(i, s.size() + 1) printf("%d ", minus1[i]);
	// printf("\n");
	vector<pair<int, int>> v, rv;

	rep(i, s.size()){
		if(s[i] != 'M') continue;
		int p = plus1[s.size()] - plus1[i];
		int m = minus1[s.size()] - minus1[i];
		// printf("%d %d\n", p, m);
		v.pb(mp(p - m, i));
		rv.pb(mp(m - p, i));
	}
	sort(all(v)); reverse(all(v));
	sort(all(rv)); reverse(all(rv));

	ll ret = 0;
	set<int> se;
	rep(i, M / 2){
		ret += v[i].fi;
		// printf("1 %d %d\n", v[i].fi, v[i].se);
		se.insert(v[i].se);
	}
	int cnt = M / 2;
	for(auto u : rv){
		if(cnt >= M) break;
		if(se.count(u.se) == 0){
			// printf("%d\n",u.se );
			ret += u.fi;
			cnt++;
		}
	}
	printf("%lld\n", ret);
	return 0;
}