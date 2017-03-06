#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int n, hx, hy, dx, dy;

//魔王はdx dyから動かない　勇者はhx hyからスタートして1/1d 毒ガスはhxhyhxhyからスタートして、同心円状に1/1d
//魔王に一番近いクリスタルの位置で判断？
void slove(void){
	vpint point(n);//fi;x  se;y
	rep(i, n){
		cin >> point[i].fi >> point[i].se;
		double len = (dx - point[i].fi) * (dx - point[i].fi) + (dy - point[i].se) * (dy - point[i].se);

}
int main(void){
	while(1){
		cin  >> n >> hx >> hy >> dx >> dy;
		if(n == 0) break;
		slove();
	}
	return 0;
}