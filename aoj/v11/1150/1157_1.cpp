#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
 
 
 
 
 
 
 
 
 
 
const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;
namespace std {
    bool operator < (const P& a, const P& b) {
        return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
}
double cross(const P& a, const P& b) {
    return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
    return real(conj(a)*b);
}
 
struct L : public vector<P> {
    L() {}
    L(const P &a, const P &b) {
        push_back(a); push_back(b);
    }
};
 
int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1;       // counter clockwise
    if (cross(b, c) < 0)   return -1;       // clockwise
    if (dot(b, c) < 0)     return +2;       // c--a--b on line
    if (norm(b) < norm(c)) return -2;       // a--b--c on line
    return 0;
}
 
bool intersectSS(const L &s, const L &t) {
    return ccw(s[0], s[1], t[0])*ccw(s[0], s[1], t[1]) <= 0 &&
        ccw(t[0], t[1], s[0])*ccw(t[0], t[1], s[1]) <= 0;
}
 
P projection(const L &l, const P &p) {
    double t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
    return l[0] + t*(l[0] - l[1]);
}
 
bool intersectSP(const L &s, const P &p) {
    return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS; // triangle inequality
}
 
double distanceSP(const L &s, const P &p) {
    const P r = projection(s, p);
    if (intersectSP(s, r)) return abs(r - p);
    return min(abs(s[0] - p), abs(s[1] - p));
}
 
double distanceSS(const L &s, const L &t) {
    if (intersectSS(s, t)) return 0;
    return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
        min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}
 
typedef vector<P> G;
 
#define curr(PP, i) PP[i]
#define next(PP, i) PP[(i+1)%PP.size()]
enum { OUT, ON, IN };
int contains(const G& g, const P& p) {
    bool in = false;
    for (int i = 0; i < g.size(); ++i) {
        P a = curr(g, i) - p, b = next(g, i) - p;
        if (imag(a) > imag(b)) swap(a, b);
        if (imag(a) <= 0 && 0 < imag(b))
            if (cross(a, b) < 0) in = !in;
        if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
    }
    return in ? IN : OUT;
}
 
 
 
 
 
 
 
int N;
L line;
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
     
    double x, y, xx, yy, h;
    while (cin >> N)
    {
        if (N == 0) return 0;
 
        cin >> x >> y; P s(x, y);
        cin >> x >> y; P t(x, y);
        line = L(s, t);
 
        double ans = 1000;
 
        rep(i, 0, N)
        {
            cin >> x >> y >> xx >> yy >> h;
 
            G poly;
            poly.push_back(P(x, yy));
            poly.push_back(P(x, y));
            poly.push_back(P(xx, y));
            poly.push_back(P(xx, yy));
 
            if (contains(poly, line[0]) == IN && contains(poly, line[1]) == IN)
            {
                ans = 0;
                continue;
            }
             
            double d = 1000;
            d = min(d, distanceSS(line, L(P(x, y), P(x, yy))));
            cout << d << endl;
            d = min(d, distanceSS(line, L(P(x, yy), P(xx, yy))));
            cout << d << endl;

            d = min(d, distanceSS(line, L(P(xx, yy), P(xx, y))));
            cout << d << endl;

            d = min(d, distanceSS(line, L(P(xx, y), P(x, y))));
            cout << d << endl;
            
 
            if (d < EPS)
            {
                ans = 0;
            }
            else if (d <= h + EPS)
            {
                ans = min(ans, d);
            }
            else
            {
                double r = (h * h + d * d) / (2.0 * h);
                ans = min(ans, r);
            }
        }
 
        printf("%.10f\n", ans);
    }
}