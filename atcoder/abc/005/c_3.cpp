/*queue
c_2.cppのように無理やりループを抜けるのではなく*/
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
	int B[100] = {1000};
	scanf("%d", &T);
	scanf("%d", &N);
	rep(i, N)
		scanf("%d", &A[i]);
	scanf("%d", &M);
	rep(i, M)
		scanf("%d", &B[i]);
 	
 	queue<pint> Q; //いつからいつまで手にはいるかを示すqueueを宣言
 	
 	//代入
 	rep(i, N)
 		Q.push(pint(A[i], A[i] + T));

 	int cnt = 0; //（何人目ー１）の客を相手しているかを示している
 	while(!Q.empty()){
 		pint tmp;
 		tmp = Q.front();

 		if (tmp.fi > B[cnt]){ //これを一度でも満たすと１人必ずタコが買えない人が出てくるので即座にno
 			printf("no\n");
 			return 0;
 		}else if(tmp.se < B[cnt]){ //もう売れなくなったタコはqueueから消す
 			Q.pop();
 		}else if(tmp.fi <= B[cnt] && tmp.se >= B[cnt]){//タコが買えるか確かめる
 			cnt++; //変えたことを確認して次の人へ
 			Q.pop(); //買ったタコを示すqueueは消す
 		}
 	}

 	if (cnt == M) //B[M - 1]の時にifにtureすればその後cnt == Mになる
 		printf("yes\n");
 	else
 		printf("no\n");

	return 0;
}