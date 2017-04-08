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

int T;
int N;
int a[35][35];
int b[35][35];

int main(void){
	cin >> T;
	vint v;
	while(T--){
		cin >> N;
		rep(i, N)rep(j, N) cin >> a[i][j];
		bool flag = true;
		rep(i, N)if(a[i][i] != 0){
			// printf("NO\n");
			v.pb(0);
			flag = false; break;
		}
		if(!flag) continue;

		rep(i, N)rep(j, N){
			if(a[i][j] == -1) b[i][j] = MOD;
			else b[i][j] = a[i][j];
		}

		rep(k, N)rep(i, N)rep(j, N) chmin(b[i][j], b[i][k] + b[k][j]);
		//check
		// rep(i, N)rep(j, N)printf("%d\n", b[i][j]);
		rep(i, N){
			rep(j, N){
				if((a[i][j] == -1 && b[i][j] != MOD) || (a[i][j] >= 0 && a[i][j] != b[i][j])){
					// printf("NO\n");
					v.pb(0);
					flag = false;
					break;
				}
			}
			if(!flag)break;
		}
		if(!flag)continue;
		v.pb(1);
	}
	rep(i, v.size()){
		if(v[i]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}