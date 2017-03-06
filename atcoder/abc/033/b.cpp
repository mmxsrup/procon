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

int n;
string s[1010];
int p[1010];
int main(void){
	cin >> n;
	ll sum = 0;
	ll dai = 0;
	int index;
	rep(i, n){
		cin >> s[i] >> p[i];
		sum += p[i];
		if(dai < p[i]){
			dai = p[i];
			index = i;
		}
	}
	if(dai > sum / 2.0){
		cout << s[index] << endl;
	}else{
		cout << "atcoder" << endl;
	}
	return 0;
}