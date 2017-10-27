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
int n;
int cntl[30];
int cntr[30];

int main(void) {
	cin >> s;
	string d;
	int sum = 0;
	rep(i, s.size()) {
		if(s[i] != 'x') d += s[i];
		else sum++;
	}
	// cout << d << endl;
	bool f = true;
	rep(i, d.size() / 2) if(d[i] != d[d.size() - 1 - i]) {
		// printf("%c %c\n", );
		f = false;
	}
	int suml = 0;
	int tcnt = 0;
	rep(i, s.size()) {
		if(tcnt == d.size() / 2) break;
		if(s[i] == 'x') suml++;
		else tcnt++;
	}
	int ans = 0;
	int l = 0, r = s.size() - 1;
	while(r - l > 0) {
		if(s[l] == s[r]) l++, r--;
		else if(s[l] == 'x') {
			ans++;
			l++;
		}else {
			ans++;
			r--;
		}
	}
	if(f) printf("%d\n", ans);
	else printf("-1\n");
	return 0;
}