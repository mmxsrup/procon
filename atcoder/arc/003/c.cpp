#include <iostream>
#include <string>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int dy[] = {1, 0, 0, -1};
int dx[] = {0, 1, -1, 0};
const int INF = 1e9;
int h, w, sy, sx, gy, gx;
string c[510];

bool used_[510][510];
bool hantei(void){//s->gの判定
	rep(i, 510)rep(j, 510) used_[i][j] = false;
	queue<pair<int ,int> > q;
	q.push(make_pair(sy, sx));
	while(!q.empty()){
		auto now = q.front(); q.pop();
		rep(i, 4){
			int ny = now.first + dy[i], nx = now.second + dx[i];
			if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
			if(ny == gy && nx == gx){
				return true;
			}
			if(used_[ny][nx]) continue;
			if(c[ny][nx] == '#') continue;
			q.push(make_pair(ny, nx));
			used_[ny][nx] = true;
		}
	}
	return false;
}

int used[510][510];//最短何回目にたどり着けるか
bool bfs(double lim){
	rep(i, 510)rep(j, 510)used[i][j] = INF;
	queue<pair<int, int> > q;
	q.push(make_pair(sy, sx));
	used[sy][sx] = 1;
	while(!q.empty()){
		auto now = q.front(); q.pop();
		int t = used[now.first][now.second];
		rep(i, 4){
			int ny = now.first + dy[i], nx = now.second + dx[i];
			if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
			if(c[ny][nx] == '#') continue;
			if(used[ny][nx] != INF) continue;
			if(ny == gy && nx == gx) return true;
			//limより明るさ上か
			if(lim < (double)(c[ny][nx] - '0') * pow(0.99, t)){
				q.push(make_pair(ny, nx));
				used[ny][nx] = t + 1;
			}
		}
	}
	return false;
}

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

	if(!hantei()){
		printf("-1\n");
		return 0;
	}
	

	//２分探索
	double r = 10.0, l = 0.0;
	while(r - l > 1e-9){
		double mid = (l + r) / 2.0;
		// printf("mid %f\n", mid);
		if(bfs(mid)){//もっと大きくできる
			l = mid;
		}else{
			r = mid;
		}
	}
	printf("%.9f\n", l);
	return 0;
}