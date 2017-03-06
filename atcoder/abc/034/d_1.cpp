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

int k, n;
double w[1010], p[1010];
double sio[1010];

bool check(double m){
	//Σsio/Σw = m * 0.01
	//Σsio = Σw * m * 0.01
	//Σsio - (w * m * 0.01) この順に貪欲に選ぶ
	vector<double> a;
	rep(i, n){
		a.pb(sio[i] - (w[i] * m * 0.01));
	}
	sort(all(a));
	reverse(all(a));
	double sum = 0;
	rep(i, k){
		sum += a[i];
	}
	return (sum >= 0) ? true : false;
}

int main(void){
	cin >> n >> k;
	rep(i, n){
		cin >> w[i] >> p[i];
		sio[i] = w[i] * p[i] * 0.01;
	}
	double l = 0.0, r = 100.0;
	rep(i, 100){
		double mid = (l + r) / 2.0;
		if(check(mid)){
			l = mid;
		}else{
			r = mid;
		}
	}
	printf("%.9f\n", l);
	return 0;
}