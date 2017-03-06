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

int a[110];
int n, q;
int main(void){
	cin >> n >> q;
	rep(i, q){
		int l, r; cin >> l >> r;
		int t; cin >> t;
		l--; r--;
		reps(j, l, r + 1){
			a[j] = t;
		}
	}
	rep(i, n){
		printf("%d\n", a[i]);
	}
	return 0;
}