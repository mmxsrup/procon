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

double S[100010];
int main(void){
	int N, A, B;
	cin >> N >> A >> B;
	double mi = INF, ma = 0;
	rep(i, N) cin >> S[i];
	// printf("k\n");
	rep(i, N){
		chmax(ma, S[i]);
		chmin(mi, S[i]);
	}
	if(ma == mi){
		printf("-1\n");
		return 0;
	}
	double p = (double)B / (double)(ma - mi);
	double sum = 0;
	// printf("k\n");
	rep(i, N)sum += S[i] *= p;
	double q = A - (sum / N);
	printf("%.9f %.9f\n", p, q);
	return 0;
}