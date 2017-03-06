#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int d[] = {1, 5, 10, -1, -5, -10};
int main(void){
	int a, b; cin >> a >> b;
	queue<pair<int, int> > q;
	q.push(make_pair(a, 0));
	while(!q.empty()){
		auto t = q.front(); q.pop();
		if(t.first == b){
			printf("%d\n", t.second);
			return 0;
		}
		rep(i, 6){
			int now = t.first + d[i];
			q.push(make_pair(now, t.second + 1));
		}
	}
}