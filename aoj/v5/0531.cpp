#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
int dy[4] = {0, 1, -1, 0};
int dx[4] = {1, 0, 0, -1};
int w, h, n;
vector<ll> xs, ys;//使用する座標
map<ll, ll> zipx, zipy, zipz;//<元, 圧縮後>
map<ll, ll> unzipx, unzipy, unzipz;//<圧縮後, 元>
bool fld[200][200];//テープの部分をtrue

int main(void){
	while(1){
		cin >> w >> h;
		if(w == 0 && h == 0) return 0;
		cin >> n;
		ll x1[101], x2[101], y1[101], y2[101];//与えられる座標
		rep(i, n){
			cin >> x1[i] >> y1[i];
			cin >> x2[i] >> y2[i];
		}

		for (int i = 0; i < n; ++i){
			for (int d = -1; d <= 1; ++d){
				int tx1 = x1[i] + d, tx2 = x2[i] + d;
				if(1 <= tx1 && tx1 <= w) xs.push_back(tx1);
				if(1 <= tx1 && tx1 <= w) xs.push_back(tx2);
			}
		}
		sort(xs.begin(), xs.end());
		xs.erase(unique(xs.begin(),xs.end()), xs.end());//重複消去
		rep(i, xs.size()){
			zipx[i] = xs[i];
			unzipx[xs[i]] = i;
		}

		for (int i = 0; i < n; ++i){
			for (int d = -1; d <= 1; ++d){
				int ty1 = y1[i] + d, ty2 = y2[i] + d;
				if(1 <= ty1 && ty1 <= w) ys.push_back(ty1);
				if(1 <= ty1 && ty1 <= w) ys.push_back(ty2);
			}
		}
		sort(ys.begin(), ys.end());
		ys.erase(unique(ys.begin(), ys.end()), ys.end());//重複消去
		rep(i, ys.size()){
			zipy[i] = ys[i];
			unzipy[ys[i]] = i;
		}

		///線のある部分を塗りつぶす
		memset(fld, 0, sizeof(fld));
		for (int i = 0; i < n; ++i){
			for (int x = unzipx[x1[i]]; x <= unzipx[x2[i]]; ++x){
				for (int y = unzipy[y1[i]]; y <= unzipy[y2[i]]; ++y){
					fld[x][y] = true;
				}
			}
		}

		//マスキングテープ以外の部分を塗っていく
		ll ans = 0;
		for (int y = 0; y < ys.size(); ++y){
			for (int x = 0; x < xs.size(); ++x){
				if(fld[y][x]) continue;
				ans++;
				// printf("%d %d\n", y, x);
				//幅優先探索
				queue<pair<int, int> > q; q.push(make_pair(y, x));
				printf("push %d %d\n", y, x);
				while(!q.empty()){
					auto now = q.front(); q.pop();
					rep(i, 4){
						int nowy = now.first + dy[i], nowx = now.second + dx[i];
						if(nowy < 0 || h <= nowy || nowx < 0 || w <= nowx) continue;
						if(fld[nowy][nowx]) continue;
						// printf("%d %d\n", nowy, nowx);
						q.push(make_pair(nowy, nowx));
						fld[nowy][nowx] = true;
					}
				}
			}
		}		
		cout << ans << endl;
		return 0;
	}
}