#include<bits/stdc++.h>
using namespace std;

void fiboncci(int n){
    int a =1, b = 1, c=0;
    ///c= a+b; 0 1 1 2 3 5 8
    for(int i = 1 ; i < n ; i++){
       c=a+b;
       a=b;
       b=c; 
    }
    cout<< c;
}
int main(int argc ,char **argv){
    int n;
    cin>> n;
    fiboncci(n);


    return 0;
}