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

int N, K;
char s[10010];
int main(void){
	scanf("%d %d", &N, &K);
	scanf("%s", s);
	/*
	for (int i = 0; i < N; ++i){
		int cnt = 0;
		int l = min(i, K - 1);
		int r = max(i, K - 1);
		// printf("%d %d\n", l, r);
		if(l == r) continue;
		if(s[l] == '(' && s[r] == ')'){
			for (int j = l; j <= r; ++j){
				if(s[j] == '(')cnt++;
				else cnt--;
			}
			if(cnt == 0){
				printf("%d\n", i + 1);
				break;
			}
		}
	}
	*/
	if(s[K - 1] == '('){
		int cnt = 0;
		reps(i, K - 1, N){
			if(s[i] == '(') cnt++;
			else cnt--;
			if(cnt == 0){
				printf("%d\n", i + 1);
				return 0;
			}
		}
	}else{
		int cnt = 0;
		for (int i = K - 1; i >= 0 ; --i)
		{
			if(s[i] == '(') cnt++;
			else cnt--;
			if(cnt == 0){
				printf("%d\n", i + 1);
				return 0;
			}
		}
	}
	return 0;
}
