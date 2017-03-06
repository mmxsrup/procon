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

int main(void){
	int n; cin >> n;
	vint v;
	rep(i, n){
		int c; cin >> c;
		v.pb(c);
	}
	sort(all(v));
	int p = 0;
	int sum = 0;
	do{
		vint flag(n, 0);
		rep(i, n - 1){
			reps(j, i + 1, n){
				if(v[j] % v[i] == 0){
					if(flag[j] == 0) flag[j] = 1;
					else flag[j] = 0;
				}
			}
		}
		rep(i, n){
			if(flag[i] == 0) sum++;
		}
		p++;
	}while(next_permutation(all(v)));
	printf("%.9f\n", (double)sum / p);
	return 0;
}