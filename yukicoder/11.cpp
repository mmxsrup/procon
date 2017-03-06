#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

const int MAX_W = 1000010, MAX_H = 1000010;
int cnt[MAX_W] = {0};
bool mark[MAX_W] = {false};
bool num[MAX_H] = {false};

int main(void){
	int w, h, n, ans = 0;
	cin >> w >> h >> n;
	vector<pair<int, int> > sk(n);
	rep(i, n){
		int s, k;
		cin >> s >> k; s--; k--;
		sk[i].first = s; sk[i].second = k;
	}

	//マークが同じで数字が異なるものを求める
	//一つのマークごとにいくつの数字があるかをメモっておく
	rep(i, n)cnt[sk[i].first]++;
	rep(i, w){
		if(cnt[i] != 0) ans += (h - cnt[i]);
	}

	// 数字が同じでマークが異なるものを求める
	//使用されているマークを調べる
	rep(i, n) mark[sk[i].first] = true;
	int cnt_mark = w;
	rep(i, w){
		if(mark[i]) cnt_mark--; 
	}

	//使用されている数字を調べる
	rep(i, n) num[sk[i].second] = true;
	int cnt_num = 0;
	rep(i, h){
		if(num[i]) cnt_num++;
	}
	ans += cnt_mark * cnt_num;
	
	cout << ans << endl;
	return 0;
}