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

int main(void){
	int T, N, M;
	int A[100];
	int B[100];
	scanf("%d", &T);
	scanf("%d", &N);
	rep(i, N)
		scanf("%d", &A[i]);
	scanf("%d", &M);
	rep(i, M)
		scanf("%d", &B[i]);

	//提供可能なたこが何個出来ているかを確かめる配列
	int tako[10000]={0}; //tako[1]てのはたこが一秒の時に何個出来てるかを示す配列
	rep(i, N){
		reps(j, A[i], A[i] + T + 1){ //A[i] takoが何秒後に出来上がるてのが入ってる配列
			tako[j]++;
		}
	}

	//売ったタコの数をへらしていく
	rep(i, M){
		if (tako[B[i]] == 0){
			//売れるタコがない
			printf("no\n");
			return 0;
		}else{
			/*reps(j, B[i], B[i] + T + 1)
				tako[j]-- ;*/
			tako[i]--;
		}
	}

	printf("yes\n");
	return 0;
}