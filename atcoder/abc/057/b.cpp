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

int N, M;
int a[55], b[55], c[55], d[55];
int main(void){
	cin >> N >> M;
	rep(i, N) cin >> a[i] >> b[i];
	rep(i, M) cin >> c[i] >> d[i];

	rep(i, N){
		int x, y;
		x = a[i], y = b[i];
		int ans = INF, idx;
		rep(i, M){
			int di = abs(x - c[i]) + abs(y - d[i]);
			if(ans > di){
				idx = i + 1;
				ans = di;
			}
		}
		printf("%d\n", idx);
	}
	return 0;
}