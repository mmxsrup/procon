#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <cstdio>
#include <cstdlib>
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

int main(void){
	int n, k;
	cin >> n >> k;
	vint x(k);
	vint y(k);
	rep(i, k){
		int tmpx, tmpy; cin >> tmpx >> tmpy;
		tmpx--; tmpy--;//0オリジンへ
		x[i] = tmpx; y[i] = tmpy;
	}

	vint goal(n);
	rep(i, n){
		int tmp; cin >> tmp;
		tmp--;
		goal[tmp] = i;
	}

	vint subgoal(n);
	rep(i, n){//iは何番目のがどこに行くか
		int nowline = i;
		rep(j, k){//j個目の横ラインを見ている 
			//printf("x:%d y:%d nowline%d\n", x[j], y[j], nowline);
			if(x[j] == nowline) nowline = y[j];
			else if(y[j] == nowline) nowline = x[j];
		}
		subgoal[nowline] = i;
	}

	vector<pair<int, int> > ans;
	int now = 0;
	while(now < n){
		if(subgoal[now] != goal[now]){//ソート順が違う時
			int point;
			
			reps(i, now, n){
				if(goal[now] == subgoal[i]) point = i;//pointには探している値の場所が入る
			}
			for (int i = point; i >= now + 1 ; --i){
				swap(subgoal[i], subgoal[i - 1]);
				ans.push_back(mp(i, i + 1));
			}
		}
		now++;
	}
	printf("%lu\n", ans.size());
	rep(i, ans.size()){
		printf("%d %d\n", ans[i].fi, ans[i].se);
	}
	return 0;

}