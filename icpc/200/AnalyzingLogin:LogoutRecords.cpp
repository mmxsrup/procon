#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
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

bool flag[10001][721];//flag[sutuden][time]

//答えを出力
void print(void){
	int q;
	scanf("%d", &q);
	int l, r, m, cnt;
	rep(i, q){
		cnt = 0;//初期化
		scanf("%d %d %d", &l, &r, &m);
		for (int j = l - 540; j <= r - 540 ; ++j){
			if (flag[m - 1][j] == true) cnt++;//pcが付いている時を探す
		}
		printf("%d\n", cnt);
	}
	return;
}


//pcがいつ使われているかを登録する
void touroku(void){
	int r;
	scanf("%d", &r);
	int t, n, m, s;
	rep(i, r){
		scanf("%d %d %d %d", &t, &n, &m, &s);
		for (int i = t - 540; i <= 1000 ; ++i){
			if (0 <= i && i <= 720 && s == 1){
				flag[m - 1][i] = true;
			}else if(0 <= i && i <= 720 && s == 0){
				flag[m - 1][i] = false;
			}
		}
	}
	return;
	
}

int main(void){
	int N, M;//pcの数　学生数
	//rep(i, 10000) rep(j, 721) flag[i][j] = false;//初期化

	rep(i, 10000000){
		rep(i, 10000) rep(j, 721) flag[i][j] = false;//初期化
		scanf("%d %d", &N, &M);
		if(N == 0) break;
		touroku();
		printf("itirannhyou\n");
		rep(i, M){
			rep(j, 721){
				if (flag[i][j] == true) printf("1");
				else if(flag[i][j] == false) printf("0");
			}
			printf("\n");
		}
		print();
	}	
	return 0;
}