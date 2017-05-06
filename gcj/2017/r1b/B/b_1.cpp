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
	priority_queue<pair<int, char>> pq;
	if(R)pq.push(mp(R, 'R'));
	if(Y)pq.push(mp(Y, 'Y'));
	if(B)pq.push(mp(B, 'B'));
	if(pq.size() <= 1){
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	auto u1 = pq.top(); pq.pop();
	auto u2 = pq.top(); pq.pop();
	string s1 = "", s2 = "";
	s1 = s1 + u1.se, s2 = u2.se + s2;

	if(u1.fi >= 2) pq.push(mp(u1.fi - 1, u1.se));
	if(u2.fi >= 2) pq.push(mp(u2.fi - 1, u2.se));

	while(!pq.empty()){
		auto d = pq.top(); pq.pop();
		char c = d.se;
		// printf("%d %c\n", d.fi, d.se);
		if(s1.back() != c){
			s1 = s1 + c;
			if(d.fi >= 2) pq.push(mp(d.fi - 1, d.se));
		}else if(s2.back() != c){
			s2 = c + s2;
			if(d.fi >= 2) pq.push(mp(d.fi - 1, d.se));
		}
	}
	string ans = s1 + s2;
	bool flag = true;
	if(ans[0] == ans.back()) flag = false;
	rep(i, (int)ans.size() - 1){	
		if(ans[i] == ans[i + 1]) flag = false;
	}
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