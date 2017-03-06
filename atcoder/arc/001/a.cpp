#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n; cin >> n;
	string s; cin >> s;
	int cnt[5];
	rep(i, 5) cnt[i] = 0;
	rep(i, n){
		cnt[s[i] - '0']++;
	}
	printf("%d ", max(cnt[1], max(cnt[2], max(cnt[3], cnt[4]))));
	printf("%d\n", min(cnt[1], min(cnt[2], min(cnt[3], cnt[4]))));
	return 0;
}