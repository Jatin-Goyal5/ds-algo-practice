#include <iostream>
using namespace std;

int main(){
   int p = 10;
   int const *q = &p + 5;
   p++;
   cout << p << endl;
   return 0;
}
