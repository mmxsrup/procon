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

int A, B, C, D;
int main(void){
	cin >> A >> B >> C >> D;
	if(A == C){
		printf("0\n");
		return 0;
	}else if(B == D){
		printf("0\n");
		return 0;
	}

	int X = abs(A - C), Y = abs(B - D);
	if(X < Y) swap(X, Y);
	if(X % Y == 0){
		printf("%d\n", X); return 0;
	}
	// printf("%d %d\n", X, Y);
	int ans = X;
	reps(i, 1, Y) ans++;
	printf("%d\n", ans);
	return 0;
}