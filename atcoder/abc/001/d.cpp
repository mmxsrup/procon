#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;
#define mp make_pairt
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int main(void){
	bool time[2000] //分刻み
	int n; cin >> n;
	rep(i, n){
		string s; cin >> s;
		int befor = (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0') * 1;
		int aftere = (s[5] - '0') * 600 + (s[6] - '0') * 60 + (s[8] - '0') * 10 + (s[9] - '0') * 1;

		int amari_before = before % 5;
		int amari_after = after % 5;
		if(amari_before % 5 != 0) before -= amari_before;
		if(amari_after % 5 != 0) after += 5 - amari_after;

		reps(i, amari_before, amari_after + 1){
			if(time[i] == false) time[i] = true;
		}
	}

}