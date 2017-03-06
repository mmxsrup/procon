#include <iostream>
#include <vector>
#include <cstdio>
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

int n;
ll s;
ll p[40];
vector<pair<ll, int> > bit1, bit2;

int main(void){
	cin >> n >> s;
	rep(i, n) cin >> p[i];

	int mid1, mid2;
	mid1 = n / 2 + n % 2;
	mid2 = n / 2;

	for (int mask = 0; mask < (1 << mid1); ++mask){
		ll sum = 0;
		for (int pos = 0; pos < mid1; ++pos){
			if((mask & (1 << pos))){
				sum += p[pos];
			}
		}
		// printf("%d %lld\n", mask, sum);
		bit1.pb(mp(sum, mask));
	}
	for (int mask = 0; mask < (1 << mid2); ++mask){
		ll sum = 0;
		for (int pos = 0; pos < mid2; ++pos){
			if((mask & (1 << pos))){
				sum += p[mid1 + pos];
			}
		}
		// printf("%d %lld\n", mask, sum);
		bit2.pb(mp(sum, mask));
	}

	sort(all(bit2));
	
	vector<pair<ll, ll> > ans;
	for (int i = 0; i < bit1.size(); ++i){//bit1のペアをbit2から探す
		auto itr = lower_bound(all(bit2), mp(s - bit1[i].fi , -1));
		for (auto it = itr; it < bit2.end(); ++it){
			if(it->fi + bit1[i].fi == s){
				ans.pb(mp(bit1[i].se, it->se));
			}else if(it->fi + bit1[i].fi > s){
				break;
			}
		}
	}

	vector<vector<int> > memo;
	for(auto u : ans){
		int mask1 = u.fi, mask2 = u.se;
		vector<int> tmp;
		for (int pos = 0; pos < mid1; ++pos){
			if(mask1 & (1 << pos)){
				tmp.pb(1);
			}else{
				tmp.pb(0);
			}
		}
		for (int pos = 0; pos < mid2; ++pos){
			if(mask2 & (1 << pos)){
				tmp.pb(1);
			}else{
				tmp.pb(0);
			}
		}
		memo.pb(tmp);
	}
	sort(all(memo));
	reverse(all(memo));
	for(auto u : memo){
		for (int i = 0; i < n; ++i){
			if(u[i]){
				printf("%d ", i + 1);
			}
		}
		printf("\n");
	}
	return 0;
}