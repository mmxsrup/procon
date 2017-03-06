#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
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
	queue<int> q[2];
	for (int i = 1; i <= n; ++i){
		if(a[i - 1] < a[i] && a[i] > a[i + 1]){
			q[0].push(i);
		}
	}
	bool flag = true;
	int cnt = 0;
	while(flag){
		flag = false;
		while(!q[cnt % 2].empty()){
			int pos = q[cnt % 2].front(); q[cnt % 2].pop();
			printf("%d ", pos);
			if(a[pos - 1] >= a[pos] || a[pos] <= a[pos + 1]) continue;
			a[pos]++;
			if(a[pos] == l){
				a[pos] = 0;
				if(a[pos - 1] != 0 && pos >= 1){
					q[(cnt + 1) % 2].push(pos - 1);//現在使っていない方に入れる
					flag = true;
				}
				if(a[pos + 1] != 0 && pos <= n){
					q[(cnt + 1) % 2].push(pos + 1);
					flag = true;
				}
			}else{
				flag = true;
				q[(cnt + 1) % 2].push(pos);
			}
		}
		printf("\n");
		cnt++;
	}
	printf("%d\n", cnt);
}