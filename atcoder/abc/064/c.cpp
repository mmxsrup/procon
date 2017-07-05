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

int n;
int a[110];
int memo[10];
int main(void){
	cin >> n;
	rep(i, n){
		cin >> a[i];
	}
	rep(i, n){
		if(a[i] < 3200)memo[a[i] / 400]++;
		else memo[8]++;
	}

	int cnt = 0;
	rep(i, 8) if(memo[i] > 0)cnt++;
	if(cnt != 0){
		printf("%d %d\n", cnt, cnt + memo[8]);
	}else{
		printf("%d %d\n", 1, cnt + memo[8]);
	}
	return 0;
}