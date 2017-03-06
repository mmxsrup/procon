//再帰関数を用いた深さ優先探索					
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <bitset>
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

int n, m, ans = 0;
bool memba[13][13];
//深さ優先探索を再帰関数で実行する部分
void dfs(vector<int> v, int num){
	//再帰関数を抜け出すための条件は必須
	if(num == n){
		rep(i, v.size()){
			reps(j, i + 1, v.size()){
				//vの中にどの番号の議員を選ぶかが入っているので、それらの人が互いに知り合いであるかを確かめる
				if(memba[v[i]][v[j]] == false) return;//一人でも知り合いでない組がいた終わり
			}
		}
		//大きな答えを見つけら、更新している
		ans = max(ans, (int)v.size());//v.size()は符号なし倍精度整数を返すので、int型に
	}else{
		//再帰呼び出し部分
		//選択しないで、再帰関数
		dfs(v, num + 1);
		//選択して、再帰関数
		v.push_back(num);//num番目の議員を選択することを示すためにvに議員の数字を入れる
		dfs(v, num + 1);//num番目の議員を選択したvを引数に渡して再帰関数を呼び出す
	}
}

int main(void){
	//初期化　falseはiとjが関係ないことを示す
	rep(i, 13)rep(j, 13) memba[i][j] = false;
	//入力部分
	cin >> n >> m;
	rep(i, m){
		int x, y;
		cin >> x >> y;
		//x-1はy-1と知り合いであるし、y-1はx-1と知り合いでもある
		memba[x - 1][y - 1] = memba[y - 1][x - 1] = true;//関係あることを示す
	}

	vector<int> v;
	int num = 0;//numは議員の番号を示す
	dfs(v, num);
	printf("%d\n", ans);
}