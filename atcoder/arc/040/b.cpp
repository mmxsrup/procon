#include <bits/stdc++.h>
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

int n, r;
string s;
int main(void){
	cin >> n >> r;
	cin >> s;
	// s += "oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo";
	int d = 0;
	rep(i, s.size()){
		if(s[i] == '.')d++;
	}
	int ans = 0;
	for (int i = 0; i < s.size(); ++i){
		cout << s << endl;
		int now = 0;
		for (int j = i; j < i + r; ++j){
			if(s[j] == '.') now++;
		}
		printf("%d %d d :%d\n", i, now, d);
		//もうない
		if(d == 0){
			printf("%d\n", ans);
			return 0;
		}else{
			//一歩進んだ分
			if(i != 0) ans++;
		}

		//塗る
		ans++;
		if(s[i] == '.' || d == now){
			for (int j = i; j < r; ++j){
				if(s[j] == '.'){
					d--;
					s[j] = 'o';
				}
			}
		}
	}
}