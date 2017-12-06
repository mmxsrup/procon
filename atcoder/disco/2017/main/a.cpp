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

int K;

int solve2() {
	int ans = 0;
	for (int i = 100 - K; i > 0; i -= K) {
		double l = i;
		double s = 100. - l;
		double r = 100.;
		double t = sqrt(r * r - s * s);
		// printf("t %f\n", t);
		ans += 2 * (int)(t / K);
		// printf("i %d %d\n", i, (int)(2 * (t / K)));
	}
	return ans * 2;
}
int solve3() {
	int ans = 0;
	if((300 / K) % 2 == 0) {
		int ans = 0;
		for (int i = 150 - K; i > 0; i -= K) {
			double l = i;
			double s = 150. - l;
			double r = 150.;
			double t = sqrt(r * r - s * s);
			ans += 2 * (int)(t / K);
		}
		return ans * 2;
	}else{
		int tmp;
		{
			double l = 150 - K;
			double s = 150. - l;
			double r = 150.;
			double t = sqrt(r * r - s * s) - (double)K / 2.;
			tmp =  2 * (int)(t / K) + 1;
		}
		// printf("tmp %d\n", tmp);
		int ans = 0;
		for (int i = 150 - K / 2 - K; i > 0; i -= K) {
			// printf("i %d\n", i);
			double l = i;
			double s = 150. - l;
			double r = 150.;
			double t = sqrt(r * r - s * s) - (double)K / 2.;
			ans += 2 * (int)(t / K) + 1;
			// printf("%d\n", 2 * (int)(t / K) + 1);
		}
		return 2 * ans + tmp;
	}
}

int main(void) {
	cin >> K;
	printf("%d %d\n", solve2(), solve3());
	return 0;
}