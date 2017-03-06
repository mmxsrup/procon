#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int h, w; scanf("%d %d", &h, &w);
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	int x, y;
	int cnt = 0;//壁の総数を入れる
	rep(i, h)rep(j, w){
		if(s[i][j] == '*') cnt++;
	}
	//行ごと和を取る
	vector<int> sumh(h, 0);
	rep(i, h){
		rep(j, w){
			if(s[i][j] == '*') sumh[i]++;
		}
	}
	//列ごとに和を取る
	vector<int> sumw(w, 0);
	rep(i, w){
		rep(j, h){
			if(s[j][i] == '*') sumw[i]++;
		}
	}

	bool flag = false;
	//爆弾を置く場所を全探索する
	for (int i = 0; i < h; ++i){
		for (int j = 0; j < w; ++j){
			int now = sumh[i] + sumw[j];
			if(s[i][j] == '*') now--;
			if(now == cnt){
				y = j + 1; x = i + 1;
				printf("YES\n");
				printf("%d %d\n", x, y);
				flag = true;
				return 0;
			}
		}
	}

	if(flag == false){
		printf("NO\n");
	}

	return 0;
}