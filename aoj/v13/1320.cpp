/*
最後尾に新たな文字列を加える場合，直前の文字列との重複判定だ
け行えばよく，dp[2n][n]（１次元目は利用文字列集合 2 次元は最後尾の文字列）
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

const int MAX_N = 15;
const int INF = 1e9;


int cost[MAX_N][MAX_N];//cost[i][j] := (文字列jを文字列iにつなげると何文字多くなるか)
//文字列jを文字列iの後ろにつなげてできる文字列の長さから文字列iの長さを引いた
int dp[1<<MAX_N][MAX_N];

//文字列aを文字列bの後ろから繋げて、どのくらい一致する部分があるかを求める関数
int getcost(string a, string b){
	int res = INF;
	//文字列aの長さを長く(後ろから前)、文字列bを長くし(前から後ろへ)、利用できる文字列の長さを計算
	for (int i = a.size() - 1, st = 0; i >= 0 && st < b.size(); --i, ++st){
		string ca = a.substr(i, a.size() - i);//文字列aのi文字目最後まで
		string cb = b.substr(0, st + 1);//文字列bの0文字目からst+1文字目
		if(ca == cb) res = st + 1;
	}
	return res;
}

int main(void){
	int n;
	while(1){
		cin >> n;
		if(n == 0) return 0;
		vector<string> tmp(n);
		vector<string> name;
		rep(i, n) cin >> tmp[i];

		rep(i, n){
			bool flag = false;
			rep(j, n){
				if(i == j) continue;
				//文字列tmp[j]の中に、文字列tmp[i]が含まれていないかを調べている
				if(tmp[j].find(tmp[i]) != string::npos){
					flag = true;//文字が含まれていたことを示す
					break;
				}
			}
			//文字列tmp[i]は他の文字列の中に完全に含まれないので、dp操作で使うためにnameに入れる
			if(flag == false) name.push_back(tmp[i]);
		}
		n = name.size();//実際にdp操作で使う数

		rep(i, MAX_N)rep(j, MAX_N) cost[i][j] = INF;
		//文字列[i]の後ろに文字列[j]をつける時のcostを計算
		rep(i, n){
			rep(j, n){
				if(i ==	j){
					cost[i][j] = name[i].size();
					continue;
				}
				int ct = getcost(name[i], name[j]);
				if(ct == INF) cost[i][j] = name[j].size();//使える部分がない
				else cost[i][j] = name[j].size() - ct;
			}
		}

		rep(i, 1<<MAX_N)rep(j, MAX_N) dp[i][j] = INF;//最小値を探すので初期化は大きいもので
		rep(i, n) dp[1<<i][i] = name[i].size();//１つの文字列だけが集合

		//bitDpを使って解く
		//dp[1<<n][i] 状態（1<<n）で現在文字列iにいる時の最小コスト　とした
		rep(S, (1<<n)){
			rep(mae, n){//前側文字列
				if(!(S>>mae) & 1) continue;//前側文字列がない
				rep(usiro, n){//後ろ側文字列
					if((S>>usiro) & 1) continue;//後ろ側の文字列がすでに集合内に存在する
					//漸化式計算部分
					dp[S|(1<<usiro)][usiro] = min(dp[S|(1<<usiro)][usiro], dp[S][mae] + cost[mae][usiro]);
				}
			}
		}
		int ans = INF;
		rep(i, n) ans = min(ans, dp[(1<<n) - 1][i]);

		printf("%d\n", ans);
	}
	return 0;
}

for (int i = 0; i < count; ++i)
{
	/* code */
}
	