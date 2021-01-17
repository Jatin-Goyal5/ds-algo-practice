#include<bits/stdc++.h>
#define f(i,a,b) for(int i =a ; i < b ; i++)
#define fr(i,a,b) for(int i = a; i>=b ; i--)
using namespace std;
typedef vector<int> vi;
int power(int n , int p){
    if(p == 0){
        return 1;
    }
    int k = power(n,p/2);
    if(p%2 == 0){
        return k*k;
    }else
    {
        return k*k*n;
    }
    
    
}
int main(){
    int n,p;
    cin>> n>> p;
    cout<< power(n,p);
    return 0;
}