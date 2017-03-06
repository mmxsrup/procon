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

int sum(int r){
	r = abs(r);
	return r * (1 + r) / 2;
}

int main(void){
	int r, g, b; cin >> r >> g >> b;
	int ans = INF;
	for (int i = -300; i <= 300; ++i){
		int lg = i, rg = i + g - 1;
		int rr = lg + 1;
		int lr = rr + r - 1;
		int bl = rg + 1;
		int br = bl + b - 1;
	}
}