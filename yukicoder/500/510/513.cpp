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

const int MAX = 100000;

int main(void){
	int lx = 0, rx = MAX + 1;
	while(rx - lx > 3){
		int m1 = (2 * lx + rx) / 3; //l
		int m2 = (lx + 2 * rx) / 3; // r
		cout << m1 << " " << 0 << endl;
		int ret1; cin >> ret1;
		if(ret1 == 0) return 0;
		cout << m2 << " " << 0 << endl;
		int ret2; cin >> ret2;
		if(ret2 == 0) return 0;
		if(ret1 < ret2) rx = m2;
		else lx = m1;
	}
	
	int retX, distX = INF;
	for (int i = max(0, lx); i <= min(rx, MAX); ++i){
		cout << i << " " << 0 << endl;
		int ret; cin >> ret;
		if(ret == 0)return 0;
		if(ret < distX) retX = i, distX = ret;
	}
	

	int ly = 0, ry = MAX + 1;
	rep(i, 100){
		int m1 = (2 * ly + ry) / 3; //l
		int m2 = (ly + 2 * ry) / 3; // r
		cout << retX << " " << m1 << endl;
		int ret1; cin >> ret1;
		if(ret1 == 0) return 0;
		cout << retX << " " << m2 << endl;
		int ret2; cin >> ret2;
		if(ret2  == 0) return 0;
		if(ret1 <= ret2) ry = m2;
		else ly = m1;
	}
	return 0;
}