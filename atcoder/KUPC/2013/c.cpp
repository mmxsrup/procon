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

int M, N;
int a[110][110];

int main(void){
	cin >> M >> N;
	rep(i, M)rep(j, N) cin >> a[i][j];
	int ans = 0;
	rep(i, M){
		int l = 0, r = N - 1;
		if(i != 0)rep(j, N) a[i][j] ^= 1;

		while(r - l >= 1){
			// printf("l %d r %d\n", l, r);
			if(a[i][l] == 1 && a[i][r] == 1){
				a[i][++l] ^= 1, ans++;
			}else if(a[i][l] == 1){
				a[i][++l] ^= 1, ans++;
			}else if(a[i][r] == 1){
				a[i][--r] ^= 1, ans++;
			}else{
				a[i][++l] ^= 1;
			}
		}
		ans += a[i][l];
		// printf("t %d\n", ans);
	}
	printf("%d\n", ans);
}