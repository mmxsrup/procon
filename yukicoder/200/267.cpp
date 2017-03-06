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
	int n; cin >> n;
	vector<pair<string, string> > s;
	rep(i, n){
		string t; cin >> t;
		string d = "";
		if(t[0] == 'D') d += 'A';
		else if(t[0] == 'C') d += 'B';
		else if(t[0] == 'H') d += 'C';
		else if(t[0] == 'S') d += 'D';	

		if('2' <= t[1] && t[1] <= '9') d += 'A' + (t[1] - '1');
		else if(t[1] == 'A') d += 'A';
		else if(t[1] == 'T') d += 'M';
		else if(t[1] == 'J') d += 'N';
		else if(t[1] == 'Q') d += 'O';
		else if(t[1] == 'K') d += 'P';
		s.pb(mp(d, t));
	}
	sort(all(s));
	rep(i, n){
		cout << s[i].se << " ";
	}
	cout << endl;
	return 0;
}