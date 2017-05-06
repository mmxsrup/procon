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

int x, y;
int N;
int A[100];
int main(void){
	cin >> x >> y;
	cin >> N;
	rep(i, N) cin >> A[i];
	if(N == 1){
		printf("YES\n");
		return 0;
	}

	double X = (double)x * 1000.0 / 3600.0;
	double Y = (double)y * 1000.0 / 3600.0;
	// printf("%f %f\n", X, Y);
	rep(i, N - 1){
		double time = (double)A[i] / X;
		double dist = time * Y;
		// printf("%f %f\n", time, dist);
		if(dist > A[i + 1]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}