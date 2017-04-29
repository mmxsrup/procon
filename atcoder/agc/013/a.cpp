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
ll b[100010];
int main(void){
	cin >> n;
	rep(i, n) cin >> a[i];
	
	//rep(i, n - 1) b[i] = a[i + 1] - a[i];
	/*
	int cnt = 0;
	rep(i, n - 1){
		if((b[i] > 0 && b[i + 1] < 0) || (b[i] < 0 && b[i + 1] > 0)){
			cnt++;
			i++;
		}else if(i >= 1){
			if((a[i - 1] < 0 && a[i] == 0 && a[i + 1] > 0) || 
				(a[i - 1] > 0 && a[i] == 0 && a[i + 1] < 0)){
				cnt++;
				i++;
			}
		}
	}
	*/
	
	int cnt = 0;
	bool zou = true, gen = true;
	if(a[n -  2] <= a[n - 1]) a[n] = INFF;
	else a[n] = -1;
	rep(i, n){
		if(zou && gen){
			// printf("1\n");
			if(a[i] < a[i + 1]) gen = false;
			else if(a[i] > a[i + 1]) zou = false;
		}else if(zou){
			// printf("2\n");
			if(a[i] > a[i + 1]){
				cnt++;
				// printf("%d\n", i);
				zou = gen = true;
			}else{
				zou = true;
			}
		}else if(gen){
			// printf("3\n");
			if(a[i] < a[i + 1]){
				cnt++;
				// printf("cnt");
				zou = gen = true;
			}else{
				gen = true;
			}
		}
	}

	/*
	int cnt1 = 0;
	for (int i = n - 1; i >= 0 ; --i){
		if(zou && gen){
			if(a[i] < a[i + 1]) gen = false;
			else if(a[i] > a[i + 1]) zou = false;
		}else if(zou){
			if(a[i] > a[i + 1]){
				cnt++;
				// printf("%d\n", i);
				zou = gen = true;
			}
		}else if(gen){
			if(a[i] < a[i + 1]){
				cnt++;
				// printf("%d\n", if);
				zou = gen = true;
			}
		}
	}
	*/
	printf("%d\n", cnt + 1);
	return 0;
}