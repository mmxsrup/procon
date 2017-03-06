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

int n, q;

 	
 	vdector<int> imos_one(vector<int> baseimos){
    int basesize = baseimos.size();
    vector<int> imos(basesize, 0); 
    imos[0] = baseimos[0];
    for(int i = 1; i < basesize; ++i){
        imos[i] = imos[i - 1] + baseimos[i];
    }
    return imos;
}

int main(void){
	cin >> n >> q;
	vector<int> v(n + 1, 0);
	rep(i, q){
		int l, r; cin >> l >> r;
		l--, r--;
		v[l]++;
		v[r + 1]--;
	}
	auto ret = imos_one(v);
	string s  = "";
	rep(i, n){
		if(ret[i] % 2 == 0) s += '0';
		else s += '1';
	}
	cout << s << endl;
	return 0;
}