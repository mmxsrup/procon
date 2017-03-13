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

// #define int long long

int dist(int x, int cx, int y, int cy){
	return (x - cx) * (x - cx) + (y - cy) * (y - cy);
}


signed main(void){
	int x1, y1, r;
	int x2, y2, x3, y3;
	cin >> x1 >> y1 >> r;
	cin >> x2 >> y2 >> x3 >> y3;
	if(x2 <= x1 - r and x1 + r <= x3 and y2 <= y1 - r and y1 + r <= y3)printf("NO\n");
	else printf("YES\n");
	int ma = 0;
	chmax(ma, dist(x2, x1, y2, y1));
	chmax(ma, dist(x2, x1, y3, y1));
	chmax(ma, dist(x3, x1, y2, y1));
	chmax(ma, dist(x3, x1, y3, y1));
	if(ma > r * r) printf("YES\n");
	else printf("NO\n");
	return 0;
}