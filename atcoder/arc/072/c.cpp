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

int n;
ll a[100010];
int main(void){
	cin >> n;
	rep(i, n) cin >> a[i];

	ll sum = 0;
	ll cnt = 0;
	rep(i, n){
		sum += a[i];
		if(i % 2){ //+
			if(sum ==  0){
				sum++;
				cnt++;
			}else if(sum < 0){
				ll d = abs(sum) + 1;
				sum = 1;
				cnt += d;
			}
		}else{ //-
			if(sum == 0){
				sum--;
				cnt++;
			}else if(sum > 0){
				ll d = sum + 1;
				sum = -1;
				cnt += d;
			}
		}
	}

	ll bsum = 0;
	ll bcnt = 0;
	rep(i, n){
		bsum += a[i];
		if(i % 2 == 0){ //+
			if(bsum ==  0){
				bsum++;
				bcnt++;
			}else if(bsum < 0){
				ll d = abs(bsum) + 1;
				bsum = 1;
				bcnt += d;
			}
		}else{ //-
			if(bsum == 0){
				bsum--;
				bcnt++;
			}else if(bsum > 0){
				ll d = bsum + 1;
				bsum = -1;
				bcnt += d;
			}
		}
	}
	printf("%lld\n", min(cnt, bcnt));

	return 0;
}