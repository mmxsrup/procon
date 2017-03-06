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

class Types_triangles{
public:
	int n;
	vector<int> y, x;//y座標　x座標
	const double EPS = 1e-10;
	long long cnt_chokaku = 0, cnt_donkaku = 0, cnt_eikaku = 0;
	Types_triangles(const vector<int> &ty, const vector<int> &tx, int size):y(ty), x(tx), n(size){//n:=座標の数
		count();
	}
private:
	void count(){
		for (int i = 0; i < n; ++i){
			//-M_PI ~ M_PI(-180 ~ 180)
			vector<double> angle;//(x[i], y[i])を原点とした偏角
			for (int j = 0; j < n; ++j){
				if(j == i) continue;
				angle.push_back(atan2(y[j] - y[i], x[j] - x[i]));
			}
			sort(angle.begin(), angle.end());
			for (int j = 0; j < n - 1; ++j){//2周目を作る
				angle.push_back(angle[j] + M_PI*2);
			}
			for (int j = 0; j < n - 1; ++j){
				cnt_chokaku += upper_bound(angle.begin(), angle.end(), angle[j] + M_PI/2.0 + EPS) - lower_bound(angle.begin(), angle.end(), angle[j] + M_PI/2.0 - EPS);
				cnt_donkaku += lower_bound(angle.begin(), angle.end(), angle[j] + M_PI) - upper_bound(angle.begin(), angle.end(), angle[j] + M_PI/2.0 + EPS);
			}
		}
		cnt_eikaku = (ll)n * (n - 1) * (n - 2) / 6 - cnt_chokaku - cnt_donkaku;//キャストミスでWA
	}
};

int main(void){
	int n; cin >> n;
	vector<int> y(n), x(n);
	rep(i, n) cin >> x[i] >> y[i];
	Types_triangles t(y, x, n);
	printf("%lld %lld %lld\n", t.cnt_eikaku, t.cnt_chokaku, t.cnt_donkaku);
	return 0;
}