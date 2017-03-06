#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int main(void){
	while(1){
		int n, k;
		scanf("%d %d", &n, &k);
		if(n == 0 && k == 0) return 0;
		//数字を文字列として扱う
		vector<string> data(n);//入力データを入れる
		set<string> num;//k個選んでできたものを入れる
		rep(i, n) cin >> data[i];
		
		sort(data.begin(), data.end());//昇順にしておく
		//next_permutaionで全順列を生成
		do{
			string tmp;
			//順列の前からk個をくっつける
			rep(i, k){
				tmp += data[i];
			}
			//setに入れることで、同じものをカウントしないようにする
			num.insert(tmp);
		}while(next_permutation(data.begin(), data.end()));
		printf("%lu\n", num.size());//個数を表示
	}
}