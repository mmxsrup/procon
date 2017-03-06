/*
AC
*/
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

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	int tmp_sei[m];
	int tmp_fu[m];

	int sei = 0, zero = 0, fu = 0, tmp;
	rep(i, m){
		scanf("%d", &tmp);
		if (tmp > 0){
			tmp_sei[sei] = tmp;
			sei++;
		}else if(tmp == 0){
			zero++;
		}else{
			tmp_fu[fu] = tmp * -1;
			fu++;
		}
	}
	vector<int> d_sei(sei);
	vector<int> d_fu(fu);

	rep(i, sei)
		d_sei[i] = tmp_sei[i];

	rep(i, fu)
		d_fu[i] = tmp_fu[i];

	//大きくなるように
	sort(d_sei.begin(), d_sei.end());
	//小さくなるように
	sort(d_fu.begin(), d_fu.end());

	int ans = 10000000;
	int sum;

	if (fu >= n - zero){
		//負だけからとる時
		sum = d_fu[n - zero - 1];
		//printf("fu%d\n", sum);
		ans = min(ans, sum);
	}
	if(sei >= n - zero){
		//正だけからとる時
		sum = d_sei[n - zero - 1];
		//printf("sei%d\n", sum);
		ans = min(ans, sum); 
	}

	//両方から取る時
	reps(i, 1 , n - zero) //i個
	{
		if(1 <= i && i <= fu && 1 <= n - i - zero && n - i - zero <= sei){
			if (d_fu[i - 1] <= d_sei[n - i - zero - 1]){
				sum = d_fu[i - 1] * 2 + d_sei[n - i - zero - 1];
			}else{
				sum = (d_fu[i - 1] + d_sei[n - i - zero - 1] * 2);
			}
			//printf("sum%d\n", sum);
		ans = min(ans, sum);
		}
	}
	printf("%d\n", ans);
	return 0;
}
