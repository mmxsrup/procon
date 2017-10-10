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
ll d[200100];
int m;
ll t[200100];
map<ll, ll> ma;

int main(void) {
	cin >> n;
	rep(i, n)	cin >> d[i];
	cin >> m;
	rep(i, m) cin >> t[i];
	rep(i, n) ma[d[i]]++;
	bool f = true;
	rep(i, m) {
		if(ma[t[i]] > 0) ma[t[i]]--;
		else f = false;
	}
	if(f) printf("YES\n");
	else printf("NO\n");
	return 0;
}