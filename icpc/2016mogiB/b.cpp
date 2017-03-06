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

int board[10][10];
int main(void){
	string s;
	while(1){
		cin >> s;
		int gyou = 0;
		int retu = 0;
		int size = s.size();
		rep(i, size){
			if(s[i] == '/'){
				printf("1bann i%d gyou%d retu%d\n", i, gyou, retu);
				gyou++;
				retu = 0;
				continue;
			}else if(s[i] == 'b'){
				printf("2bann i%d gyou%d retu%d\n", i, gyou,retu);
				board[gyou][retu] = 0;
				retu++;
				continue;
			}else{
				printf("3bann i%d gyou%d retu%d\n", i, gyou,retu);
				int num = s[i] - '0';
				printf("num%d\n", num);
				printf("retu %d retu + num %d\n", retu, retu + num);
				reps(j, retu, retu + num){
					board[gyou][j] = 1;
					printf("board %d gyou%d j%d\n", board[gyou][j], gyou, j);
				}
				retu += num;
				continue;
			}
		}

		printf("%d %d\n", gyou, retu);
		rep(i, gyou + 1){
			rep(j, retu){
				printf("%d", board[i][j]);
			}
			printf("\n");
		}

		int px, py, nx, ny;//yが行 xが列
		cin >> py >> px >> ny >> nx;
		swap(board[py - 1][px - 1], board[ny - 1][nx - 1]);
		rep(i, gyou + 1){
			rep(j, retu){
				printf("%d", board[i][j]);
			}
			printf("\n");
		}

		int cnt = 0 ;
		rep(i, gyou + 1){
			rep(j, retu){
				if(board[i][j] == 0){
					if(cnt > 0){
						printf("%d", cnt);
						cnt = 0;
					}
					printf("b");
				}else{
					cnt++;
				}
			}
			if(cnt > 0) printf("%d", cnt);
			if(i < gyou) printf("/");
			cnt = 0;
		}
		printf("\n");
	}
	return 0;
}