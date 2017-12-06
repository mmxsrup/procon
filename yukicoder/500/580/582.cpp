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

int N;
ll C[200];

int main(void) {
	cin >> N;
	rep(i, N) cin >> C[i];
	int cnt0 = 0, cnt1 = 0, cnt2 = 0, oth = 0;
	rep(i, N) {
		if(C[i] == 0) cnt0++;
		else if(C[i] == 1) cnt1++;
		else if(C[i] == 2) cnt2++;
		else oth++;
	}
	if(oth > 0) {
		printf("B\n");
	}else if(cnt2 > 1) {
		printf("B\n");
	}else{
		if(cnt1 % 2) printf("A\n");
		else printf("B\n");
	}
	return 0;
}