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


const double EPS = 1e-10;
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

int main(void) {
	set<Point> se1;
	se1.insert({
		Point(1.000000000001, 1.000000000001),
		Point(1.000000000002, 1.000000000002),
		Point(1.000000000003, 1.000000000003),
		Point(1.000000000004, 1.000000000004),
		Point(1.000000000005, 1.000000000005),
		Point(1.000000000001, 1.000000000005),
		Point(1.000000000002, 1.000000000004),
	});
	cout << se1.size() << endl;
	return 0;
}