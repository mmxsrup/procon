#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int namea[30];
int nameA[30];
int kita[30];
int kitA[30];

int main(void){
	rep(i, 30) namea[i] = nameA[i] = kita[i] = kitA[i] = 0;

	int n, m; cin >> n >> m;
	string s, kit; cin >> s >> kit;
	rep(i, s.size()){
		if('a' <= s[i] && s[i] <= 'z'){
			namea[s[i] - 'a']++;
		}else{
			nameA[s[i] - 'A']++;
		}	
	}

	int ans = 0;
	while(1){
		ans++;
		rep(i, kit.size()){
			if('a' <= kit[i] && kit[i] <= 'z'){
				kita[kit[i] - 'a']++;
			}else{
				kitA[kit[i] - 'A']++;
			}
		}
		//すべて揃ったかチェック
		rep(i, 26){
			if(namea[i] > kita[i]) break;
			if(nameA[i] > kitA[i]) break;
			if(i == 25){
				printf("%d\n", ans);
				return 0;
			}
		}
		rep(i, 26){
			if(namea[i] > 0 && kita[i] == 0){
				printf("-1\n"); return 0;
			}
			if(nameA[i] > 0 && kitA[i] == 0){
				printf("-1\n"); return 0;
			}
		}
	}

}