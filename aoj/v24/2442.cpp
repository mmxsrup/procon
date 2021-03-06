/*
長さだけだと不十分なことは明らか
対象と成りうる点の中点を全て比較して、全てが一致していれば十分条件　例外台形
*/
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(ll i=0;i<(n);i++)

const double EPS = 1e-14;
int main(void){
	ll n; cin >> n;
	vector<pair<double, double> > point(n);//fi　;x座標　 se ;y座標
	rep(i, n) scanf("%lf %lf", &point[i].fi, &point[i].se);

	//nが奇数はありえない
	if(n % 2 == 1){
		printf("NA\n");
		return 0;
	}

	//長さチェック
	vector<double> len(n);
	rep(i, n - 1){
		double tmp = pow(point[i + 1].fi - point[i].fi, 2) + pow(point[i + 1].se - point[i].se, 2);
		len.push_back(tmp);
	}
	double tmp = pow(point[0].fi - point[n - 1].fi, 2) + pow(point[0].se - point[n - 1].se, 2);
	len.push_back(tmp);
	sort(all(len));
	if(len[n - 1] - len[0] > EPS){
		printf("NA\n");
		return 0;
	}

	//対象と成り得る点の中点を求める
	vector<double> Px;
	vector<double> Py;
	rep(i, n / 2){
		double x = (point[i].fi + point[i + n / 2].fi) / 2.0;
		Px.push_back(x);
		double y = (point[i].se + point[i + n / 2].se) / 2.0;
		Py.push_back(y);
	}

	//上で求めた対象と成りうる点をソートして、大きいものと小さいものが一致していれば、点対象である
	sort(all(Px));
	if(Px[n / 2 - 1] - Px[0] > EPS){
		printf("NA\n");
		return 0;
	}
	sort(all(Py));
	if(Py[n / 2 - 1] - Py[0] > EPS){
		printf("NA\n");
		return 0;
	}

	printf("%.9f %.9f\n", Px[0], Py[0]);
	return 0;
}

