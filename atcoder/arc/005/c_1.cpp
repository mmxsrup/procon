#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int dy[] = {1, 0, 0, -1};
int dx[] = {0, 1, -1, 0};
int h, w; 
string c[510];
bool used[510][510][3];//k=0:壁壊し0 k=1:壁1壊し k=2:壁2壊し
int sy, sx, gy, gx;
int main(void){
	cin >> h >> w;
	rep(i, h) cin >> c[i];
	rep(i, h)rep(j, w){
		if(c[i][j] == 's'){
			sy = i; sx = j;
		}
		if(c[i][j] == 'g'){
			gy = i; gx = j;
		}
	}
	rep(i, 510)rep(j, 510)rep(k, 3)used[i][j][k]= false;

	queue<tuple<int, int, int> > q;
	q.push(make_tuple(sy, sx, 0));
	used[sy][sx][0] = true;
	while(!q.empty()){
		int y, x, t;
		tie(y, x, t) = q.front(); q.pop();
		if(y == gy && x == gx) break;//ゴール
		rep(i, 4){
			int ny = y + dy[i], nx = x + dx[i];
			if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
			if(t == 2 && c[ny][nx] == '#') continue;//もう壁壊せない
			if(used[ny][nx][t]) continue;//すでに調べている
			if(c[ny][nx] == '#'){
				used[ny][nx][t + 1] = true;
				q.push(make_tuple(ny, nx, t + 1));
			}else{
				used[ny][nx][t] = true;
				q.push(make_tuple(ny, nx, t));
			}
		}
	}

	rep(i, 3){
		if(used[gy][gx][i]){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}