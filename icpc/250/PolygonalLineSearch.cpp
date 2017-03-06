
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
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

void slove(int n){
	//元データの作成
	int M; scanf("%d", &M);
	vpint deta(M - 1);//deta.fi:距離　deta.se:ベクトル方向
	int PX, PY, NX, NY;
	scanf("%d %d", &PX, &PY);
	rep(i, M - 1){
		scanf("%d %d", &NX, &NY);
		deta[i].fi = abs(NX - PX + NY - PY);

		printf("PX%d NX%d PY%d NY%d\n", PX, NX, PY, NY);
		if(NX > PX) deta[i].se = 0;
		else if(NX < PX) deta[i].se = 2;
		else if(NY < PY) deta[i].se = 3;
		else if(PY < NY) deta[i].se = 1;
		PX = NX; PY = NY;
	}

	rep(i, M - 1){
		printf("データの距離%d 向き%d\n", deta[i].fi, deta[i].se);
	}




	//確認するデータ
	rep(i, n){
		printf("%d番目のチェックです\n", i);
		int m; scanf("%d", &m);
		vpint v(m - 1);//v.fi:距離　deta.se:ベクトル方向
		int px, py, nx, ny;
		scanf("%d %d", &px, &py);
		rep(j, m - 1){
			scanf("%d %d", &nx, &ny);
			v[j].fi = abs(nx - px + ny - py);
			if(nx > px) v[j].se = 0;
			else if(nx < px) v[j].se = 2;
			else if(ny < py) v[j].se = 3;
			else if(py < ny) v[j].se = 1;
			px = nx; py = ny;
		}

		rep(j, m - 1){
			printf("%d回目の距離%d 向き%d\n", i, v[j].fi, v[j].se);
		}



		bool flag = true;
		//距離が等しいか確認している
		rep(j, m - 1){
			if(v[j].fi != deta[j].fi){
				flag = false;
				break;
			}
		}

		//ベクトルの向きが等しいか確認している
		if (flag ==  true){
			printf("%d番目で距離はおkだった\n", i);
			rep(j, 4){
				bool print = false;
				rep(k, m - 1){
					//+jは90度ずつ回して確認しているのと同じ
					if((v[k].se + j) % 4 != deta[k].se) break;
					if(k == m - 2){
						printf("print%d\n", i + 1);
						print = true;
						break;
					}
				}
				if(print == true) break;
			}
		}

	}
	printf("+++++\n");
	return;
}


int main(void){
	int n;
	while(1){
		scanf("%d", &n);
		if(n == 0) break;
		slove(n);
	}
	return 0;
}