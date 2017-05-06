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

class WaterAndOxygen{
public:
	double maxDays(int remainH20, int remainO2, int costH2O, int costO2){
		double ret = 0;
		double day = min(((double)remainH20 / costH2O), ((double)remainO2 / costO2));
		ret += day;
		// cout << day << endl;
		remainH20 -= day * costH2O;
		remainO2 -= day * costO2;

		// cout << remainH20 << " " << remainO2 << endl;	
		double l = 0.0; double r = INF + 1;
		rep(i, 100){
			// cout << l << " " << r << endl;
			double m = (l + r) / 2.0;
			double needO2 = m * costO2;
			double needH2O = m * costH2O;
			double tarinai = max(0.0, needO2 - remainO2);
			double sum = needH2O + tarinai * 2;
			if(sum <= remainH20) l = m;
			else r = m;
		}
		// cout << remainH20 << " " << remainO2 << endl;
		return ret + l;
	}
};

int main(void){
	WaterAndOxygen wo;
	// cout << wo.maxDays(64, 70, 3, 7) << endl;
	cout << wo.maxDays(99, 102, 1,	 1) << endl;

	return 0;
}