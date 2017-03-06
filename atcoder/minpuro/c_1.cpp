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

int n, k;
int a[100010];
set<int> seta;
string s[100010];
bool flag[100010];
vector<string> atari, gomi;
int main(void){
	cin >> n >> k;
	rep(i, k){
		cin >> a[i];
		a[i]--;
	}
	rep(i, k) seta.insert(a[i]);
	rep(i, n) cin >> s[i];
	rep(i, n){
		if(seta.count(i)) atari.pb(s[i]);
		else gomi.pb(s[i]);
	}
	if(n == k){
		printf("\n");
		return 0;
	}
	/*
	printf("atari\n");
	for(auto u : atari){
		cout << u << endl;
	}
	printf("goi\n");
	for(auto u : gomi){
		cout << u << endl;
	}
	*/
	int mi = INF, index;
	rep(i, atari.size()){
		if(mi > atari[i].size()){
			index = i;
			mi = atari[i].size();
		}
	}
	// printf("%d %d\n", mi, index);
	string aim = atari[index];
	// cout << "aim " << aim << endl;

	rep(i, aim.size() + 1){
		string t = aim.substr(0, i);
		bool flag = true;
		for(auto u : atari){
			auto v = u.substr(0, i);
			if(t != v){
				flag = false;
				break;
			}
		}
		if(!flag) continue;
		for(auto u : gomi){
			auto v = u.substr(0, i);
			if(t == v){
				flag = false;
				break;
			}
		}
		if(!flag) continue;
		cout << t << endl;
		return 0;
	}
	printf("-1\n");
	return 0;
}