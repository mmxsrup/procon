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

int dx[8] = {1, 0, 0, -1, 1, -1, -1, 1};
int dy[8] = {0, 1, -1, 0, 1, 1, -1, -1};

char board[110][110];//board[y][x]
int kakomareteru[110][110];//１が入ってたら周りが黒で囲まれてる
char syuusyuku[110][110];//syuusyuku[y][x]
int h, w;

//黒の周りを全て黒が囲んでいる部分を求める
void tannsaku(void){
	rep(i, h){
		rep(j, w){
			if(board[i][j] == '#'){
				rep(k, 8){
					//周りの８方に動かす
					int nowy = i + dy[k];
					int nowx = j + dx[k];

					if(0 <= nowy && nowy <= h - 1 && 0 <= nowx && nowx <= w - 1 && board[nowy][nowx] == '.') break;
					if(k == 7) kakomareteru[i][j] = 1;//囲まれていることを示す
				}
			}
		}
	}

}

//上の関数で求めた８方向囲まれているものの周りを全て黒く塗り収縮の作業をしてみる
void nuritubusi(void){
	rep(i, h){
		rep(j, w){
			if(kakomareteru[i][j] == 1){
				syuusyuku[i][j] = '#';
				rep(k, 8){
					//周りの８方に動かす
					int nowy = i + dy[k];
					int nowx = j + dx[k];
					if(0 <= nowy && nowy <= h - 1 && 0 <= nowx && nowx <= w - 1){
						syuusyuku[nowy][nowx] = '#';
					}
				}
			}
		}
	}
}

int main(void){
	rep(i, 110) rep(j, 110) kakomareteru[i][j] = 0;//初期化
	rep(i, 110) rep(j, 110) syuusyuku[i][j] = '.';//初期化
 
 	//入力
	cin >> h >> w;
	rep(i, h){
		rep(j, w){
			cin >> board[i][j];
		}
		getchar();
	}

	tannsaku();
	nuritubusi();

	//収縮で再現できたかチェック
	rep(i, h){
		rep(j, w){
			if(board[i][j] != syuusyuku[i][j]){
				//違う場所があれば
				printf("impossible\n");
				return 0;
			}
		}
	}

	printf("possible\n");

	//出力
	rep(i, h){
		rep(j, w){
			if(kakomareteru[i][j] == 1) printf("#");
			else printf(".");
		}
		printf("\n");
	}

	return 0;
}