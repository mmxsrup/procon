//http://acm-icpc.aitea.net/index.php?plugin=attach&refer=2009%2FPractice%2F%E6%A8%A1%E6%93%AC%E5%9C%B0%E5%8C%BA%E4%BA%88%E9%81%B8%2F%E8%AC%9B%E8%A9%95&openfile=b.pdf

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	while(1){
		int n, d;//n country  d limit
		cin >> n >> d;
		if(n == 0 && d == 0) return 0;

		vector<pair<int, int> > inf(n);//fi 国のミサイルの戦力合計　se　次に排除することができるミサイルの番号
		rep(i, n) inf[i].fi = 0;//初期化
		rep(i, n) inf[i].se = 0;//初期化
		vector<vector<int> > misairu(n);//misairu[i][]にはi国のミサイルが入る

		rep(i, n){
			int m; scanf("%d", &m);
			misairu[i].resize(m);
			for (int j = m - 1; j >= 0 ; --j){//生成順にミサイルを取り除いていくので、逆順に入れる
				int c; scanf("%d", &c);
				misairu[i][j] = c;
				inf[i].fi += c;//ミサイル力の和を入れていく
			}
		}

		//貧欲法
		while(1){
			bool endflag = false;
			int cntflag = 0;
			rep(j, n){
				int size = misairu[j].size() - inf[j].se;//j国にあといくつミサイルが残っているか

				if(size <= 0) continue;
				int now = inf[j].se;//今、消すことができるミサイルの番号
				int tikara = misairu[j][now];//今現在なくそうとしているミサイルの威力
				int tmp = inf[j].fi;//合計値を保持しておく
				inf[j].fi -= tikara;//ミサイルを削除した時の威力の合計値
				//最大値と最小値を探す
				int dai = -1, syou = 10000000;
				//すべての国のミサイルの威力の合計値を計算
				rep(k, n){
					dai = max(dai, inf[k].fi);
					syou = min(syou, inf[k].fi);
				}

				if(dai - syou > d){//一番合計値が大きい国と小さい国の戦力の差がdを超えていないかをチェック
					inf[j].fi = tmp;//値を戻しておく
					cntflag++;
					if(j == n - 1 && cntflag == n){
						printf("No\n");
						endflag = true;
						break;
					}  
				}else{
					inf[j].se++;
				}
				//この時のすべての国のミサイルの合計値を計算
				int sum = 0;
				rep(j, n) sum += inf[j].fi;
				if(sum == 0){
					printf("Yes\n");
					endflag = true;
					break;
				}
			}
			if(endflag == true) break;
		}
	}
	return 0;
}