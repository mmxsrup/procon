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
const ll INFF = 1e18;

int n, l;
int x[100010];
char d[100010];

int main(void){
	cin >> n >> l;
	reps(i, 1, n + 1){
		cin >> x[i] >> d[i];
	}
	//番兵
	x[0] = 1; x[n + 1] = l;
	d[0] = 'S', x[n + 1] = 'F';
	
	set<pair<int, int> > se;
	int l = 0, r = 0;
	while(r < n){
		while(d[r] == 'L') r++;
		se.insert()
	}
	return 0;
}