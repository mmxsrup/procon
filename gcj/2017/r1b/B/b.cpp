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

void solve(void){
	int N, R, O, Y, G, B, V;
	cin >> N >> R >> O >> Y >> G >> B >> V;
	int cnt = 0;
	if(R)cnt++; if(Y)cnt++; if(B)cnt++;
	if(cnt <= 1){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	vector<pair<int, char>> v;
	if(R)v.pb(mp(R, 'R'));
	if(Y)v.pb(mp(Y, 'Y'));
	if(B)v.pb(mp(B, 'B'));

	sort(all(v)); reverse(all(v));
	string ans = "";
	int n1 = v[0].fi, n2 = v[1].fi;
	char c1 = v[0].se, c2 = v[1].se;
	rep(i, n2){
		ans = c2 + ans;
		ans = c1 + ans;
	}
	rep(i, n1 - n2){
		ans = c1 + ans;
	}
	// cout << ans << endl;
	if(v.size() > 2){
		int n3 = v[2].fi;
		char c3 = v[2].se;
		// printf("%d %c\n", n3, c3);
		string inc3{c3};
		int cnt = 0;
		int idx = 0;
		while(cnt < n3){
			rep(i, ans.size() - 1){
				if(ans[i] != c3 && ans[i + 1] != c3){
					// printf("%d\n", i);
					ans.insert(i + 1, inc3);
					cnt++;
					break;
				}
			}
		}
	}
	// cout << ans << endl;
	
	bool flag = true;

	if(ans[0] == ans.back()) flag = false;
	rep(i, (int)ans.size() - 1){
		if(ans[i] == ans[i + 1]) flag = false;
	}
	int r = 0, y = 0, b = 0;
	for(auto u : ans){
		if(u == 'R')r++;
		else if(u == 'Y')y++;
		else if(u == 'B')b++;
	}
	if(!(r == R && y == Y && b == B)) flag = false;

	if(flag) cout << ans << endl;
	else cout << "IMPOSSIBLE" << endl;

}
//segfowo naosu
int main(void){
	int T; cin >> T;
	rep(i, T){
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}