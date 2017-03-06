#include <bits/stdc++.h>
using namespace std;
  
using namespace std;
int main() {  
  
   int a = 20004;  
  
   // high 7 and 8 bits  
   int mask = 1 << 8 | 1 << 7;  
   cout << bitset<16>(a) << endl;  
   cout << bitset<16>(a | mask) << endl << endl;  
  
   // low 9 and 10 bits  
   mask = 1 << 9 | 1 << 10;  
   cout << bitset<16>(a) << endl;  
   cout << bitset<16>(a & ~mask) << endl << endl;  
  
   // flip 0 and 1 bits  
   mask = 1 << 0 | 1 << 1;  
   cout << bitset<16>(a) << endl;  
   cout << bitset<16>(a ^ mask) << endl << endl;  
  
   // the leaset significant non-zero bit  
   cout << bitset<16>(a) << endl;  
   cout << bitset<16>(-a) << endl;  
   cout << bitset<16>(a&-a) << endl;  
  
   return 0;  
}  