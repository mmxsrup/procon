#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
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
#define REP(i,n) for (int i=(n)-1;i>=0;i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define REPS(i,f,n) for (int i=(f)-1;i>=(n);i--)
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
double pai = 3.141592653589793;

struct point{
	double x, y; 
};

void slove(int n, point a, point b){
	if(n == 0) return;
	point s, t, u;
	double th = pai * 60.0 / 180.0;//60度を1/3πに変換

	//ベクトルの内分公式から
	s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
	s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
	t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
	t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
	//正三角形の頂点 複素数平面的にできる？　回転行列
	u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
	u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

//ここから６行の操作が微妙
	slove(n - 1, a, s);
	printf("%.9f %.9f\n", s.x, s.y);
	slove(n - 1, s, u);
	printf("%.9f %.9f\n", u.x, u.y);
	slove(n - 1, u, t);
	printf("%.9f %.9f\n", t.x, t.y);
	slove(n - 1, t, b);
}


int main (void){
	point a, b;
	int n;
	cin >> n;

	a.x = 0.0;
	a.y = 0.0;
	b.x = 100.0;
	b.y = 0.0;

	printf("%.9f %.9f\n", a.x, a.y);//始めの点
	slove(n, a, b);//中間の点を表示するプログラムに飛ばす
	printf("%.9f %.9f\n", b.x, b.y);//最後の点

	return 0;
}