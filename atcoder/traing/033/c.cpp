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

int na, nb;
string a[100010];
string b[100010];

int main(void) {
	cin >> na >> nb;
	rep(i, na) cin >> a[i];
	rep(i, nb) cin >> b[i];

	set<string> s, t;
	int cnt = 0;
	rep(i, na) s.insert(a[i]);
	rep(i, nb) if(s.count(b[i])) cnt++;
	rep(i, na) t.insert(a[i]);
	rep(i, nb) t.insert(b[i]);

	double ans = (double)cnt / (double)t.size();
	printf("%.9f\n", ans);
	return 0;
}