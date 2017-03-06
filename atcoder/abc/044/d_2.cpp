#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int n, l, q;
//nx[i][j] := x[j]からスタートして、2^i日後に行ける最も遠いホテルの番号(xの添字)
int nx[20][100010];
int main(void){
	cin >> n;
	vector<int> x(n);
	rep(i, n) cin >> x[i];
	cin >> l >> q;

	//ダブリング
	for (int j = 0; j < n; ++j){
		nx[0][j] = upper_bound(x.begin(), x.end(), x[j] + l) - x.begin() - 1;
	}
	for (int i = 1; i < 20; ++i){
		for (int j = 0; j < n; ++j){
			nx[i][j] = nx[i - 1][nx[i - 1][j]];
		}
	}

	//ダブリングしたものを利用して２分探索
	for (int k = 0; k < q; ++k){
		int a, b; cin >> a >> b;
		--a; --b;
		if(b < a) swap(a, b);
		int ans = 0;
		int now = a;
		for (int i = 19; i >= 0; --i){
			if(nx[i][now] < b){
				now = nx[i][now];
				ans += 1 << i;
			}
		}
		cout << ans + 1 << endl;
	}
}