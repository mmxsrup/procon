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

int cnt;
vector<int> v;//約数であり素数でもある数を昇順に入れていく

void print(int num){
	printf("%d:", num);
	rep(i, cnt) printf(" %d", v[i]);
	printf("\n");
	return;
}

//その約数が素数かどうかを確かめる
void check(int yakusu){
	if (cnt == 0){
		v.push_back(yakusu);//cnt==0でくる約数はかならず素数でもある
		cnt++;
	}else{
		rep(i, cnt){
			if (yakusu % v[i] == 0) break;//v[i]に入っている素数で割り切れたので、素数ではない			

			//すでにv[i]に入っているもの全てで割り切れなかったので、素数である
			if (i == cnt - 1){
				cnt++;
				v.push_back(yakusu);
			}
		}
	}
	
	return;
}

void slove(int num){
	cnt = 0;//cntの初期化
	//約数であるかを探し、それが素数であるかをcheck()関数で判定へ
	for (int i = 6; i<= num; i += 7){
		if (num % i == 0) check(i);
		if (num % (i + 2) == 0) check(i + 2);
	}
	return;
}

int main(void){
	int n;
	rep(i, 1000000){
		scanf("%d", &n);
		if(n == 1) break;
		slove(n);
		print(n);
		v.clear();//vがグローバル変数に入っているので、これで削除しないと変な挙動に
	}	

	return 0;
}