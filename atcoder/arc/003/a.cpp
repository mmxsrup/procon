#include <iostream>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	double n; cin >> n;
	string s; cin >> s;
	double sum = 0;
	rep(i, n){
		if(s[i] == 'A') sum += 4.0;
		else if(s[i] == 'B') sum += 3.0;
		else if(s[i] == 'C') sum += 2.0;
		else if(s[i] == 'D') sum += 1.0;
	}

	printf("%.11f\n", sum / n);
	return 0;
}