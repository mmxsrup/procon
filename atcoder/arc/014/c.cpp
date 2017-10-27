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
string s;

int main(void) {
	cin >> N >> s;

	/* 3色しかないので, うまくいれることで, それぞれ偶数個のものは全て消せる */
	int r = 0, g = 0, b = 0;
	for(auto c : s) {
		if(c == 'R') r++;
		else if(c == 'G') g++;
		else if(c == 'B') b++;
	}
	printf("%d\n", r % 2 + g % 2 + b % 2);
	return 0;
}