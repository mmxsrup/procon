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

int a[100010];

int main(void) {
	int n; cin >> n;
	set<int> se;
	rep(i, n) {
		int d; cin >> d;
		a[i] = d;
		se.insert(d);
	}
	vector<int> v;
	for(auto u : se) v.push_back(u);
	sort(all(v));
	rep(i, n) {
		int k = lower_bound(all(v), a[i]) - v.begin();
		printf("%d\n", k);
	}
	return 0;
}