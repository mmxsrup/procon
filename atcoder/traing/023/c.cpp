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

double A, B;
int N;
double C[5010], D[5010];

int main(void) {
	cin >> A >> B >> N;
	rep(i, N) cin >> C[i] >> D[i];
	if(A > B) swap(A, B);
	rep(i, N) if(C[i] > D[i]) swap(C[i], D[i]);
	rep(i, N){
		if(A <= C[i] && B <= D[i]){
			printf("YES\n"); continue;
		}
		/*
		if(A > C[i]){
			printf("NO\n"); continue;
		}
		*/
		bool f = false;
		double l = 0.0, r = 3.1415926535897932384626433 / 2.0;
		rep(k, 500){
			double m = (l + r) / 2.0;
			double x = cos(m) * A + sin(m) * B;
			double y = sin(m) * A + cos(m) * B;
			if(x <= C[i] && y <= D[i]){
				f = true;
				break;
			}else if(x > C[i]){
				r = m;
			}else{
				l = m;
			}
		}

		if(f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}