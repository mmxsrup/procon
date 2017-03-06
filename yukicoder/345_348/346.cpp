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
	string s;
	cin >> s;
	ll s_size = s.size();

	vector<int> s_c;
	vector<int> s_w;
	ll cnt_c = 0;
	ll cnt_w = 0;

	//c,wがどの場所にあるかを調べている
	rep(i, s_size){
		if (s[i] == 'c'){
			s_c.push_back(i);
			cnt_c++;
		}
		else if(s[i] == 'w'){
			s_w.push_back(i);
			cnt_w++;
		}
	}

	ll s_c_size = s_c.size();
	ll s_w_size = s_w.size();
	ll ans = 0; 

	rep(i, s_c_size){
		rep(j, s_w_size){
			if (s_w[j] > s_c[i]){
				ans += ((s_w_size - j) * (s_w_size - j - 1)) / 2; //(s_w_size - j) C 2
				break;
			}
		}
	}

	printf("%lld\n", ans);

	return 0;

}