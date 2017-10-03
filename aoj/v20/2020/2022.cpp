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

int n;
int main(void) {
	while(1) {
		scanf("%d", &n);
		if(n == 0) break;
		vector<string> ts(n);
		rep(i, n) cin >> ts[i];
		sort(all(ts));	
		ts.erase(unique(ts.begin(), ts.end()), ts.end());
		n = ts.size();

		set<int> se; //いらないやつ
		rep(i, n)rep(j, n){ // aにbが含まれるか
			if(i == j) continue;
			string a = ts[i], b = ts[j];
			if(a.size() < b.size()) continue;
			int size = b.size();
			rep(i, a.size()){
				if(a.substr(i, size) == b){
					se.insert(j);
					break;
				}
			}
		}
		vector<string> s;
		rep(i, n) if(se.count(i) == 0) s.pb(ts[i]);
		sort(all(s));
		s.erase(unique(s.begin(), s.end()), s.end());

		n = s.size();
		vector<int> v;
		rep(i, n) v.pb(i);

		string ans;
		rep(i, 1000) ans += "z";

		do{
			string d = s[v[0]];
			// cout << "d: " << d << endl;
			bool ok = false;
			reps(i, 1, n){
				int idx = v[i]; //次んつなげる文字列のindex
				bool f = false;
				for (int j = s[idx].size(); j >= 0; --j){
					// printf("j %d\n", j);
					string t = s[idx].substr(0, j);
					// cout << "t: " << t << endl;
					// tがdに含まれているかしらべる
					if((int)d.size() - j < 0) continue;
					// printf("ok %d %d\n", d.size(), j);
					if(t == d.substr(d.size() - j)){
						d += s[idx].substr(j);
						f = true;
						break;
					}
				}
				if(!f) break;

				if(i == n - 1) ok = true;
			}
			// if(ok) cout << "d: " << d << endl;
			if(ok && (int)d.size() < (int)ans.size()) ans = d;
			else if(ok && (int)d.size() < (int)ans.size() && d < ans) ans = d;

		}while(next_permutation(all(v)));

		if(n == 1) cout << s[0] << endl;
		else cout << ans << endl;
	}
	return 0;
}