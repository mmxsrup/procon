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
int main(void){
	cin >> N;
	cin >> s;
	int c = N / 2;
	bool f = true;
	for (int i = 0; i <= N / 2; ++i) {
		int l = c - i, r = c + i;
		if(i == 0){
			if(s[l] != 'b') f = false;
		}else if(i % 3 == 1) {
			if(s[l] != 'a') f = false;
			if(s[r] != 'c') f = false;
		}else if(i % 3 == 2) {
			if(s[l] != 'c') f = false;
			if(s[r] != 'a') f = false;
		}else if(i % 3 == 0) {
			if(s[l] != 'b') f = false;
			if(s[r] != 'b') f = false;
		}
	}
	if(f) printf("%d\n", N / 2);
	else printf("-1\n");
	return 0;
}