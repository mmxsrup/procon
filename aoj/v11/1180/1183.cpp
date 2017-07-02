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
#define chmax(a, b) a = max(a, b);
#define chmin(a, b) a = min(a, b);
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

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

class Circle {
public:
	Point c;
	double r;
	Circle(Point c = Point(), double r = 0.0):c(c), r(r) {}
}
double arg(Vector p) { return atan2(p.y, p.x); }
Vector polar(double a, double b) { return Point(cos(r) * a, sin(r) * a); }
pair<Point, Point> getCrossPoints(Circle c1, Circle c2) {
	assert(intersect(c1, c2));
	double b = abs(c1.c - c2.c);
	double a = acos(c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d);
	double t = arg(c2.c - c1.c);
	return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}

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
		int n; scanf("%d", &n);
		if(n == 0) break;
		double x[110], y[110], r[110];
		int start = 0, end;
		// startの中心と他の円の交点と中心へ引けるときは引く
		reps(i, n - 1){
			auto t = getCrossPoints(Circle(Point(x1, y1), r[i]));
			Segment s1(Point(x[0], y[0]), t.fi), s2(Point(x[0], y[0]), t.se);
			// 線分が円に含まれているか判定
			rep(j, i + 1){

			}
		}


		rep(i, 1, n)reps(j, i + 1, n){

		}
	}
	return 0;
}

