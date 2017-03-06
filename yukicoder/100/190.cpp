#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
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

int memo1[100010], memo2[100010];
int main(void){
	int n; cin >> n;
	rep(i, 100010) memo1[i] = memo2[i] = 0;
	vector<int> a, b;
	rep(i, 2 * n){
		int t; cin >> t;
		if(t >= 0){
			// printf("t %d\n", t);
			a.pb(t);
			memo1[t]++;
		}else{
			// printf("t %d\n", t);
			t *= -1;
			b.pb(t);
			memo2[t]++;
		}
	}

	sort(all(a)); sort(all(b));

	int moist = 0;
	rep(i, 100010){
		if(memo1[i]> 0 && memo2[i] > 0){
			moist += min(memo1[i], memo2[i]);
		}
	}
	moist += memo1[0] / 2;

	int wet = 0;
	int l = 0, r = 0;
	int usedzero = 0;
	while(r < a.size() && l < b.size()){
		while(a[r] - b[l] < 1)r++;
		if(l >= b.size()) break;
		if(r >= a.size()) break;
		wet++;
		if(a[r] == 0) usedzero++;
		l++;
		r++;
	}
	int notzero = a.size() - wet - memo1[0];
	if(notzero >= memo1[0]) wet += (notzero + memo1[0]) / 2;
	else wet += notzero;

	int dry = 0;
	l = 0, r = 0;
	while(r < b.size() && l < a.size()){
		while(b[r] - a[l] < 1)r++;
		if(l >= a.size()) break;
		if(r >= b.size()) break;
		dry++;
		l++;
		r++;
	}
	dry += (b.size() - dry) / 2;
	
	printf("%d %d %d\n", dry, wet, moist);
	return 0;
}