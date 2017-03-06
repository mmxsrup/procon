/*行ごとの累積和を用いて和の計算を高速化*/
#include <bits/stdc++.h>
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

int n;
int board[60][60];//board[i][j] iは行 jは列
int memo_max[3000] = {0};

void slove(void){
	/*考えられるすべての長方形を全探索で探す*/
	for(int i = 1; i <= n; i++){//横幅の長さ
		for(int j = 1; j + i - 1<= n; j++){//左橋の場所
			for(int k = 1; k <= n; k++){//縦幅の長さ
				for(int l = 1; l + k - 1<= n; l++){//上端の場所
					//考えている長方形の面積を計算
					int menseki = i * k;
					//main関数内で累積したメモしてあるものを利用して、面積計算
					int sum = 0;
					/*多次元に累積和をとる方法はわからなかったので、行ごとに累積和をとったものを利用
					  lからl+k-1の行ごとに、累積和を利用した行ごとの和を求める*/
					for (int m = l; m <= l + k - 1; ++m)
						sum += board[m][j + i - 1] - board[m][j - 1];
					memo_max[menseki] = max(memo_max[menseki], sum);
				}
			}
		}
	}
	return;
}

int main(void){
	cin >> n;
	reps(i, 1, n + 1) board[i][0] = 0;//累積和しやすいように端っこを設定
	reps(i, 1, n + 1)reps(j, 1, n + 1){
		int d; cin >> d;
		//行ごとに累積和をとっている。２次元での累積和はとってない。
		board[i][j] += board[i][j - 1] + d;
	}

	slove();

	int q; cin >> q;
	rep(i, q){
		int p; cin >> p;
		int ans = 0;
		reps(j, 1, p + 1){
			//求める面積以下のもので最大のものを探す
			ans = max(ans, memo_max[j]);
		}
		printf("%d\n", ans);
	}
	 return 0;
}