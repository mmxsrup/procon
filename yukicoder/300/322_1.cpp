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

int n;
double t[200010], d[200010];

vector<int> ans;
int main(void){
	cin >> n;
	rep(i, n) cin >> t[i];
	rep(i, n) cin >> d[i];
	rep(i, n) ans.push_back(i);

	sort(all(ans), [](int l, int r){return t[l] * (d[l] * 0.5 + d[r] + 1.0) + t[r] * (d[r] * 0.5 + 1.0) > t[r] * (d[r] * 0.5 + d[l] + 1.0) + t[l] * (d[l] * 0.5 + 1.0);});

	rep(i, n){
		printf("%d ", ans[i] + 1);
	}
	printf("\n");
	return 0;
}