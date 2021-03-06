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

int R, K, H, W;

vector<string> rota(vector<string> v) {
	int y = v.size(), x = v[0].size();
	vector<string> ret;
	rep(i, x){
		string tmp;
		rep(j, y) tmp += v[j][i];
		reverse(all(tmp));
		ret.pb(tmp);
	}
	return ret;
}

int main(void) {

	cin >> R >> K >> H >> W;
	vector<string> c;
	rep(i, H) {
		string d; cin >> d;
		c.pb(d);
	}

	rep(i, R / 90) {
		c = rota(c);
	}

	// for(auto u : c) cout << u << endl;
	// printf("\n");

	vector<string> ans1;
	for(auto u : c) {
		rep(i, K) ans1.pb(u);
	}

	// for(auto u : ans1) cout << u << endl;
	// printf("\n");

	vector<string> ans2;
	for(auto u : ans1) {
		string tmp;
		for(auto v : u) {
			rep(i, K) tmp += v;
		}
		ans2.pb(tmp);
	}

	for(auto u : ans2) cout << u << endl;
	return 0;
}