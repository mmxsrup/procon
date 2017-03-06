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



vector<int> vc(4);

void find(void){

	sort(all(vc));
	
	do{
		rep(i, 4)
			//クエリ出力
			printf("%d\n", vc[i]);

		//応答受けとり
		int x, y;
			scanf("%d %d", &x, &y);

		if (x == 4 && y == 0){
			return;
		}

	}while(next_permutation(all(vc)));

	return;
}


int main(void){
	int cnt = 0;
	rep(i, 10){

		rep(j, 4)
			printf("%d\n", i);

		int x, y;
		scanf("%d %d", &x, &y);

		if(x == 1 && y == 3){
			vc[cnt] = i;
			cnt++;
		}
	}

	find();

	return 0;
}
