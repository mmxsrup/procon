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

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int main(void) {
	while(1) {
		int W, H;
		string s[20];
		int memo[5][20][70]; // vec y x
		rep(i, 5)rep(j, 20)rep(k, 70) memo[i][j][k] = 0;
		
		scanf("%d %d", &W, &H);
		if(W == 0 && H == 0) break;
		rep(i, H) cin >> s[i];
		pair<int, int> start, goal;
		rep(i, H)rep(j, W){
			if(s[i][j] == 'K') start = mp(i, j);
			if(s[i][j] == 'M') goal = mp(i, j);
		}

		queue<tuple<int, int, int, bool>> q;
		set<string> stog;
		int cnt = 0;
		bool f = false; //帰りがある

		while(q.empty()) {
			int y, x, vec; bool flag; tie(y, x, vec, flag) = q.front(); q.pop();
			int ny = y + dy[vec], nx = x + dx[vec];
			if(s[ny][nx] == '#') { //　change vec
				if(s[y][x] == 'M'){
					cnt++;
					if(flag) f = true;
				} else {
					int rvec = (vec + 1) % 4, lvec = (vec - 1 + 4) % 4;
					int rny = y + dy[rvec], rnx = x + dx[rvec];
					int lny = y + dy[lvec], lnx = x + dx[lvec];
					bool rf = flag, lf = flag;
					if(s[rny][rnx] != '#') rf = false;
					if(s[lny][lnx] != '#') lf = false;

					if()que.push(make_tuple(rny, rnx, rvec, rf));
					que.push(make_tuple(lny, lnx, lvec, lf));
				}
			}else{
				q.push(make_tuple(ny, nx, vec, t));
			}
		}

		if(cnt == 0) {
			printf("He cannot bring tea to his master.\n");
		}
		else if(f) printf("He can accomplish his mission.\n");
		else printf("He cannot return to the kitchen.\n");

	}
	return 0;
}

/*
#######
##...##
###.#M#
#.....#
#.#...#
#.#..##
#.K####
#######
*/
