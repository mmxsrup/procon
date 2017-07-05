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

const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> bool eq(T a, T b){ return abs(a - b) < EPS; }

class Point { // 点
public:
	double x, y;
	Point(double x = 0, double y = 0):x(x), y(y){}
	Point operator + (Point p) { return Point(x + p.x, y + p.y); }
	Point operator - (Point p) { return Point(x - p.x, y - p.y); }
	Point operator * (double a) { return Point(a * x, a * y); }
	Point operator / (double a) { return Point(x / a, y / a); }
	double abs() const { return sqrt(norm()); }
	double norm() const { return x * x + y * y; }
	// bool operator < (const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
	bool operator < (const Point &p) const { // 誤差を許容して比較
		return x + EPS < p.x || (eq<double>(x, p.x) && y + EPS < p.y);
	}
	bool operator == (const Point &p) const { return (eq<double>(x, p.x) && eq<double>(y, p.y)); }
};
using Vector = Point;
using Polygon = vector<Point>; // 多角形

double dot(const Vector& a, const Vector& b) { return a.x * b.x + a.y * b.y; } // ベクトルaとbの内積
double cross(const Vector& a, const Vector& b) { return a.x * b.y - a.y * b.x; } // ベクトルaとbの外積
double length2(const Point& a) { return a.norm(); } // 通常の長さの2乗
double length(const Point& a) { return a.abs(); } // 通常の長さ
Point rotationalTransfer(Point c, double r, double deg) { // cを中心として半径rの円周上のdeg度の位置座標
	double rad = PI * deg / 180.0; return c + Point(cos(rad), sin(rad)) * r;
}
// (x, y, z) の点を光源(xy座標での角度がtheta, xy平面からz方向への角度がphiの時の)
Point Shadow(double x, double y, double z, double theta, double phi) {
	return Point(x + cos(theta) * z / sin(phi), y + sin(theta) * z / sin(phi));
}

enum ccw_t {
	COUNTER_CLOCKWISE = 1, // p0->p1 反時計回りの方向にp2
	CLOCKWISE = -1, // p0->p1 時計回りの方向にp2
	ONLINE_BACK = 2, // p2->p0->p1 の順で直線上でp2
	ONLINE_FRONT = -2, // p0->p1->p2 の順で直線上p2
	ON_SEGMENT = 0, // p0->p2->p1 の順で線分p0p1上にp2
};
ccw_t ccw(Point p0, Point p1, Point p2) {
	Vector a = p1 - p0, b = p2 - p0;
	if ( cross(a, b) > EPS  )  return COUNTER_CLOCKWISE;
	if ( cross(a, b) < -EPS )  return CLOCKWISE;
	if ( dot(a, b) < -EPS )    return ONLINE_BACK;
	if ( a.norm() < b.norm() ) return ONLINE_FRONT;
	return ON_SEGMENT;
}

class Segment { //線分
public:
	Point p1, p2;
	Segment(){}
	Segment(Point p1, Point p2):p1(p1), p2(p2){}
};
using Line = Segment;

// *** 多角形 ***
// IN := 2, ON := 1, OUT := 0
vector<Segment> getPolygonSegument(const Polygon& p) { //多角形の点から多角形の辺を求める
	vector<Segment> ret;
	rep(i, p.size() - 1) ret.push_back(Segment(p[i], p[i + 1]));
	ret.push_back(Segment(p[p.size() - 1], p[0]));
	return ret;
}
int contains(Polygon g, Point p){ // 多角形gの中に点pが含まれているか
	int n = g.size(); bool x = false;
	for (int i = 0; i < n; ++i) {
		Point a = g[i] - p, b = g[(i + 1) % n] - p;
		if ( abs(cross(a, b)) < EPS && dot(a, b) < EPS ) return 1;
		if (a.y > b.y) swap(a, b);
		if (a.y < EPS && EPS < b.y && cross(a, b) > EPS ) x = !x;
	}
	return (x ? 2 : 0);
}
Polygon andrewScan(Polygon s) { // 凸包(最も左にある頂点から)
	Polygon u, l;
	if (s.size() < 3) return s;
	sort(s.begin(), s.end()); // x, yを基準に昇順ソート
	// xが小さいものから2つ u に追加
	u.push_back(s[0]), u.push_back(s[1]);
	// x が大きいものから2つ1に追加
	l.push_back(s[s.size() - 1]), l.push_back(s[s.size() - 2]);
	// 凸包の上部を生成
	for (int i = 2; i < s.size(); i++) {
		for (int n = u.size(); n >= 2 && ccw(u[n - 2], u[n - 1], s[i]) != CLOCKWISE; n--){
			u.pop_back();
		}
		u.push_back(s[i]);
	}
	// 凸包の下部を生成
	for (int i = s.size() - 3; i >= 0; i--) {
		for (int n = l.size(); n >= 2 && ccw(l[n - 2], l[n - 1], s[i]) != CLOCKWISE; n--){
			l.pop_back();
		}
		l.push_back(s[i]);
	}
	// 時計回りになるように凸包の点の列を生成
	reverse(l.begin(), l.end());
	for (int i = u.size() - 2; i >= 1; i--) l.push_back(u[i]);
	return l;
}


// *** 線分の交差判定 ***
bool intersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
	return ( ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && 
			 ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0 );
}
bool intersect(const Segment& s1, const Segment& s2) { // 交差していたらtrue
	return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}
//*** 線分の交点 ***
Point getCrossPoint(Segment s1, Segment s2) { // 線分の交点が存在するから調べた後つかうこと
	Vector base = s2.p2 - s2.p1;
	double d1 = abs(cross(base, s1.p1 - s2.p1)), d2 = abs(cross(base, s1.p2 - s2.p1));
	double t  = d1 / (d1 + d2);
	return s1.p1 + (s1.p2 - s1.p1) * t;
}
// *** 距離 ***
double getDistance(Point& a, Point& b) { // 点aと点bの距離
	return length(a - b);
}
double getDistanceLP(Line& l, Point& p) { // 直線sと点pの距離
	return length(cross(l.p2 - l.p1, p - l.p1) / length(l.p2 - l.p1));
}
double getDistanceSP(Segment s, Point p) { // 線分sと点pの距離
	if( dot(s.p2 - s.p1, p - s.p1) < EPS ) return length(p - s.p1);
	if( dot(s.p1 - s.p2, p - s.p2) < EPS ) return length(p - s.p2);
	return getDistanceLP(s, p);
}
double getDistanceSS(Segment s1, Segment s2) { // 線分s1と線分s2の交点
	if( intersect(s1, s2) ) return 0.0; //交わっているとき
	return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
			   min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}
double getDistancePolP(const Polygon& pol, const Point& p) { // 多角形polと点pの距離
	if(contains(pol, p) != 0) return 0.0; // 点が多角形の内部に含まれている
	double ret = 1e9;
	for(Segment& u : getPolygonSegument(pol)) ret = min(ret, getDistanceSP(u, p));
	return ret;
}
double getDistancePolPol(const Polygon& p1, const Polygon& p2) { // 多角形p1とp2の距離
	double ret = 1e9;
	for(Segment& u : getPolygonSegument(p1))for(Segment& v : getPolygonSegument(p2)) {
		ret = min(ret, getDistanceSS(u, v));
	}
	return ret;
}


class Rectangle { // 長方形
public:
	// 3 2
	// 0 1 (反時計回りに長方形の頂点をいれること)
	vector<Point> p; // 点を順番にいれること
	Rectangle(vector<Point>&p):p(p) {
		rep(i, 3) reps(j, i + 1, 4) { //適当な順番にいれても大丈夫なように?
			int cnt = 0;
			rep(k, 4) if(k != i && k != j) {
				cnt += ccw(p[i], p[j], p[k]) == COUNTER_CLOCKWISE;
			}
			if(cnt == 2) {
				swap(p[i + 1], p[j]);
				break;
			}
		}
	}
	bool intersect(const Segment& s) { // 線分sと長方形の少なくとも1辺が交差していればtrue
		bool flag = false;
		rep(i, 4) flag |= ::intersect(s, Segment(p[i], p[(i + 1) % 4]));
		return flag;
	}
	bool contain(const Point& pp) { // 点ppが長方形内に含まれれば(辺を含まない)true
		bool flag = true;
		rep(i, 4) flag &= ccw(p[i], p[(i + 1) % 4], pp) == COUNTER_CLOCKWISE;
		return flag;
	}
	bool contain(const Segment& s) { // 線分sが長方形内に含まれれば(辺を含まない)true
		return contain(s.p1) && contain(s.p2);
	}
};




const int MAX_N = 210;
using TYPE = double; // 距離の型を入れる
vector<pair<int, TYPE> > G[MAX_N];
vector<TYPE> dijkstra(int start){
	vector<TYPE> dist(MAX_N, INFF);
	dist[start] = 0;//dist[i] :=　start->iまでの最短距離
	priority_queue<pair<TYPE, int>, vector<pair<TYPE, int> >, greater<pair<TYPE, int> > >  que;
	que.push(make_pair(0, start));
	while(!que.empty()){
		TYPE cost; int u;//今までにかかった時間 現在の頂点
		cost = que.top().first, u = que.top().second;
		que.pop();
		if(dist[u] < cost) continue;
		for (auto tmp : G[u]){
			int v = tmp.first; TYPE time = tmp.second;//隣接する頂点 その頂点まで行く時間
			if(dist[v] > dist[u] + time){//u->v
				dist[v] = dist[u] + time;
				que.push(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}


int main(void) {
	

	while(1) {
		int N; scanf("%d", &N);
		if(N == 0) break;
		int NV[110], H[110];
		vector<vector<pair<double, double>>> p;
		rep(i, N){
			scanf("%d %d", &NV[i], &H[i]);
			vector<pair<double, double>> tmp;
			rep(j, NV[i]){
				double x, y; scanf("%lf %lf", &x, &y);
				tmp.pb(mp(x, y));
			}
			p.pb(tmp);
		}
		double theta, phi; scanf("%lf %lf", &theta, &phi);
		double Sx, Sy, Tx, Ty; scanf("%lf %lf %lf %lf", &Sx, &Sy, &Tx, &Ty);
		Point start(Sx, Sy), goal(Tx, Ty);

		vector<Polygon> v;
		rep(i, N){
			Polygon t;
			for(auto u : p[i]) t.pb(Shadow(u.fi, u.se, H[i], theta, phi));
			for(auto u : p[i]) t.pb(Point(u.fi, u.se));
			Polygon tt = andrewScan(t);
			v.pb(tt);
		}

		for(auto u : v) {
			for(auto k : u) printf("%f %f, ", k.x, k.y);
			printf("\n");
		}

		rep(i, MAX_N) G[i].clear();

		rep(i, v.size())rep(j, v.size()){
			if(i == j) continue;
			int s = i + 1, t = j + 1;
			auto dis = getDistancePolPol(v[i], v[j]);
			G[s].pb(mp(t, dis)), G[t].pb(mp(s, dis));
		}

		rep(i, v.size()){
			auto dis = getDistancePolP(v[i], start);
			G[0].pb(mp(i + 1, dis)), G[i + 1].pb(mp(0, dis));
		}
		rep(i, v.size()){
			auto dis = getDistancePolP(v[i], goal);
			G[N + 1].pb(mp(i + 1, dis)), G[i + 1].pb(mp(N + 1, dis));
		}

		auto ret = dijkstra(0);
		printf("%.9f\n", ret[N + 1]);
	}


	return 0;
}