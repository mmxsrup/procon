#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n, A; cin >> n >> A;
	A--;
	int a[210], sum = 0;
	rep(i, n){
		int t; cin >> t;
		a[i] = t;
		sum += t;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i){
		bool flagl = true, flagr = true;
		int l = A - i, r = A + i;
		if(l < 0) flagl = false;
		if(r >= n) flagr = false;

		if(l == r){
			if(a[l] == 1){
				ans++; sum--;
			}
		}else{
			if(!flagl && !flagr) break;
			if(!flagl && a[r] == 1){//右側しか見る場所がない
				ans++; sum--;
			}else if(!flagr && a[l] == 1){//左側しか見る場所がない
				ans++; sum--;
			}else{//両側見る場合がある
				if(a[l] == 1 && a[r] == 1){//２つの都市どちらにも、犯人いるなら確信できる
					ans += 2; sum -= 2;
				}else{//どちらかにしかいない場合確信できない(sum != 1)
					if(a[l] == 1) sum--;
					if(a[r] == 1) sum--;
				}
				//sum == 1だからといって、どちらに入るかはわからない
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}