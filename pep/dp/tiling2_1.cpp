// 1. You are given a number n representing the length of a floor space which is 2m wide. It's a 2 * n board.
// 2. You've an infinite supply of 2 * 1 tiles.
// 3. You are required to calculate and print the number of ways floor can be tiled using tiles.

#include<bits/stdc++.h>
using namespace std;
int tiling(int n){
    int a=1;
    int b =2;
    for(int i =3 ; i < n ; i++){
        int c = a+b;
        a=b;
        b=c;
        
    }
    return a+b;
}
int main(){
    int n;
    cin>> n;
    cout<< tiling(n);
    return 0;
}