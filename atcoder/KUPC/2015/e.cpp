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

int T;
int main(void){
	cin >> T;

	rep(i, T){
		double ans = 0;
		double H, W; cin >> H >> W;
		//3 tu
		chmax(ans, min(H, W));
		// printf("3 %.9f\n", ans);	

		//2 tu
		chmax(ans, min(sqrt(H*H + (W/2)*(W/2)), W));
		// printf("21 %.9f\n", ans);

		chmax(ans, min(sqrt(W*W + (H/2)*(H/2)), H));
		// printf("22 %.9f\n", ans);

		if(H > W) swap(H, W);
		double l1 = (H*H + W*W) / (2 * W);
		// double l2 = (H*H + W*W) / (2 * H);
		// cout << sqrt(H*H + W*W) << endl;
		// cout << l1 << " " << l2 << endl;
		chmax(ans, min(l1, sqrt(H*H + W*W))); //chmax(ans, min(l2, sqrt(H*H + W*W)));
		// printf("23 %.9f\n", ans);

		//1 tu
		if(H == W){
			double r = H*H + W*W - (sqrt(3)*H*W);
			if(r >= 0){
				chmax(ans, 2*sqrt(r));
			}
		}
		printf("%.9f\n", ans);
	}
	return 0;
}