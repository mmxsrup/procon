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
int A[810][810];
int memo[810][810];
int sy, sx;
int main(void){
	cin >> H >> W >> K;
	rep(i, H)rep(j, W) cin >> A[i][j];
	rep(i, H)rep(j ,W) if(A[i][j] == 'S') sy = i, sx =j;
	// priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > q;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, sy, sx));
	while(!q.empty()){
		int flag, y, x;
		tie(flag, y, x) = q.front(); q.top();
		rep(i, 4){
			int ny = y + dy[i], nx = x + dx[i];
			if(!(0 <= ny && ny < H && 0 <= nx && nx < W)) continue;
			if(memo[ny][nx] != INF) continue;
			if(flag == 0){
				if(memo[ny][nx])
			}else{

			}
		}
	}
	return 0;
}