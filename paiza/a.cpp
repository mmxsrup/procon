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
int s[1010], p[3010];
vector<int> v;
int main(void){
	scanf("%d %d", &M, &N);
	rep(i, M) scanf("%d", &s[i]);
	rep(i, N) scanf("%d", &p[i]);
	v.resize(N * N);
	rep(i, N)rep(j, N)v[N * i + j] = p[i] * p[j];
	/*
	rep(i, N)rep(j, N) v.pb(p[i] * p[j]);
	for(auto u : v){
		printf("%d ", u);
	}
	printf("\n");
	*/

	sort(all(v));
	rep(i, M){
		auto d = lower_bound(all(v), s[i]);
		printf("%d\n", *d - s[i]);
	}
	return 0;
}