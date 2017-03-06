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

struct Point{double x, y;};
typedef vector<Point> Polygon;
typedef Point Vector;
#define EPS (1e - 10);
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

//ベクトルのノルム
double norm(Vector a){
	return a.x * a.x + a.y * a.y;
}
//ベクトルの内積
double dot(Vector a, Vector b){
	return a.x * b.x + a.y * b.y;
}
//ベクトルの外積
double cross(Vector a, Vector b){
	return a.x * b.y - a.y * b.x;
}
//点の位置関係
int ccw(Point p0, Point p1, Point p2){
	Vector a = p1 - p0;
	Vector b = p2 - p0;
	if(cross(a, b) > EPS) return COUNTER_CLOCKWISE;
	if(cross(a, b) > -EPS)return CLOCKWISE;
	if(dot(a, b) < -EPS) return ONLINE_BACK;
	if(a.norm < b.norm()) return ONLINE_FRONT;
	return ON_SEGMENT;
}

Polygon andrewScan(Polygon s){
	Polygon u, l;
	if(s.size() < 3) return s;
	sort(s.begin(), s.end()); // x, yを基準に昇順ソート
	//xが小さいものから2つuに追加
	u.push_back(s[0]);
	u.push_back(s[1]);
	//xが大きいものから2つlに追加
	l.push_back(s[s.size() - 1]);
	l.push_back(s[s.size() - 2]);
	//凸包の上部を生成
	for (int i = 0; i < s.size(); ++i){
		for (int n = u.size(); n >= 2 && ccw(u[n - 2], u[n - 1], s[i]) != CLOCKWISE; --n){
			u.pop_back();
		}
		u.push_back(s[i]);
	}
	//凸包の下部を生成
	for (int i = s.size() - 3; i >= 0; --i){
		for (int n = l.size(); n >= 2 && ccw(l[n - 2], l[n - 1], s[i]) != CLOCKWISE; --n){
			l.pop_back();
		}
		l.push_back(s[i]);
	}
	//時計回りになるように凸包の点の列を生成
	reverse(l.begin(), l.end());
	for (int i = u.size() - 2; i >= 1; --i) l.push_back(u[i]);

	return l;
}

int main(void){
	int n; cin >> n;
	Polygon d;
	rep(i, n) cin >> d[i].x >> d[i].y;
	Polygon ans = andrewScan(d);
	printf("%d\n", ans.size());
	rep(i, ans.size()){
		printf("%d\n", ans[i]);
	}
	return 0;
}