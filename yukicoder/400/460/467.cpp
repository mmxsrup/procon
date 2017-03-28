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

int n;
ll x, y;
int main(void){
	cin >> n;
	vector<ll> d(n);
	rep(i, n) cin >> d[i];
	sort(all(d));
	cin >> x >> y;
	if(x < 0) x *= -1;
	if(y < 0) y *= -1;

	if(max(x, y) == 0){
		printf("0\n");
		return 0;
	}else if(find(all(d), max(x, y)) != d.end()){
		printf("1\n");
		return 0;
	}else if(max(x, y) <= d.back() * 2){
		printf("2\n");
		return 0;
	}else{
		int dist = max(x, y) - d.back() * 2;
		int k = dist / d.back() + ((dist % d.back()) ? 1 : 0);
		int nokori = max(x, y) - k * d.back();
		// printf("%d %d %d %d\n", dist, k, nokori, d.back());
		if(nokori == 0) printf("%d\n", k);
		else if(find(all(d), nokori) != d.end()) printf("%d\n", k + 1);
		else printf("%d\n", k + 2);
	}
	return 0;
}