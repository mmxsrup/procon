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

int main(void) {
	int n; cin >> n;  cin.ignore();
	rep(i, n) {
		string s;
		getline(cin, s);
		int index = 0;
		bool ok = false;

		int start = -1, end = -1;
		REP(i, s.size()) if('0' <= s[i] && s[i] <= '9'){
			start = i; break;
		}
		REP(i, start) if(!('0' <= s[i] && s[i] <= '9')){
			// printf("end i %d\n", i);
			end = i + 1; break;
		}
		if(end == -1) end = 0;
		swap(start, end);
		// cout << start << " " << end << endl;

		if(start == -1 && end == -1){
			cout << s << endl;
			break;
		}

		string num = s.substr(start, end - start + 1);
		// cout << "num " << num << endl;
		bool f = false;
		REP(i, num.size()) {
			if(num[i] < '9'){
				// printf("i %d\n", i);
				num[i] = num[i] + 1;
				break;
			}else{
				// printf("j %d\n", i);
				if(i == 0) f = true;
				num[i] = '0';
			}
		}
		if(f)num = '1' + num;
		cout << s.substr(0, start) + num + s.substr(end + 1) << endl;
	}
	return 0;
}