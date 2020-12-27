#include<bits/stdc++.h>
#define f(i,a,b) for(int i =a ; i < b ; i++)
#define fr(i,a,b) for(int i = a; i>=b ; i--)
using namespace std;
typedef vector<vector<int>> vi;

void goldmine(vi a){
    vi dp(a.size(),vector<int>(a[0].size()));
    f(i,0,a.size())
        dp[i][a[0].size()-1] = a[i][a[0].size()-1];
    fr(i,a[0].size()-2,0){
        fr(j,a.size()-1,0){
            if(j == 0)
                dp[j][i] = max(dp[j][i+1],dp[j+1][i+1])+a[j][i];
            else if(j == a.size()-1)
                dp[j][i] = max(dp[j-1][i+1],dp[j][i+1])+a[j][i];
            else
                dp[j][i] = max(dp[j-1][i+1],max(dp[j][i+1],dp[j+1][i+1]))+a[j][i];
                
            
        }
    }
    int ans = INT_MIN;
    f(i,0,a.size())
        ans =max(ans,dp[i][0]) ;
    cout<< ans;
    
    

}

void minmaze(vi a){
    vi dp(a.size(),vector<int>(a[0].size()));
    dp[a.size()-1][a[0].size()-1]= a[a.size()-1][a[0].size()-1];
    for(int i =a[0].size()-2 ; i >= 0 ; i--)
        dp[a.size()-1][i] = a[a.size()-1][i]+dp[a.size()-1][i+1];
    fr(i,a.size()-2,0){
        fr(j,a[0].size()-1, 0){
            if(j == a[0].size()-1)
                dp[i][j]= dp[i+1][j]+a[i][j];
            else
            {
                dp[i][j] = min(dp[i+1][j],dp[i][j+1]) +a[i][j];
            }
            
        }
    }
    cout<< dp[0][0];
    
}
int main(){
    int n,m;
    cin>> n>> m;
    vi a(n,vector<int>(m));

    f(i,0,n){
        f(j,0,m){
            cin>> a[i][j];
        }
    }
    //minmaze(a);
    goldmine(a);
    return 0;
}