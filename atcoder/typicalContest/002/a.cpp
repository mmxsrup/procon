#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
int dy[] = {1, 0, 0, -1};
int dx[] = {0, 1, -1, 0};
int b[55][55];
int main(void){
	int r, c; cin >> r >> c;
	int sx, sy; cin >> sy >> sx;
	int gx, gy; cin >> gy >> gx;
	sx--;sy--;gx--;gy--;
	vector<string> s(r);
	rep(i, r) cin >> s[i];
	rep(i, 55)rep(j, 55) b[i][j] = -1;
	queue<pair<int, int> > q;
	q.push(make_pair(sy, sx));
	b[sy][sx] = 0;
	while(!q.empty()){
		auto now = q.front(); q.pop();
		rep(i, 4){
			int ny = now.first + dy[i], nx = now.second + dx[i];
			if(0 <= ny && ny < r && 0 <= nx && nx < c){
				if(s[ny][nx] == '.' && b[ny][nx] == -1){
					b[ny][nx] = b[now.first][now.second] + 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
	printf("%d\n", b[gy][gx]);
	return 0;
}