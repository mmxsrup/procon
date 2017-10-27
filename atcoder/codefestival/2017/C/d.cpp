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
int main(void) {
	cin >> s;
	queue<pair<int, int>, char> v1, v2;
	rep(i, s.size()) {
		odd.push(make_pair(make_pair(i, i + 1), s[i]));
	}
	int psize = 0;

	auto l = 0; r = odd.front(); odd.pop();
	int prev = -1;

	while(prev != odd.size()) {
		prev = odd.size();
		l = r; r = odd.front(); odd.pop();
		int ssize = l.fi.se - l.fi.fi;
		int tsize = r.fi.se - r.fi.fi
		if(ssize % 2 == 0 && tsize % 2 == 0) {
			even.push(make_pair(mp(l.fi.fi, r.fi.se), '#'));
			r = odd.front(); odd.pop();
		}else if(ssize % 2 == 0 && tsize % 2 == 1) {
			odd.push(make_pair(mp(l.fi.fi, r.fi.se), r.se));
			r = odd.front(); odd.pop();
		}else if(ssize % 2 == 1 && tsize % 2 == 0) {
			odd.push(make_pair(mp(l.fi.fi, r.fi.se), l.se));
			r = odd.front(); odd.pop();
		}else {
			if(r.se == r.se) {
				even.push(make_pair(mp(l.fi.fi, r.fi.se), '#'));
				r = odd.front(); odd.pop();
			}else {
				odd.push(l);
			}
		}
	}
	/*
	while(!odd.empty()) {
		vector<char> c;
		reps(k, l, l + 2) c.push_back(odd[l].se);
		sort(all(c));
		if(c[0] == c[1]) {
			odd.push(mp(odd[l].fi.fi, odd[l + 2].fi.se), c[2]);
		}else if(c[1] == c[2]) {
			odd.push(mp(odd[l].fi.fi, odd[l + 2].fi.se), c[0]);
			l += 3;
		}else{
			v1.pb(odd[])
		}
	*/
	return 0;
}