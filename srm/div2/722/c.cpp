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

class MulticoreProcessingEasy
{
public:
	int fastestTime(int jobLength, int corePenalty, vector <int> speed, vector <int> cores) {
		int n = speed.size();
		long double ans = INF;
		rep(i, n) {
			reps(j, 1, cores[i] + 1) { //つかうこあ
				long double time = ((long double)jobLength / j) / (long double)speed[i];
				time += (long double)(j - 1) * (long double)corePenalty;
				chmin(ans, time);
			}
		}
		// cout << ans << endl;
		return (int)ceil(ans);
	}
};
int main(void) {
	MulticoreProcessingEasy mm;
	printf("%d\n", mm.fastestTime(2000, 5, {40, 20}, {2, 4}));
	return 0;
}