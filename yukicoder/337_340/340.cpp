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
#define REP(i,n) for (int i=(n)-1;i>=0;i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define REPS(i,f,n) for (int i=(f)-1;i>=(n);i--)
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};



int w, h, n;
int board[1001][1001];

//大人が通った場所をboard配列に１としてフラグを立てていく
void flag(int num){
	int dy_tmp = num / w;
	int dx_tmp = num % w;
	board[dy_tmp][dx_tmp] = 1;
}


int main(void){
	cin >> w >> h >> n;

	//大人が通った場所を記載する配列を初期化　0は通ってない
	rep(i, h){
		rep(j, w)
			board[i][j] = 0;
	}


	int tmp1, tmp2, m;

	//大人が通った場所ますの数字をメモっていく
	rep(i, n){
		cin >> m;
		cin >> tmp1; //１回めの入力
		rep(j, m){ //1~m回目の入力
			cin >> tmp2;

			if (tmp1 % w == tmp2 % w){
				//縦移動
				if (tmp1 >= tmp2){
					for (int k = tmp1; k >= tmp2; k -= w){
						flag(k);
						tmp1 = tmp2;
					}
				}else{
					for (int k = tmp1; k <= tmp2; k += w){
						flag(k);
						tmp1 = tmp2;
					}
				}
			}

			if(tmp1 % w != tmp2 % w){
				if (tmp1 >= tmp2){
					for (int l = tmp1; l >= tmp2; --l){
						flag(l);
						tmp1 = tmp2;
					}
				}else{
					for (int l = tmp1; l <= tmp2; ++l){
						flag(l);
						tmp1 = tmp2;
					}
				}
			}
		}
	}


	//子供がどこを通るかを確かめる
	queue<pint> q;//現在の位置を入れていく
	q.push(mp(0, 0));
	int cnt = 0;
	
	int record[1010][1010];
	rep(i, h){
		rep(j, w)
			record[i][j] = 0;
	}


	while(!q.empty()){
		pint tmp = q.front(); //tmp(y, x)情報
		q.pop();

		rep(i, 4){
			int dy_board = tmp.fi + dy[i];
			int dx_board = tmp.se + dx[i];

			if (0 <= dx_board && dx_board <= w - 1 && 0 <= dy_board && dy_board <= h - 1 && board[tmp.fi][tmp.se] != 0){
				if (board[dy_board][dx_board] == 1 && record[dy_board][dx_board] == 0){
					record[dy_board][dx_board] = record[tmp.fi][tmp.se] + 1;
					q.push(mp(dy_board, dx_board));
				}
			}

			if (dy_board == h - 1 && dx_board == w - 1){
				printf("%d\n", record[h - 1][w - 1]);
				return 0;
			}
		}
	}

	printf("Odekakedekinai..\n");

	return 0;
}































