#include<bits/stdc++.h>

using namespace std;

void profit( vector<vector<int>> a){
     vector<vector<int>> dp(a.size() , vector<int>(a[0].size()));
     
     for(int i = a.size()-1 ; i >= 0 ; i--)
        dp[i][a[0].size()-1] =a[i][a[0].size()-1];
    for(int j = a[0].size()-2 ; j >= 0 ; j-- ){
        for(int i = a.size()-1 ; i >=0 ; i--){
            dp[i][j] = a[i][j];
            if(i == a.size()-1){
                dp[i][j] += max(dp[i-1][j+1],dp[i][j+1]);
            }else if(i == 0){
              dp[i][j]+= max(dp[i+1][j+1],dp[i][j+1]);
            }else{
                 dp[i][j] +=max(dp[i+1][j+1], max(dp[i-1][j+1],dp[i][j+1]));
            }
        }
    }
    int maxp = INT_MIN;
    for(int i = a.size()-1 ; i >= 0 ; i--){
        maxp =max(maxp,dp[i][0]);
    }
    cout<< maxp;
}

int main(){
    int n,m;
    cin>> n>> m;
    vector<vector<int>> a(n , vector<int>(m));
    for(int i =0 ; i < a.size() ; i++){
        for(int j =0 ; j < a[0].size() ; j++){
            cin>> a[i][j];
        }
        
    }
    profit(a);
    

}