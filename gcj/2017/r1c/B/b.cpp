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

int Ac, Aj;
int C[110], D[110];
int J[110], K[110];

void solve(void){
	cin >> Ac >> Aj;
	rep(i, Ac) cin >> C[i] >> D[i];
	rep(i, Aj) cin >> J[i] >> K[i];

	if(Ac == 1 && Aj == 1){
		if(C[0] > J[0]){
			swap(C[0], J[0]), swap(D[0], K[0]);
		}
		if(J[0] - D[0] <= 720) printf("2\n");
		else printf("4\n");
		return;
	}else if(Ac + Aj == 1){
		printf("2\n");
		return;
	}else if(Ac == 2){
		if(C[0] > C[1]){
			swap(C[0], C[1]), swap(D[0], D[1]);
		}
		if(D[1] - C[0] <= 720){
			printf("2\n");
			return;
		}else{
			printf("4\n");
			return;
		}
	}else if(Aj == 2){
		if(J[0] > J[1]){
			swap(J[0], J[1]), swap(K[0], K[1]);
		}
		if(K[1] - J[0] <= 720){
			printf("2\n");
			return;
		}else{
			printf("4\n");
			return;
		}
	}
}

int main(void){
	int T; cin >> T;
	rep(i, T){
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}