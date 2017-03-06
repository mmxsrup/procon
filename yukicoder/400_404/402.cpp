#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
int d[3005][3005] = {0};
string s[3005];
// int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
// int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1, 1};
int dx[3] = {0, -1, -1,};
int dy[3] = {-1, -1, 0};
int dx1[3] = {1, 1, 0};
int dy1[3] = {0, 1, 1};
const int INF = 1e8;
int main(void){
	int h, w; cin >> h >> w;
	rep(i, w + 2){
		s[0].push_back('.');
		s[h + 1].push_back('.');
	}
	reps(i, 1, h + 1){
		cin >> s[i];
		s[i].insert(s[i].begin(), '.');
		s[i].push_back('.');
	}


	for (int i = 1; i < h + 1; ++i){//y h
		for (int j = 1; j < w + 1; ++j){//x w
			if(s[i][j] == '.') continue;
			int mini = INF;
			rep(k, 3){
				int y = i + dy[k], x = j + dx[k];
				printf("[%d %d]", i, j);
				if(0 <= x && x <= w + 1 && 0 <= y && y <= h + 1){
					printf("(%d %d)", y, x);
					mini = min(d[y][x], mini);
				}
			}
			printf("\n");
			d[i][j] = mini + 1;
			// printf("d[%d][%d] = %d\n", i, j, d[i][j]);
			rep(i, h + 2){
				rep(j, w + 2){
					printf("%d", d[i][j]);
				}
				printf("\n");
			}
			printf("-------------------\n");
		}
	}
	for (int i = h; i >= 1; --i){//y h
		for (int j = w; j >= 1; --j){//x w
			if(s[i][j] == '.') continue;
			int mini = INF;
			rep(k, 3){
				int y = i + dy1[k], x = j + dx1[k];
				printf("[%d %d]", i, j);
				if(0 <= x && x <= w + 1 && 0 <= y && y <= h + 1){
					printf("(%d %d)", y, x);
					mini = min(d[y][x], mini);
				}
			}
			printf("\n");
			if(d[i][j] > mini) d[i][j] = mini + 1;
			// printf("d[%d][%d] = %d\n", i, j, d[i][j]);
			rep(i, h + 2){
				rep(j, w + 2){
					printf("%d", d[i][j]);
				}
				printf("\n");
			}
			printf("-------------------\n");
		}
	}
	int ans = 0;
	rep(i, h + 2){
		rep(j, w + 2){
			ans = max(ans, d[i][j]);
		}
	}
	printf("%d\n", ans);

	return 0;
}