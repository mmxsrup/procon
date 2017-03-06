/*
幅優先探索
この問題の難しい点 – 「全探索」で解ける問題だが、「パターンの全列挙」が出来 るわけではない。 
• リモコンの押し方は無限通り存在する。 • 深さ優先探索だと、ずっとループしてしまう！ 
• 39 -> 40 -> 39 -> 40 -> 39 -> 40 -> 39 -> …… • ループしないように対策しても難しい。 
– だが、ボタンを押す回数を制限してしまえば、組み合わせ は有限通りしか存在しない。 – よって、押す回数が少ないパターンから順番に調べていく 
(http://www.slideshare.net/chokudai/wap-atcoder2)
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector> 
#include <functional>
#include <bitset>
#include <queue>
using namespace std;

typedef long long ll;
//typedef pair<int, int> P;

int A, B;
int d[6] = {1, 5, 10, -1, -5, -10};
int ans;

int slove(void){
	queue<pair<int, int> > Q; //Qのfirstは現在の温度、secondは操作回数
	Q.push(make_pair(A, 0)); //現在の温度と回数
	//Q.push(pair<int, int>(a, 0));	
	pair<int, int> now;

	while(!Q.empty()){
		now = Q.front(); //キューの中の値が使えるようにpairで作った変数に入れる
		Q.pop(); //キューから値をなくす
		if (now.first == B) //firstは今の温度
		{
			ans = now.second; //secondは何階操作したかを示している
			return ans;
		}

		//まだ、目標温度にいたってない時
		for (int i = 0; i < 6; ++i)
		{
			int next = now.first + d[i];
			Q.push(make_pair(next, now.second + 1));
		}
	}
	return 0;
}

int main(void){
	scanf("%d %d", &A, &B); //A: now  B: aim
	printf("%d\n", slove());

	return 0;
}



/*
参考用プログラム
include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
int a,b;
int d[6] = {1,5,10,-1,-5,-10};
 
int solve(){
    queue<P> q;
    q.push( P(a,0) );
    map<int,bool> m;

    while( !q.empty() ){
        P now = q.front(); q.pop();
        m[now.first] = true;
        if( now.first == b ){
            return now.second;
        }
	
        for(int i=0 ; i < 6 ; i++ ){
            int next = now.first + d[i];
            if( m[next] != true ){
                q.push( P(next,now.second+1) );
            }
        }
    }
    return -1;
}
 
int main(){
    cin >> a >> b;
    cout << solve() << endl;
}

*/

