#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int main(void){
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	rep(i, 2 * n - 3){
		rep(p, n){
			int q = i - p;
			if(p >= q) continue;
			if(q > n - 1) continue;
			if(a[p] > a[q])swap(a[p], a[q]);
		}
	}
	rep(i, n) printf("%d ", a[i]);
	printf("\n");
	return 0;
}