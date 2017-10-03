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

int H, N;

int main(void) {
	cin >> H >> N;
	std::vector<int> v;
	v.pb(H);
	rep(i, N - 1) {
		int d; cin >> d;
		v.pb(d);
	}
	sort(all(v));
	reverse(all(v));
	int ans;
	rep(i, v.size()) {
		if(v[i] == H) {
			ans = i + 1;	
			break;
		}
	}
	if(ans % 10 == 1) printf("%dst\n", ans);
	else if(ans % 10 == 2) printf("%dnd\n", ans);
	else if(ans % 10 == 3) printf("%drd\n", ans);
	else printf("%dth\n", ans);
	return 0;
}