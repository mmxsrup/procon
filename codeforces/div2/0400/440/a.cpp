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


int n, m;
int a[20], b[20];
int main(void) {
	scanf("%d %d", &n, &m);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, m) scanf("%d", &b[i]);
	set<int> s, t;
	rep(i, n) s.insert(a[i]);
	rep(i, m) t.insert(b[i]);
	int ans = INF;
	reps(i, 1, 100){

		int d1, d2;
		if(i >= 10) d1 = i / 10, d2 = i % 10;
		else d1 = d2 = i;
		// printf(" %d %d\n", d1, d2);
		if((s.count(d1) && t.count(d2)) | (s.count(d2) && t.count(d1))) {
			chmin(ans, i);
		}
	}
	printf("%d\n", ans);
	return 0;
}