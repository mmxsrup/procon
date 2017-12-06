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


int ans[55];
int d1[] = {12, 11, 10, 9, 8};

void dfs(int idx, int l, int lim, int ret, vector<int> v)  {
	// printf("lim %d\n", lim);
	if(idx == lim) {
		// printf("ok\n");
		int sum = 0;
		for(auto u : v) sum += u;

		// printf("sum %d\n", sum);
		if(sum == ret) {
			// printf("u\n");
			// for(auto u : v) printf("%d ", u);
			// printf("\n");
			rep(j, lim)rep(k, 5) {
				int dd = d1[k] * pow(10, j);
				if(v[j] % dd == 0) {
					// printf("%d\n", d1[k]);
					ans[l + j] = d1[k] % 2;
					break;
				}
			}
		}
		return;
	}

	rep(i, 5) {
		auto tmp = v;
		tmp.pb(d1[i] * pow(10, idx));
		dfs(idx + 1, l, lim, ret, tmp);
	}
}
int main(void) {
	int N; cin >> N;
	int t = N / 5 + (N % 5 ? 1 : 0);
	// printf("t %d\n", t);
	rep(i, t) {
		int l = i * 5;
		int r = min(N, l + 5);
		printf("? ");
		rep(j, N) {
			if(l <= j && j < l + 5) {
				if(l == j) printf("1 ");
				else if(l + 1 == j) printf("10 ");
				else if(l + 2 == j) printf("100 ");
				else if(l + 3 == j) printf("1000 ");
				else if(l + 4 == j) printf("10000 ");
			} else {
				printf("0 ");
			}
		}
		printf("\n");fflush(stdout);

		int ret;
		scanf("%d", &ret);

		// printf("%d %d\n", l, r);
		dfs(0, l, r - l, ret, {});
	}

	printf("! ");
	rep(i, N) printf("%d ", ans[i]);
	printf("\n");fflush(stdout);

	return 0;
}