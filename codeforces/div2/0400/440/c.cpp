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

int q;
ll n[100010];

int main(void) {
	scanf("%d", &q);
	rep(i, q) scanf("%lld", &n[i]);

	rep(i, q) {
		ll a = n[i];
		if(a <= 3) printf("-1\n");
		else {
			if(a % 2 == 0) printf("%d\n", a / 4);
			else {
				if(a < 9) printf("-1\n");
				else if(a == 9) printf("1\n");
				else {
					ll d = a - 9;
					if(d < 4) printf("-1\n");
					else printf("%d\n", 1 + d / 4);
				}
			}
		}
	}
	return 0;
}