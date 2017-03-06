#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#define fi first
#define se second
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n, l; cin >> n >> l;
	vector<int> a;
	a.push_back(0);
	rep(i, n){
		int tmp; cin >> tmp;
		a.push_back(tmp);
	}
	a.push_back(0);
	priority_queue<pair<int, int> > q[2];
	for (int i = 1; i <= n; ++i){
		if(a[i - 1] < a[i] && a[i] > a[i + 1]){
			q[0].push(make_pair(a[i], i));
		}
	}
	bool flag = true;
	int cnt = 0;
	int ans = 0;
	while(flag){
		flag = false;
		auto pos = q[cnt % 2].top();
		int time = l - pos.fi;
		// printf("pos.fi=%d  pos.se=%d  time %d\n", pos.fi, pos.se, time);
		if(time == 0) break;
		ans += time;
		while(!q[cnt % 2].empty()){
			auto pos = q[cnt % 2].top(); q[cnt % 2].pop();
			// printf("%d ", pos.se);
			if(a[pos.se - 1] >= a[pos.se] || a[pos.se] <= a[pos.se + 1]) continue;
			if(pos.fi + time == l){
				a[pos.se] = 0;
				if(a[pos.se - 1] != 0 && pos.se >= 1){
					if(a[pos.se - 2] >= a[pos.se - 1] || a[pos.se - 1] <= a[pos.se]) continue;
					q[(cnt + 1) % 2].push(make_pair(a[pos.se - 1], pos.se - 1));//現在使っていない方に入れる
					flag = true;
				}
				if(a[pos.se + 1] != 0 && pos.se <= n){
					if(a[pos.se] >= a[pos.se + 1] || a[pos.se + 1] <= a[pos.se + 2]) continue;
					q[(cnt + 1) % 2].push(make_pair(a[pos.se + 1], pos.se + 1));
					flag = true;
				}
			}else{
				flag = true;
				a[pos.se] += time;
				q[(cnt + 1) % 2].push(make_pair(pos.fi + time, pos.se));
			}
		}
		// printf("\n");
		cnt++;
	}
	printf("%d\n", ans);
}