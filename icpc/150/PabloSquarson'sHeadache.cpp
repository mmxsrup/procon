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
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

void count(void){
	int ma_x = 0, mi_x = 0, ma_y = 0, mi_x = 0;
	rep(i, 400){
		rep(j, 400){
			if (board[i][j] == 1){
				max(ma_x, j);
				max(ma_y, i);
				min(mi_x, j);
				min(mi_y, i);
			}
		}
	}

	printf("%d %d\n", ma_x - mi_x + 1, ma_y - mi_y + 1);//答えを出力
	return;
}

void slove(int n){
	board[200][200] = 0;//土台設定
	rep(i, n - 1){
		
	}
	count();
	return;
}

int main((void){
	int n:
	rep(i, 1900){
		cin >> n;
		if (n == 0) break;
		slove(n)
	}
}