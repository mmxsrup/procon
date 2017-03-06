#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;

int main(void){
	string c;
	getline(cin, c);
	vector<string> ans;
	string k = "";
	for(auto u : c){
		int d = u - '\0';
		bitset<7> b(d);
		k += b.to_string();
	}

	// cout << "k " << k << endl;

	int l = 0, r = 0;
	//[l, r)がおなじ文字
	while(l < k.size() || r < k.size()){
		while(k[l] == k[r] && r < k.size()) r++;

		string d = "";
		rep(i, r - l) d += '0';
		if(k[l] == '0') ans.pb("00");
		else ans.pb("0");
		ans.pb(d);
		l = r;
	}

	rep(i, ans.size()){
		if(i != ans.size() - 1) cout << ans[i] << " ";
		else cout << ans[i] << endl;
	}
	return 0;
}