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
int a[110];
int main(void){
	cin >> N;
	rep(i, N) cin >> a[i];
	int sum = 0;
	rep(i, N) sum += a[i];
	if(sum % N != 0){
		printf("-1\n");
		return 0;
	}
	int cnt = 0;
	int num = sum / N;
	rep(i, N - 1){
		int l = 0, r = 0;
		int nl = num * (i + 1);
		int nr = sum - nl;
		rep(j, i + 1) l += a[j];
		reps(j, i + 1, N) r += a[j];
		if(!(l == nl && r == nr)) cnt++;
	}
	printf("%d\n",cnt );
	return 0;
}