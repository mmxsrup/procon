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
#define rep(i,n) for(ll i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int main(void){
	int n, m;
	cin >> n >> m;
	vector<ll> s(n);//始点側
	vector<ll> t(n);//終端側
	rep(i, n) scanf("%lld %lld", &s[i], &t[i]);

	vector<ll> p;//糸の切断位置を小さい順
	//vector<ll> rp(m);//糸の切断位置を大きい順
	p.push_back(-1);
	rep(i, m){
		ll tmp; scanf("%lld", &tmp);
		p.push_back(tmp);
	}
	p.push_back(1e14);

	sort(all(p));
	//rp = p;
	//sort(all(rp));

	ll ans = 0;
	rep(i, n){
		int cnt = 0;//何個目の切断場所かを見るため
		//使い魔が持っている位置の方が小さい時
		if(s[i] <= t[i]){
			vector<ll>::iterator it = lower_bound(p.begin(),p.end(),s[i]);
			ll prv = s[i];
			while(*it < t[i] && cnt <= m){
				if(cnt % 2 == 0) ans += *it - prv;//偶数回目の切断は残った糸にカウントされる
				prv = *it;//前の切断位置を記憶する
				it++;//切断位置を進める
				cnt++;//切断回数を増やす
			}
			//爆弾の切断が糸の範囲を超えた時（端が残ったいとなら追加する）
			if(cnt % 2 == 0) ans += t[i] - prv;
		//使い魔が持っている位置の方が大きい時
		}else{
			vector<ll>::iterator it = upper_bound(p.begin(),p.end(),s[i]);
			it--;
			ll prv = s[i];
			while(*it > t[i] && cnt <= m){
				if(cnt % 2 == 0) ans += prv - *it;
				prv = *it;
				it--;
				cnt++;
			}
			if(cnt % 2 == 0) ans += prv - t[i]; 
		}
	}
	printf("%lld\n", ans);
	return 0;
}