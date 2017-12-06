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
const ll INFF = 1e18

unsigned int randxor() {
    static unsigned int x=123456789,y=362436069,z=521288629,w=88675123;
    unsigned int t;
    t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );
}

int calcscore(int N, int M, const auto& v, const auto& item1, const auto& item2, const auto& score) {
	map<int, int> num2idx;
	rep(i, N) num2idx[v[i]] = i;
	int sumScore = 0;
	rep(i, M) if(num2idx[item1[i]]< num2idx[item2[i]]) sumScore += score[i];
	return sumScore;
}

vector<int> solve(int N, int M, const auto& item1, const auto& item2, const auto& score) {
	vector<int> ans;
	int maxScore = 0;
	const int MAX_T = 100000;
	vector<int> now(N);
	rep(i, N) now[i] = i;

	rep(i, MAX_T) {
		int idx1 = 0, idx2 = 0;
		while(idx1 == idx2) {
			idx1 = randxor() % N, idx2 = randxor() % N;
		}
		vector<int> next = now;
		swap(now[idx1], now[idx2]);
		auto nowScore  = calcscore(now);
		auto nextScore = calcscore(next);
		if (nextscore < nowScore) {
			maxScore = nextscore;
			ans = next;
		} else {
			int P = randxor() % 100;
			
		}
	}
}

int main(void) {
	int N, M; cin >> N >> M;
	vector<int> item1(M), item2(M), score(M);
	rep(i, M) cin >> item1[i] >> item2[i] >> score[i];

	return 0;
}