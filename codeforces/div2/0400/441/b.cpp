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


int n, k, m;
int a[100010];

int main(void) {
	scanf("%d %d %d", &n, &k, &m);
	rep(i, n) scanf("%d", &a[i]);

	map<int, int> ma;
	rep(i, n) ma[a[i] % m]++;
	int ans, max = 0;
	for(auto t : ma) {
		// printf("%d %d\n", t.fi, t.se);
		if(t.se > max) {
			max = t.se; ans = t.fi;
		}
	}
	// printf("max %d ans %d\n", max, ans);
	if(max < k) {
		printf("No\n");
	}else{
		printf("Yes\n");
		int cnt = 0;
		rep(i, n) {
			if(cnt == k) break;
			if(a[i] % m == ans) {
				printf("%d ", a[i]);
				cnt++;
			}
		}
		printf("\n");
	}
	return 0;
}