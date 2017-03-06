#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

bool e[10], l[10];
int b;
int main(void){
	rep(i, 10) e[i] = l[i] = false;
	rep(i, 6){
		int t; cin >> t;
		e[t] = true;
	}
	cin >> b;
	rep(i, 6){
		int t; cin >> t;
		l[t] = true;
	}

	int cnt = 0;
	vector<int> miss;
	rep(i, 10){
		if(e[i] && l[i]) cnt++;
		else miss.push_back(i);
	}

	if(cnt == 6){
		printf("1\n");
	}else if(cnt == 5){
		if(miss[0] == b) printf("2\n");
		else printf("3\n");
	}else if(cnt == 4){
		printf("4\n");
	}else if(cnt == 3){
		printf("5\n");
	}else{
		printf("0\n");
	}
	return 0;
}