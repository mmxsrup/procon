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

int cnt;
vector<int> v;//約数であり素数でもある数を入れていく


//答えを出力
void print(int num){
	printf("%d:", num);
	for (int i = 0; i < v.size(); ++i){
		printf(" %d", v[i]);
	}
	printf("\n");
	return;
}


//その約数が素数かどうかを確かめる
void check(int yakusu){
	for (int i = 6; i < yakusu; i += 7){
		if (yakusu % i == 0) return;
	}
	for (int i = 8; i < yakusu; i += 7){
		if (yakusu % i == 0) return;
	}

	v.push_back(yakusu);//素数であったので入れる
	return;
}

void slove(int num){
	//約数であるかを探し、それが素数であるかをcheck()関数で素数かどうかを判定へ
	for (int i = 6; i<= num; i += 7){
		if (num % i == 0) check(i);
		if (num % (i + 2) == 0) check(i + 2);
	}
	return;
}

int main(void){
	int n;
	rep(i, 10000000){
		scanf("%d", &n);
		if(n == 1) break;
		slove(n);
		print(n);
		v.clear();//vがグローバル変数に入っているので、これで削除しないと変な挙動に
	}	

	return 0;
}