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

class HillClimber {
public:
	int longest(vector <int> height) {
		int ans = 0;
		int tmp = 0;
		rep(i, height.size() - 1) {
			if(height[i] < height[i + 1]) {
				tmp++;
			}else {
				tmp = 0;
			}
			chmax(ans, tmp);
		}
		return ans;
	}	
};

int main(void) {
	HillClimber hh;
	printf("%d\n", hh.longest({ 1, 2, 3, 2, 2 }));
	return 0;
}