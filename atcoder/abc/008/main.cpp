#include <iostream>
#include <iomanip>
using namespace std;

int main(void){
	int i, j;
	int n;
	cout << "数値=";
	cin >> n;
	if(n < 2 || 30 < n) return 0;

	for (i = 1; i <= n; ++i){
		for (j = 1; j <= n; ++j){
			cout << setw(4) << i * j;
		}
		cout << '\n';
	}
	return 0;
}