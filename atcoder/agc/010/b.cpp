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

ll a[100010];
int main(void){
	int n; cin >> n;
	ll sum = 0;
	rep(i, n){
		cin >> a[i];
		sum += a[i];
	}
	int index = 0;
	ll mi = INF + 10;
	rep(i, n){
		if(mi > a[i]){
			index = i; mi = a[i];
		}
	}
	while(1){
		int k = index;
		mi = INF;
		// printf("mi %d k %d\n", mi, k);
		rep(i, n){
			a[k % n] -= i + 1;
			if(mi > a[k % n]){
				index = k % n; mi = a[k % n];
			}
			k++;
		}
		if(mi < 0){
			printf("NO\n");
			return 0;
		}
		sum -= n * (n + 1) / 2;
		if(sum == 0){
			break;
		}
	}
	printf("YES\n");
	return 0;
}