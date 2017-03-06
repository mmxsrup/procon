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
int dist;
int main(void){
	cin >> n;
	int nokori = n;
	int left = 0;
	int right = 0;
	int sum = 0;
	while(1){
		int ret;
		int cnt = 0;
		while(pow(2, cnt) <= nokori) cnt++;
		cnt--;
		right += pow(2, cnt);
		cout << "?" << " " << left << " " << right << endl;
		cin >> ret;
		sum += ret;
		left = right;
		nokori -= pow(2, cnt);
		if(nokori == 0) break;
	}
	cout << "!" << " " << sum << endl;
	return 0;
}