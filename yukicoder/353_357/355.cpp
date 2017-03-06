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

void find(int a, int b, int c, int d){
	vector<int> vc(4);
	vc[0] = a;
	vc[1] = b;
	vc[2] = c;
	vc[3] = d;
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

	rep(i, 10){
		rep(j, 10){
			rep(k, 10){
				rep(l, 10){
					if (i != j && j != k && k != l && l != i && i != k && j != l)
					{
						printf("%d\n", i);
						printf("%d\n", j);
						printf("%d\n", k);
						printf("%d\n", l);
						int x, y;
						scanf("%d %d", &x, &y);

						if (x + y == 4)
						{
							find(i, j, k, l);
							return 0;
						}
					}
				}
			}
		}
	}

	return 0;
}















