#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

// typedef __int64 lint;

int main()
{
	int N, K;
	static int cube[128][128][128];
	int x1[64], x2[64], y1[64], y2[64], z1[64], z2[64];
	vector<int> xs, ys, zs;
	map<int, int> convx, convy, convz;
	map<int, int> motox, motoy, motoz;
	
	scanf("%d %d", &N, &K);
	
	for (int i = 0; i < N; i++){
		scanf("%d %d %d %d %d %d", x1 + i, y1 + i, z1 + i, x2 + i, y2 + i, z2 + i);
		xs.push_back(x1[i]); xs.push_back(x2[i]);
		ys.push_back(y1[i]); ys.push_back(y2[i]);
		zs.push_back(z1[i]); zs.push_back(z2[i]);
	}
	
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	sort(zs.begin(), zs.end());
	

	int idx = 0;
	convx[xs[0]] = idx;
	motox[idx++] = xs[0];
	for (int i = 1; i < 2 * N; i++){
		if (xs[i] != xs[i - 1]){
			convx[xs[i]] = idx;
			// printf("unzip[%d] = %d\n", xs[i], idx);
			motox[idx] = xs[i];
			// printf("zip[%d] = %d\n", idx, xs[i]);
			idx++;
		}
	}

	printf("\n");
	idx = 0;
	convy[ys[0]] = idx;
	motoy[idx++] = ys[0];
	for (int i = 1; i < 2 * N; i++){
		if (ys[i] != ys[i - 1]){
			convy[ys[i]] = idx;
			// printf("unzip[%d] = %d\n", ys[i], idx);
			motoy[idx] = ys[i];
			// printf("zip[%d] = %d\n", idx, ys[i]);
			idx++;
		}
	}
	
	printf("\n");
	idx = 0;
	convz[zs[0]] = idx;
	// printf("unzip[%d] = %d\n", zs[0], idx);
	motoz[idx] = zs[0];
	// printf("zip[%d] = %d\n", idx, zs[0]);
	idx++;
	for (int i = 1; i < 2 * N; i++){
		if (zs[i] != zs[i - 1]){
			convz[zs[i]] = idx;
			// printf("unzip[%d] = %d\n", zs[i], idx);
			motoz[idx] = zs[i];
			// printf("zip[%d] = %d\n", idx, zs[i]);
			idx++;
		}
	}


	
	for (int i = 0; i < N; i++){
		// printf("%d %d %d %d %d %d\n", convx[x1[i]], convy[y1[i]], convz[z1[i]], convx[x2[i]], convy[y2[i]], convz[z2[i]]);
		for (int x = convx[x1[i]]; x < convx[x2[i]]; x++){
			for (int y = convy[y1[i]]; y < convy[y2[i]]; y++){
				for (int z = convz[z1[i]]; z < convz[z2[i]]; z++){
					// printf("%d %d %d\n", x, y, z);
					cube[x][y][z]++;
				}
			}
		}
	}
	
	long long ans = 0;
	for (int i = 0; i < 128; i++){
		for (int j = 0; j < 128; j++){
			for (int k = 0; k < 128; k++){
				/*if (cube[i][j][k] >= K){
					printf("!!\n");
					printf("motox[i + 1] = %d motox[i] = %d motoy[j + 1] = %d motoy[j] = %d motoz[k + 1] = %d motoz[k] = %d\n", motox[i + 1], motox[i], motoy[j + 1], motoy[j], motoz[k + 1], motoz[k]);
				}*/
				ans += (cube[i][j][k] >= K ? (motox[i + 1] - motox[i]) * (motoy[j + 1] - motoy[j]) * (motoz[k + 1] - motoz[k]) : 0);
			}
		}
	}
	
	printf("%lld\n", ans);
	
	return (0);
}