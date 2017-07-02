#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=n-1;i>=(0);i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int N;
string s[110];
map<char, int> ma; 
int main(void){
	ma['I'] = 1, ma['V'] = 5, ma['X'] = 10, ma['L'] = 50, ma['C'] = 100, ma['D'] = 500, ma['M'] = 1000;
	cin >> N;
	rep(i, N) cin >> s[i];
	int ans = 0;
	rep(i, N){
		rep(j, s[i].size() - 1){
			auto d1 = ma[s[i][j]], d2 = ma[s[i][j + 1]];
			if(d1 >= d2) ans += d1;
			else ans -= d1;
		}
		ans += ma[s[i].back()];
	}
	if(ans >= 4000){
		printf("ERROR\n");
		return 0;
	}
	string ret;
	while(ans > 0){
		if(ans >= 1000){
			rep(i, ans / 1000) ret += 'M';
			ans %= 1000;
		}else if(ans >= 900){
			ret += "CM";
			ans -= 900;
		}else if(ans >= 500){
			ret += 'D';
			ans -= 500;
		}else if(ans >= 400){
			ret += "CD";
			ans -= 400;
		}else if(ans >= 100){
			rep(i, ans / 100) ret += 'C';
			ans %= 100;
		}else if(ans >= 90){
			ret += "XC";
			ans -= 90;
		}else if(ans >= 50){
			ret += 'L';
			ans -= 50
		}else if(ans >= 40){
			ret += "XL";
			ans -= 40;
		}else if(ans >= 10){
			rep(i, ans / 10) ret += 'X';
			ans %= 10;
		}else if(ans >= 9){
			ret += "IX";
			ans -= 9;
		}else if(ans >= 5){
			ret += 'V';
			ans -= 5;
		}else if(ans >= 4){
			ret += "IV";
			ans -= 4;
		}else if(ans >= 1){
			rep(i, ans) ret += 'I';
			ans = 0;
		}
	}
	cout << ret << endl;
	return 0;
}