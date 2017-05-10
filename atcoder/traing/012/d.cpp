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
#define rall(v) (v).rbegin(), (v).rend()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define OUT(x) cout << #x << " = " << x << endl; 
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

#define EPS 1e-10//誤差で計算できるように
#define equals(a, b) (fabs(a) - (b) < EPS)
class Point{
    public:
    double x, y;
    Point():x(0),y(0) {}
    Point(double x, double y):x(x),y(y) {}
    //ベクトルの演算を定義
    Point operator + (Point p){ return Point(x + p.x, y + p.y); }//和
    Point operator - (Point p){ return Point(x - p.x, y - p.y); }//差
    Point operator * (double a){ return Point(a * x, a * y); }//スカラー倍
    Point operator / (double a){ return Point(x / a, y / a); }
    //ベクトルの大きさ(原点からベクトルを表す点までの距離)
    double abs(){ return sqrt(norm()); }
    //ベクトルの大きさの2乗
    double norm(){ return x * x + y * y; }
    //ベクトルの大小関係を表す演算を定義
    bool operator < (const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
    bool operator == (const Point &p) const{
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
        //return equals(x, p.x) && equals(y, p.y);
    }
};
typedef Point Vector;
double dot(Vector a, Vector b){ //内積
    return a.x * b.x + a.y * b.y;
}
double cross(Vector a, Vector b){ //外積
    return a.x * b.y - a.y * b.x;
}
 
//反時計回りccw
int ccw(Point p0, Point p1, Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    //return値は変更すること
    if(cross(a, b) > EPS) return -2;//p0p1反時計回りの方向にp2
    if(cross(a, b) < -EPS) return -1;//p0p1時計回りの方向にp2
    if(dot(a, b) < -EPS) return 0;//p2p0p1の順で直線上にp2
    if(a.norm() < b.norm()) return 1;//p0p1p2の順で直線上にp2
    return 2;//p0p2p1の順で線分p0p1上にp2
}

bool intersect(Point p1, Point p2, Point p3, Point p4){
	return (ccw(p1, p2, p3) + ccw(p1, p2, p4) == -3 &&
			ccw(p3, p4, p1) + ccw(p3, p4, p2) == -3);
}

int Ax, Ay, Bx, By;
int N;
int X[110], Y[110];
int main(void){
	cin >> Ax >> Ay >> Bx >> By;
	cin >> N;
	rep(i, N) cin >> X[i] >> Y[i];
	int cnt = 0;
	rep(i, N){
		if(intersect(Point(Ax, Ay), Point(Bx, By),
			Point(X[i % N], Y[i % N]), Point(X[(i + 1) % N], Y[(i + 1) % N])))cnt++;
	}
	int ans = cnt / 2 + 1;
	printf("%d\n", ans);
	return 0;
}