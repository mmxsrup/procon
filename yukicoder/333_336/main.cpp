#include <iostream>
using namespace std;

int main(void){
	int input1, input2;
	cin >> input1 >> input2;

	if (input2 < input1)
		cout << "input1 is max\n";
	if(input1 < input2)
		cout << "input2 is max\n";
	if(input1 == input2)
		cout << "same\n";

	return 0;
}