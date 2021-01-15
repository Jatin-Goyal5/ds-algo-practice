#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,n1 ,n2;
    cin>> a >> b;
    int gcd =1;
    n1 =a ;
    n2= b;
    while (n1%n2 != 0)
    {
        int r = n1%n2;
        n1 =n2;
        n2 = r;

    }
    gcd = n2;
    
    // for(int i = min(n1,n2) ; i>= 2 ; i--){
    //     if(n1%i == 0 && n2%i ==0 ){
    //         gcd =i;
    //         break;
    //     }     
    // }
     cout<< "gcd " <<gcd;
     cout<< "LCM " << (a*b)/gcd;
    return 0;
}