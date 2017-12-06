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

int N, M;
int board[1010][1010];
int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

int main(void) {
	cin >> N >> M;
	int y = 0, x = 0;
	int cnt = 1;
	board[0][0] = 1;
	while(cnt < M) {
		rep(i, 4) {
			while(1) {
				int ny = y + dy[i], nx = x + dx[i];
				if(!(0 <= ny && ny < N && 0 <= nx && nx < N)) {
					break;
				}
				if(board[ny][nx] == 1) {
					break;
				}
				cnt++;
				// printf("n %d %d cnt %d \n", ny + 1, nx + 1, cnt);
				y = ny, x = nx;
				board[y][x] = 1;
				if(cnt == M) break;
			}
			if(cnt >= M) break;
		}
	}
	printf("%d %d\n", y + 1, x + 1);
	return 0;
}