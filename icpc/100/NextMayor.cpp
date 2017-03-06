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

void slove(int n, int p){
	int tyawan = p;//茶碗に入っている数
	vint person(n);//候補者が持っている数
	rep(i, n) person[i] = 0;//初期化
	int cnt = 0;
	do{
		if (tyawan >= 1){//１つとる
			person[cnt % n]++;//１回り終わった後のことも考えて、modで
			tyawan--;
		}else{//さらに全部入れる
			tyawan = person[cnt % n];
			person[cnt % n] = 0;
		}
		cnt++;

	} while (person[cnt % n] + tyawan != p);//次の人の情報で判断

	printf("%d\n", cnt % n);
	return;
}

int main(void){
	int n, p;
	scanf("%d %d", &n, &p);
	while(n != 0){
		slove(n, p);
		scanf("%d %d", &n, &p);
	}
	return 0;
}

