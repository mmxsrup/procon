#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;

int n;
string ans = "";
void priiwi(int t){
	string s = "iwi";
	rep(i, t - 1){
		s += "wi";
	}
	ans += s;
	return;
}

void priyzy(int t){
	string s = "yzy";
	rep(i, t - 1){
		s += "zy";
	}
	ans += s;
	return;
}

void priiwi2(int t, int nokori){
	string s = "iwi";
	rep(i, t - 1){
		s += "iwi";
	}
	rep(i, nokori){
		if(i % 3 == 1) s += 'a';
		else if(i % 3 == 2) s += 'b';
		else s += 'c';
	}
	ans += s;
	return;
}

void priyzy2(int t, int nokori){
	string s = "yzy";
	rep(i, t - 1){
		s += "yzy";
	}
	rep(i, nokori){
		if(i % 3 == 1) s += 'a';
		else if(i % 3 == 2) s += 'b';
		else s += 'c';
	}
	ans += s;
	return;
}

int main(void){
	cin >> n;
	if(n == 1){
		cout << "a" << endl;
	}else if(n == 2){
		cout << "ab" << endl;
	}else if(n == 3){
		cout << "abc" << endl;
	}else if(n <= 100000000){
		// printf("kk\n");
		int len = 3;
		for (int i = 1; i <= 1000000; ++i){	
			if(i * i + len == n){
				// printf("ok\n");
				priiwi(i);
				break;
			}else if(i * i + len > n){
				// printf("ok2\n");
				priiwi2(i - 1, n - ((i - 1) * (i - 1) + len - 2));
				break;
			}
			len += 2;
		}
	}else{
		priiwi(n - 100000000);
		// printf("ok\n");
		n -= 100000000;	
		int len = 3;
		for (int i = 1; i <= 1000000; ++i){	
			if(i * i + len == n){
				priyzy(i);
				break;
			}else if(i * i + len > n){
				priyzy2(i - 1, n - ((i - 1) * (i - 1) + len - 2));
				break;
			}
			len += 2;
		}
	}
	cout << ans << endl;
	return 0;
}