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

bool flag = false;
void dfs(string s){
	if(s.size() < 3) return;
	if(s == "ABC"){
		// cout << s << endl;
		flag = true; return;
	}
	static string b[] = {"A", "B", "C"};
	rep(k, 3){
		string t = s;
		bool f = false;
		/* すべての"ABC"をb[k]日間したら, 置換後の文字列にb[k]は含まれていてはだめ */
		int cnt = 0;
		rep(i, t.size()){
			if(i < t.size() - 2 && t[i] == 'A' && t[i + 1] == 'B' && t[i + 2] == 'C'){
				f = true;
				t.replace(i, 3, b[k]);
			}else if(t[i] == "ABC"[k]){
				cnt++;
			}
		}
		if(f && cnt == 0){
			// cout << t << endl;
			dfs(t);
		}
	}
	return;
}

int main(void){
	string s; cin >> s;
	dfs(s);
	if(flag) printf("Yes\n");
	else printf("No\n");
	return 0;
}