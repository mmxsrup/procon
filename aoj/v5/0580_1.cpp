#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int n, k;
vector<ll> xs, ys, zs;
map<ll, ll> zipx, zipy, zipz;//<元, 圧縮後>
map<ll, ll> unzipx, unzipy, unzipz;//<圧縮後, 元>
int num[100][100][100];//魚の種類を入れる

int main(void){
	cin >> n >> k;
	ll x1[51], x2[51], y1[51], y2[51], z1[51], z2[51];//与えられる座標
	rep(i, n){
		cin >> x1[i] >> y1[i] >> z1[i];
		cin >> x2[i] >> y2[i] >> z2[i];
		xs.push_back(x1[i]); xs.push_back(x2[i]);
		ys.push_back(y1[i]); ys.push_back(y2[i]);
		zs.push_back(z1[i]); zs.push_back(z2[i]);
	}
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(),xs.end()), xs.end());//重複消去
	sort(ys.begin(), ys.end());
	ys.erase(unique(ys.begin(), ys.end()), ys.end());
	sort(zs.begin(), zs.end());
	zs.erase(unique(zs.begin(), zs.end()), zs.end());

	rep(i, xs.size()){
		zipx[i] = xs[i];
		unzipx[xs[i]] = i;
		// printf("unzip[%d] = %d\n", xs[i], i);
		// printf("zip[%d] = %d\n", i, xs[i]);
	}
	rep(i, ys.size()){
		zipy[i] = ys[i];
		unzipy[ys[i]] = i;
		// printf("unzip[%d] = %d\n", ys[i], i);
		// printf("zip[%d] = %d\n", i, ys[i]);
	}
	rep(i, zs.size()){
		zipz[i] = zs[i];
		unzipz[zs[i]] = i;
		// printf("unzip[%d] = %d\n", zs[i], i);
		// printf("zip[%d] = %d\n", i, zs[i]);
	}

	memset(num, 0, sizeof(num));
	for (int i = 0; i < n; ++i){
		// printf("%d %d %d %d %d %d\n", unzipx[x1[i]], unzipy[y1[i]], unzipz[z1[i]], unzipx[x2[i]], unzipy[y2[i]], unzipz[z2[i]]);
		for (int x = unzipx[x1[i]]; x < unzipx[x2[i]]; ++x){
			for (int y = unzipy[y1[i]]; y < unzipy[y2[i]]; ++y){
				for (int z = unzipz[z1[i]]; z < unzipz[z2[i]]; ++z){
					// printf("%d %d %d \n", x, y, z);
					num[x][y][z]++;
				}
			}
		}
	}
	ll ans = 0;
	rep(x, 100)rep(y, 100)rep(z, 100){
		if(num[x][y][z] >= k){
			// printf("%lld\n", zipx[x + 1] - zipx[x]);
			// printf("%lld\n", zipy[x + 1] - zipy[y]);
			// printf("%lld\n", zipz[x + 1] - zipz[z]);
			ans += ((zipx[x + 1] - zipx[x]) * (zipy[y + 1] - zipy[y]) * (zipz[z + 1] - zipz[z]));
		}
	}
	cout << ans << endl;
	return 0;
}