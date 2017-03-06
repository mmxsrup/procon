#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int main(void){
	string s; cin >> s;
	rep(l, s.size()){
		reps(r, l + 1, s.size()){
			vector<int> v(30);
			rep(i, 30) v[i] = 0;
			reps(i, l, r + 1){
				v[s[i] - 'a']++;
			}
			sort(v.begin(), v.end());
			if(v[v.size() - 1] > (r - l + 1) / 2){
				printf("%d %d\n", l + 1 ,r + 1);
				return 0;
			}
		}
	}
	printf("-1 -1\n");
	return 0;
}