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

string s, t;
int main(void) {
	cin >> s >> t;
	vector<string> ans;
	rep(i, s.size()) {
		string d = s.substr(i, t.size());
		if(d.size() < t.size()) continue;
		bool f = true;
		rep(j, d.size()) {
			if(!(d[j] == '?' || d[j] == t[j])) f = false;
		}
		if(!f) continue;
		string ts = s;
		reps(j, i, i + t.size()) ts[j] = t[j - i];
		rep(j, ts.size()) if(ts[j] == '?') ts[j] = 'a';
		ans.pb(ts);
	}
	sort(all(ans));
	if(ans.size() == 0) cout << "UNRESTORABLE" << endl;
	else cout << ans[0] << endl;
	return 0;
}