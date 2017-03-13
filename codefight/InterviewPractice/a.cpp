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


int ans = INF;
void dfs(string now, string goal, string pre, int cnt, vector<string> wordlist){
	if(now == goal){
		chmin(ans, cnt);
		return;
	}
	if(cnt >= wordlist.size()) return;
	for(auto nex : wordlist){
		if(nex == pre) continue;
		int c = 0;
		rep(i, nex.size()) if(nex[i] != now[i])c++;
		if(c != 1) continue;
		dfs(nex, goal, now, cnt + 1, wordlist);
	}
	return;
}

int wordLadder(std::string beginWord, std::string endWord, std::vector<std::string> wordList) {
	bool f = false;
	for(auto u : wordList) if(u == endWord){
		f = true;
	}
	if(!f) return 0;

	dfs(beginWord, endWord, "-1", 0, wordList);
	if(ans == INF) return 0;
	else return ans + 1;
}

int main(void){
	auto d = wordLadder("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"});
	printf("%d\n", d);
	return 0;
}