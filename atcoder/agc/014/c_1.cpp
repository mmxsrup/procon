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

int H, W, K;
string A[810];
int memo[810][810];
int sy, sx;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
void solve(){
	bool used[810][810];
	rep(i, 810)rep(j, 810) used[i][j] = 0;
	queue<tuple<int, int, int>> que;
	// rep(i, H)rep(j, W)if(memo[i][j] == tar) que.pb(mp(i, j));
	rep(y, H)rep(x, W){
		if(memo[y][x] != 0){
			que.push(make_tuple(0, y, x));
		}
	}
	while(!que.empty()){
		int kaisu, y, x;
		tie(kaisu, y, x) = que.front(); que.pop();
		if(kaisu < K){
			rep(k, 4){
				int ny = y + dy[k], nx = x + dx[k];
				if(!(0 <= ny && ny < H && 0 <= nx && nx < W)) continue;
				if(used[ny][nx]) continue;
				// if(A[ny][nx] != '#') continue;
				A[ny][nx] = '.';
				used[ny][nx] = 1;
				que.push(make_tuple(kaisu + 1, ny, nx));
			}
		}
	}
}

int main(void){
	cin >> H >> W >> K;
	rep(i, H) cin >> A[i];
	rep(i, H)rep(j ,W) if(A[i][j] == 'S') sy = i, sx =j;
	// priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > q;
	int ans = 0;
	memo[sy][sx] = 1;
	while(1){
		ans++;
		queue<tuple<int, int, int>> q;
		rep(i, H)rep(j, W) if(memo[i][j] != 0)q.push(make_tuple(0, i, j));
		while(!q.empty()){
			int kaisu, y, x;
			tie(kaisu, y, x) = q.front(); q.pop();
			if(kaisu < K){
				rep(k, 4){
					int ny = y + dy[k], nx = x + dx[k];
					if(!(0 <= ny && ny < H && 0 <= nx && nx < W)) continue;
					if(memo[ny][nx] != 0) continue;
					if(A[ny][nx] != '.') continue;
					// printf("%d %d %d\n", ans, ny, nx);
					q.push(make_tuple(kaisu + 1, ny, nx));
					memo[ny][nx] = 1;
					if(ny == 0 || nx == 0 || ny == H - 1 || nx == W - 1){
						printf("%d\n", ans);
						return 0;
					}
				}
			}else{
				break;
			}
		}
		solve();
		// rep(i, H)cout << A[i] << endl;
	}

	return 0;
}