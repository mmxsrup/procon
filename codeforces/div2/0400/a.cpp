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
int a[110];
int cnt[110];

int main(void) {
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n) cnt[a[i]]++;

	vector<int> b;
	int d = 0;
	reps(i, 1, 101) {
		if(cnt[i] == 0) continue;
		d++;
		b.pb(i);
	}

	printf("d  %d\n", d);

	if(d != 2) {
		printf("NO\n");
		return 0;
	}

	if(b[0] != b[1]) {
		printf("NO\n");
		return 0;
	}

	printf("YES\n");
	printf("%d %d\n", b[0], b[1]);

	return 0;
}