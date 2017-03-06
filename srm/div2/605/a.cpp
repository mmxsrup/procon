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

class AlienAndPassword{
public:
	int getNumber(string S){
		set<string> se;
		rep(i, S.size()){
			string d = "";
			rep(j, S.size()){
				if(j == i) continue;
				d += S[j];
			}
			se.insert(d);
		}
		return (int)(se.size());
	}
};

int main(void){
	AlienAndPassword ap;
	printf("%d\n", ap.getNumber("ABA"));
	return 0;
}