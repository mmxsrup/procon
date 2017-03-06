#include <iostream>
#include <string>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

string b[10];
int main(void){
	int x, y; string w;
	cin >> x >> y >> w;
	x--; y--;
	rep(i, 9) cin >> b[i];
	int dx, dy;
	if(w == "R"){
		dx = 1; dy = 0;
	}else if(w == "L"){
		dx = -1; dy = 0;
	}else if(w == "U"){
		dx = 0; dy = -1;
	}else if(w == "D"){
		dx = 0; dy = 1;
	}else if(w == "RU"){
		dx = 1; dy = -1;
	}else if(w == "RD"){
		dx = 1; dy = 1;
	}else if(w == "LU"){
		dx = -1; dy = -1;
	}else if(w == "LD"){
		dx = -1; dy = 1;
	}

	cout << b[y][x];
	rep(i, 3){
		int tmpx = x, tmpy = y;
		tmpx += dx; tmpy += dy;
		if(!(0 <= tmpx && tmpx < 9)) dx *= -1;
		if(!(0 <= tmpy && tmpy < 9)) dy *= -1;
		x += dx; y += dy;
		cout << b[y][x];
	}
	printf("\n");
	return 0;
}