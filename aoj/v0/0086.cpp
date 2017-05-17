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
#define rall(v) (v).rbegin(), (v).rend()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define OUT(x) cout << #x << " = " << x << endl; 
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int deg[110];

void init(void){
	rep(i, 110) deg[i] = 0;
}

int main(void){
	int a, b;
	while(cin >> a >> b){
		if(a == 0 && b == 0){
			bool flag = true;
			reps(i, 3, 110){
				if(deg[i] % 2) flag = false;
			}
			if(deg[1] % 2 == 0) flag = false;
			if(deg[2] % 2 == 0) flag = false;
			if(flag) printf("OK\n");
			else printf("NG\n");
			init();
		}else{
			deg[a]++, deg[b]++;
		}
	}
	return 0;
}