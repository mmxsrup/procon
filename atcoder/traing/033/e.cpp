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


int n, k;
string s;

bool chc(string& a, string& b) {
	int cnta[26], cntb[26];
	rep(i, 26) cnta[i] = cntb[i] = 0;
	// cout << a << " " << b << endl;
	for(auto u : a) cnta[u - 'a']++;
	for(auto u : b) cntb[u - 'a']++;
	/*
	rep(i, 26) printf("%2d ", cnta[i]);
	printf("\n");
	rep(i, 26) printf("%2d ", cntb[i]);
	printf("\n");
	*/

	bool f = true;
	rep(i, 26) if(cnta[i] != cntb[i]) f = false;
	
	return f;
}

int main(void) {
	cin >> n >> k;
	cin >> s;
	bool flag = false;

	rep(i, s.size() - k + 1) {
		int l = i, r = i + k;
		string a = s.substr(l, k);
		reps(j, r, s.size() - k + 1) {
			string b = s.substr(j, k);
			// cout << a <<  " " << b << endl;
			if(chc(a, b)) {
				flag = true;
				break;
			}
		}
		if(flag) break;
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
}