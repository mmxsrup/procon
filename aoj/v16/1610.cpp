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

int m, n;
int dat[7400000];

int main(void){
	while(1){
		scanf("%d %d", &m, &n);
		if(m == 0 && n == 0) return 0;
		rep(i, 7400000) dat[i] = 0;

		int cnt = 0;
		int d = m;
		while(cnt < n){
			if(dat[d] != 0){
				d++;
				continue;
			}
			for (int j = d; j <= 7400000; j += d){
				dat[j] = 1;
			}
			cnt++;
			d++;
		}

		reps(i, m, 7400000){
			if(dat[i] == 0){
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}