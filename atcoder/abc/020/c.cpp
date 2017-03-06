#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int h, w;
ll t;
pair<int, int> S, G;
string s[12];

bool bfs(int m){//m := #に行く時のコスト
	queue<tuple<int, int, ll, int>> q;
	//used[y][x][i] := (y,x)に#をi回通ってきた時の最短距離
	ll used[12][12][110];
	rep(i, 12)rep(j, 12)rep(k, 110)used[i][j][k] = INFF;
	q.push(make_tuple(S.fi, S.se, 0, 0));
	used[S.fi][S.se][0] = 0;//start
	while(!q.empty()){
		int y, x, black;
		ll cost;
		tie(y, x, cost, black) = q.front(); q.pop();
		rep(i, 4){
			int ny = y + dy[i], nx = x + dx[i];
			if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
			ll ncost = cost + (s[ny][nx] == '#' ? m : 1);
			int nblack = black + (s[ny][nx] == '#' ? 1 : 0);

			if(used[ny][nx][nblack] != INFF) continue;
			used[ny][nx][nblack] = ncost;//(ny,nx)に#をnblack回通って、最短距離ncostで来れたことを記録
			if(ny == G.fi && nx == G.se) continue;//goal
			q.push(make_tuple(ny, nx, ncost, nblack));
		}
	}
	rep(i, 110){//t以下でgoalに他取り付いているものがあるか調べる
		if(used[G.fi][G.se][i] <= t) return true;
	}
	return false;
}

int main(void){
	cin >> h >> w >> t;
	rep(i, h) cin >> s[i];
	rep(i, h)rep(j, w){
		if(s[i][j] == 'S') S.fi = i, S.se = j;
		if(s[i][j] == 'G') G.fi = i, G.se = j;
	}
	int l = 0, r = INF;
	while(r - l > 1){//2分探索
		int m = (l + r) / 2;
		if(bfs(m)) l = m;
		else r = m;
	}
	printf("%d\n", l);
	return 0;
}