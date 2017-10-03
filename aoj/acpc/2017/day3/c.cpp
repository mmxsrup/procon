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

int cnt[500010];

int main(void) {
	string t, p; cin >> t >> p;
	reverse(all(t)), reverse(all(p));
	int idx = 0;
	rep(i, t.size()) {
		// cout << t[i] << " " << p[idx] << endl;
		if(t[i] == p[idx]) {
			// printf("kk\n");
			cnt[idx]++; continue;
		}
		if(idx + 1 < p.size() && t[i] == p[idx + 1]) {
			idx++; cnt[idx]++;
		}
	}

	bool flag = true;
	rep(i, p.size()) if(cnt[i] != 1) flag = false;
	// rep(i, p.size()) printf("%d ", cnt[i]);
	// printf("\n");
	if(flag)printf("yes\n");
	else printf("no\n");
	return 0;
}