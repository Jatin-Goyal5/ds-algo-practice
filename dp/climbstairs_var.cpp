#include<bits/stdc++.h>
#define f(i,a,b) for(int i =a ; i < b ; i++)
using namespace std;
typedef vector<int> vi;

void climb_var(vi a){
    int n = a.size();
    vi dp(n+1);
    dp[n] = 1;
    for(int i= n-1 ; i >= 0 ; i-- ){
        for(int j = 1 ; j <= a[i]; j++){
            if(i+j < n+1){
                dp[i] += dp[i+j];
            }
        }
    }
    cout<< dp[0];
    
}
int main(int argc ,char **argv){
    int n;
    cin>> n;
    vi a(n);
    f(i,0,n)
        cin>> a[i];
    climb_var(a);
    return 0;

    
    
   
}