/*
015-c
幅優先探索
キュー
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

int slove(void){
	queue<pair<string, string> > name;
	queue<int> num;

	pair<string, string> now_name;
	int now_num;

	while(!name.empty() && !num.empty()){
		now_name = name.front();
		now_num = num.front();
		//キューから値を消す
		name.pop();
		num.pop();




	}
}

int main (void){
	for (int i = 0; i < N; ++i)
	{
		/* code */
	}

}