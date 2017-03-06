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

int Hash[1000000007];
char s[20];

int getchar(char ch){
	if (ch == 'A') return 1;
	else if (ch == 'C') return 2;
	else if (ch == 'G') return 3;
	else if (ch == 'T') return 4;
	else return 0;
}

//文字列から数値へ変換して、keyを生成する
int getkey(){
	int sum = 0, p = 1;
	rep(i, strlen(s)){
		sum += p * (getchar(s[i]));
		p *= 5;
	}
	return sum;
}

int main(void){
	int n;
	cin >> n;

	rep(i, n){
		char meirei[10];
		scanf("%s %s", meirei, s);

		if (meirei[0] == 'i'){
			//インサートする場合
			//ハッシュ関数を利用してハッシュ値を計算して、ハッシュ値の添字にフラグを代入する
			Hash[getkey()] = true;
		}else{
			//検索する場合
			if (Hash[getkey()])//すでにインサートずみの場合
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}