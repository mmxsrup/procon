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

int G[10];
int ans = 1e9;
int keta;

void slove(int cnt, int* D){
	//どこまで一致してるか検証
	int point;
	rep(i, keta){
		if(D[i] != G[i]){
			point = i;//何文字目から違うか
			break;
		}
		if(i == keta - 1){
			ans = min(cnt, ans);
			return;
		}
	}

	reps(i, 1, keta){//何文字分動かすか
		cnt++;
		if(G[point] - D[point] >= 0){
			int sa = G[point] - D[point];
			reps(j, point, point + i){
				if(j > keta - 1) return;
				D[j] = (D[j] + sa) % 10;//mod
				ans = min(ans, slove(cnt, D));
			}
		}else{
			int sa = 10 + G[i] - D[i];
			reps(j, point, point + i){
				if(j > keta - 1) return;
				D[j] = (D[j] + sa) % 10;
				ans = min(ans, slove(cnt, D));
			}
		}
	}
	return;
}

int main(void){
	cin >> keta;

	int D[10];
	int d; cin >> d;
	int ten = pow(10, keta - 1);
	int i = 0;
	while(ten >= 1){
		D[i] = d / ten;
		printf("%d\n", D[i]);
		d %= ten;
		ten /= 10;
		i++;
	}

	int g; cin >> g;
	ten = pow(10, keta - 1); 
	i = 0;
	while(ten >= 1){
		G[i] = g / ten;
		g %= ten;
		ten /= 10;
		i++;
	}
	slove(0, D);
	printf("%d\n", ans);

	return 0;

}