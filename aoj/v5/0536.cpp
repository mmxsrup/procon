#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

#include <cstring>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int n, m, p, q, r;
deque<pair<int> > que;

int shuffle(int x, int y){
	bool f1 = false, f2 = false, f3 = false;
	int len1 = x, len2 = y - x, len3 = n - 5;
	auto q = que.front(); que.pop_front();
	int len = now.second - now.first + 1;
	int l = q.firsr, r.second, now = now.second - now.first + 1;//左端,右端, 現在の長さ
	while(f1 && f2 && f3){
		auto q = que.front(); que.pop_front();
		int len = now + q.second - q.first + 1;
		if(!f1){
			if(len1 <= x){
				now 
			}
			fl = true;
		}else if(!f2){

			f2 = true;
		}else{
			f2 = true;
		}
	}
}
int main(void){
	while(1){
		cin >> n; if(n == 0)return 0;
		cin >> m >> p >> q >> r;
		que.push_back(make_pair(1, n));
		rep(i, m){
			int x, y; cin >> x >> y;
			shuffle(x, y);
		}	
		q.push_back()
	}
}