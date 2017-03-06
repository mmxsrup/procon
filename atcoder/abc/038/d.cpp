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
#define REP(i,n) for (int i=(n)-1;i>=0;i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define REPS(i,f,n) for (int i=(f)-1;i>=(n);i--)
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};



int main(void){

	int n;
	cin >> n;

	vpint wh(n);
	vpint wh1(n);

	rep(i, n){
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		wh[i] = mp(tmp1, tmp2);
		wh1[i] = mp(tmp2, tmp1);
	}

  	// firstが小さい順、secondが小さい順にソート
	sort(wh.begin(), wh.end());
	// firstが大きい順、secondが大きい順にソート
	reverse(wh.begin(), wh.end());


	sort(wh1.begin(), wh1.end());
	reverse(wh1.begin(), wh1.end());
	
	ll cnt = 1;
	ll cnt1 = 1;

	int pre_w = wh[0].fi;
	int pre_h = wh[0].se;

	reps(i, 1, n){
		if (pre_w > wh[i].fi && pre_h > wh[i].se)
		{
			cnt++;
			pre_w = wh[i].fi;
			pre_h = wh[i].se;
		}
	}

	int pre1_w = wh1[0].fi;
	int pre1_h = wh1[0].se;

	reps(i, 1, n){
		if (pre1_w > wh1[i].fi && pre1_h > wh1[i].se)
		{
			cnt1++;
			pre1_w = wh1[i].fi;
			pre1_h = wh1[i].se;
		}
	}

	ll ans = max(cnt, cnt1);
	printf("%lld\n", ans);


	return 0;
}




























