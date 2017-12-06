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

int h, w;
int memo[110][110];
int r[110][110];
const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

string s[110];

int main(void) {
	cin >> h >> w;
	rep(i, h) cin >> s[i];
	rep(i, h)rep(j, w) {
		bool f = true;
		if(s[i][j] == '.') continue;
		rep(k, 8) {
			int ny = i + dy[k], nx = j + dx[k];
			if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
			if(s[ny][nx] == '.') f = false;
		}
		if(f) {
			// printf("%d %d\n", i, j);
			memo[i][j] = 1;
		}
	}

	rep(i, h)rep(j, w) {
		if(memo[i][j] == 0) continue;
		rep(k, 8) {
			int ny = i + dy[k], nx = j + dx[k];
			if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
			r[ny][nx] = 1;
			// printf("n %d %d\n", ny, nx);
		}
		r[i][j] = 1;
	}

	bool f = true;
	rep(i, h)rep(j, w) {
		if(!((r[i][j] == 1 && s[i][j] == '#') || (r[i][j] == 0 && s[i][j] == '.'))) f = false;
	}
	if(f) {
		printf("possible\n");

		rep(i, h){
			rep(j, w) {
				if(memo[i][j] == 1) printf("#");
				else printf(".");
			}
			printf("\n");
		}
	}else{
		printf("impossible\n");
	}
	return 0;
}