//sを行列式とみなして、行列式を解けばよい。偶奇だけ答えれば良いのでオーバーフローはしなさそう。
//（完全マッチングの個数 == 行列式ではない。しかし、a + b (mod 2) == a - b(mod2)を利用すると、modだけなら行列式でOKなことが分かる（＞＜））
//これはオーバーフローします。適当に求めると小数点が発生するので、逐次modができず、苦労します。
//(a + b) (mod 2) == (a - b) (mod 2), ab (mod 2) == -ab (mod 2)だよね…。ん？ということは…（引き算の代わりにxorが使える！！！）
//これなら行列式の各成分の値を0, 1にできる -> 常勝！！
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
 
int n;
int s[200][200];
 
 
signed main() {
	int i, j, k;
	
	cin >> n;
	for (i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (j = 0; j < n; j++) {
			s[i][j] = (tmp[j] - '0');
		}
	}
	
	//i行目を00…x…000にする
	for (i = 0; i < n; i++) {
		//i列目が0でない行を探す（見つけたら即採用してよい→なぜ？：存在しなければ行列式=0, 採用する行によらず行列式の値が変化しないように変形するから）
		int pivot = -1;
		for (j = i; j < n; j++) {
			if (s[j][i] != 0) {
				pivot = j;
				break;
			}
		}
		if (pivot == -1) {
			cout << "Even" << endl;
			return 0;
		}
		
		//pivot行目とi行目を交換する。(pivot != iなら)これで行列式の答えが-1倍 -> 偶奇は変わらない）
		for (j = 0; j < n; j++) {
			swap(s[pivot][j], s[i][j]);
		}
		
		//i行目のj(≠i)列目を0にする。
		for (j = 0; j < n; j++) {
			if (j != i && s[i][j] == 1) {
				for (k = 0; k < n; k++) {
					s[k][j] ^= s[k][i];
				}
			}
		}
	}
	
	int ans = 1;
	for (i = 0; i < n; i++) {
		ans *= s[i][i];
	}
	cout << ((ans % 2) ? "Odd" : "Even") << endl;
	return 0;
}