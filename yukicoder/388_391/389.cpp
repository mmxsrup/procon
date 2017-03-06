#include <iostream>
#include <algorithm>
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
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int m; cin >> m;
	string s;
	getchar();
	getline(cin, s);
	// cout << s <<endl;
	int sum = 0, cnt = 0;
	rep(i, 1000){
		if(s[i] == '\0') break;
		if('0' <= s[i] && s[i] <= '9'){
			cnt++;
			sum += s[i] - '0';
			if(s[i] == '0'){
				printf("%c ee\n", s[i]);
				printf("1\n");
				return 0;
			}
		}
	}
	printf("cnt %d sum%d\n", cnt, sum);
	int bunnsi = 1;
	int bunnsitmp = cnt + 1;
	while(bunnsitmp > 0){
		bunnsi *= bunnsitmp;
		bunnsitmp--;
	}
	// printf("bunnsi%d\n", bunnsi);
	int bunnbo = 1;
	int bunnbotmp = m - sum;
	while(bunnbotmp > 0){
		bunnbo *= bunnbotmp;
		bunnbotmp--;
	}
	// printf("bunnbo %d\n", bunnbo);
	printf("%d\n", bunnsi / bunnbo);
	return 0;
}