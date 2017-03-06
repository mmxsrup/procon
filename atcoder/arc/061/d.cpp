#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
 
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int x[100010], y[100010];
 
int main(void){
	int h, w, n; cin >> h >> w >> n;
	set<pair<int, int> > s;
	set<pair<int, int> > used;
	rep(i, n){
		int a, b; cin >> a >> b;
		a--; b--;
		y[i] = a; x[i] = b;
		s.insert(make_pair(a, b));//y,x
	}
 
	ll ans[10];
	rep(i, 10) ans[i] = 0;
 
	rep(i, n){
		rep(j, 9){
			//黒の周りから3x3の真ん中となりうるものをcy,cx
			int cy = y[i] + dy[j], cx = x[i] + dx[j];
			if(!(0 <= cy && cy < h && 0 <= cx && cx < w)) continue;
			if(used.count(make_pair(cy, cx)) == 1)continue;//すでに調べた
			int tmp = 0;
			rep(k, 9){//cy,cxを中心とした3x3を調べる
				int ny = cy + dy[k], nx = cx + dx[k];
				if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) break;
				if(s.count(make_pair(ny, nx)) == 1)tmp++;
				if(k == 8){
					used.insert(make_pair(cy, cx));
					ans[tmp]++;
				}
			}
		}		
	}
	ll sum = 0;
	rep(i, 10){//1~9の合計
		sum += ans[i];
	}
	//0は全ての3x3から1~9の合計を引けばいい
	printf("%lld\n", ((ll)h - 2) * ((ll)w - 2) - sum);
	for (int i = 1; i <= 9; ++i){
		printf("%lld\n", ans[i]);
	}
	return 0;
}