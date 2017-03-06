#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
static const int INF = 1e9;

int erace(int n, vector<int> v, int num, int c){//ボールの個数　ボール（数字）の配列　色を変えた場所 変えた色の番号
	int n_tmp = n;//残っているボールの番号
	int l = num;//色変えた場所の番号
	int r = num + 1;
	int color = c;//変えた場所の数字の番号（色）
	while(1){
		int cnt = 0;//同じ数字が連続している数
		//左側に何個同じ色が連続しているか
		while(0 <= l && v[l] == color){
      		cnt++;
      		l--;//左端を伸ばす
    	}
    	//右側に何個同じ色が連続しているか
    	while(r < n && v[r] == color){
      		cnt++;
      		r++;//右端を伸ばす
    	}
   		if(cnt >= 4){
    		n_tmp -= cnt;//連続した数の分を消す
    		if(v[l] == v[r]){
	    		color = v[l];//次に消える色を更新する
	    	}
    		else break;//消した後の両サイドが同じ色でなければ、それ以上消えることはない
    	}else{
    		break;//４つ消えなければ、それ以上消えることはない
    	}
	}
	return n_tmp;
}

int main(void){
	while(1){
		int n; scanf("%d", &n);
		if(n == 0) return 0;
		vector<int> v(n);
		rep(i, n) scanf("%d", &v[i]);
		int ans = INF;//初期化
		//全探索
		rep(i, n){//色を変えるとこの番号
			int tmp = v[i];
			//色を変える
			reps(j, 1, 4){//色を変える
				if(tmp == j) continue;
				v[i] = j;
				ans = min(ans, erace(n, v, i, j));
			}
			v[i] = tmp;//ボールの色を元に戻す
		}
		printf("%d\n", ans);
	}
	return 0;
}