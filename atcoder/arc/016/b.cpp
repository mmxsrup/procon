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
//#define int long long
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for (int i=(n)-1;i>=0;i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define REPS(i,f,n) for (int i=(f)-1;i>=(n);i--)
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

char board[101][10];
ll sum = 0;
int n;

void search_x(void){
	rep(i, n){
		rep(j, 9){
			if(board[i][j] == 'x')
				sum++;
		}
	}
}

void search_o(int i){//何列目かサーチするか
	int flag = 0;
	rep(j, n){
		if (board[j][i] == 'o' && flag == 0){//長押しに入った
			flag = 1;
		}else if(board[j][i] != 'o' && flag == 1){//長押しからでる
			flag = 0;
			sum++;
		}

		if (board[j][i] == 'o' && j == n - 1 && flag == 1)//最後とその前から長押しボタン
			sum++;
		if (board[j][i] == 'o' && j == n - 1 && flag == 0)//最後に長押しボタンを押す
			sum++;
	}
}

int main(void){
	cin >> n;
	rep(i, n){
		cin >> board[i];
	}

	search_x();
	//printf("sum%lld\n", sum);

	rep(i, 9){
		search_o(i);
	}

	printf("%lld\n", sum);

	return 0;
}