#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
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
string tb[510];
int b[510][510];
int ans[510][510];
int main(void){
	cin >> n >> m;
	rep(i, n)cin >> tb[i];
	rep(i, 510)rep(j, 510){
		b[i][j] = tb[i][j] - '0';
	}

	rep(i, n)rep(j, m){
		int t = b[i][j];
		b[i][j] -= t;
		if(i + 2 < n) b[i + 2][j] -= t;
		if(i + 1 < n && j + 1 < m)b[i + 1][j + 1] -= t;
		if(i + 1 < n && 0 <= j - 1)b[i + 1][j - 1] -= t;
		ans[i + 1][j] += t;
	}
	rep(i, n){
		rep(j, m){
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}