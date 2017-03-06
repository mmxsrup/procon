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

//yuki
//abcdefghijklmnopqrstuvwxyz
int z = 0, y = 0, y_u = 0, u = 0, u_k = 0, k = 0, k_i = 0, i = 0, i_a = 0;
int main(void){
	int n; cin >> n;
	string s; cin >> s;
	for(auto t : s){
		if(t == 'z') z++;
		else if(t == 'y') y++;
		else if('u' < t && t < 'y') y_u++;
		else if(t == 'u') u++;
		else if('k' < t & t < 'u') u_k++;
		else if(t == 'k') k++;
		else if('i' < t && t < 'k') k_i++;
		else if(t == 'i') i++;
		else i_a++;
	}
	// printf("%d %d %d %d %d %d %d %d %d\n", z, y, y_u, u, u_k, k, k_i, i, i_a);
	int ans = 0;
	while(1){
		if(z > 0) z--, ans++;
		else if(y > 0 && u > 0 && k > 0 && i > 0 && i_a > 0) y--, u--, k--, i--, i_a--, ans++; //yuki + i_a
		else if(y > 0 && u > 0 && k > 0 && i > 1) y--, u--, k--, i -= 2, ans++; //yukii
		else if(y > 0 && u > 0 && k > 0 && k_i > 0) y--, u--, k--, k_i--, ans++; //yuk + k_i
		else if(y > 0 && u > 0 && k > 1) y--, u--, k -= 2, ans++; //yukk
		else if(y > 0 && u > 0 && u_k > 0) y--, u--, u_k--, ans++; //yu + u_k
		else if(y > 0 && u > 1) y--, u -= 2, ans++; //yuu
		else if(y > 0 && y_u > 0) y--, y_u--, ans++; //y + y_u
		else if(y > 1) y -= 2, ans++;
		else break;
	}
	printf("%d\n", ans);
	return 0;
}