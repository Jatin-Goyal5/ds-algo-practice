// 1. You are given a number n and a number k in separate lines, representing 
//     the number of fences and number of colors.
// 2. You are required to calculate and print the number of ways in which the 
// fences could be painted so that not more than two fences have same colors.

#include<bits/stdc++.h>
using namespace std;

void ways(int n , int k ){
    int ls = k;
    int ld = k*(k-1);
    for(int i =3 ; i <= n ; i++){
        int nls = ld;
        int nld = (ls+ld)*(k-1);
        ls = nls;
        ld = nld;
    }
    
    cout<< ls+ld;
} 

int main(){
    int n,k;
    cin>>n>> k;
     ways(n,k);
    return 0;
}