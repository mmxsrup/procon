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


int H, W;
int N;
int a[10010];

int main(void) {
	cin >> H >> W;
	cin >> N;
	rep(i, N) cin >> a[i];

	vector<int> ans;
	rep(i, N) {
		rep(j, a[i])ans.push_back(i + 1);		
	}

	rep(i, H) {
		int l = W * i, r = l + W;
		if(i % 2) {
			for (int j = r - 1; j >= l; --j){
				cout << ans[j] << " ";
			}
		}else {
			for (int j = l; j < r; ++j){
				cout << ans[j] << " ";
			}
		}
		printf("\n");
	}
	return 0;
}