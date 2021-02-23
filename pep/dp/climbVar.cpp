#include<bits/stdc++.h>
#define f(i,a,b) for(int i =a ; i < b ; i++)
using namespace std;
typedef vector<int> vi;
void climb_varmin(vi a){
    int n = a.size();
    vi dp(n+1,0);
    dp[n] = 1;
    //cout<< dp[n];
    for(int i= n-1 ; i >= 0 ; i-- ){
        //cout<<endl <<a[i]<<"--> ";
        int c=0;
        for(int j = 1 ; j <= a[i]; j++){
            if(i+j <= n && dp[i+j] > 0){
               dp[i] += dp[i+j];
            }
        }
        
        //cout<< minan;
        // dp[i] = minan == INT_MAX? 0 :minan;
    //     cout<< dp[i];
    //    //dp[i] = ans ==INT_MAX?0:ans+1;
    }

    cout<< dp[0];
    
}

int main(){
    int n;
    cin>> n;
    vi a(n);
    for(int i =0 ; i< n ; i++){
        cin>>a[i];
    }
    climb_varmin(a);
}