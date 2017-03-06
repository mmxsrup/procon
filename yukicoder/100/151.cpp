#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

ll al[20010];//左向き
ll ar[20010];//右向き
ll bl[20010];//1ツヅラし
ll br[20010];
int main(void){
	rep(i, 20010) al[i] = ar[i] = 0;

	int n, q; scanf("%d %d", &n, &q);
	rep(i, q){
		char x; int y, z;
		cin >> x >> y >> z;

		if(x == 'L'){
			al[y] += z;
		}else if(x == 'R'){
			ar[y] += z;
		}else if(x == 'C'){
			ll sum = 0;
			for (int p = y; p < z; ++p){
				sum += (al[p] + ar[p]);
			}
			printf("%lld\n", sum);
		}

		//移動
		for (int j = 0; j < n - 1; ++j){
			bl[j] = al[j + 1];
		}
		bl[n - 1] = ar[n - 1];
		for (int j = 0; j < n - 1; ++j){
			br[j + 1] = ar[j];
		}
		br[0] = al[0];

		rep(j, n){
			al[j] = bl[j];
			ar[j] = br[j];
		}
	}
	return 0;
}