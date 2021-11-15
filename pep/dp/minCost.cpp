#include<bits/stdc++.h>
using namespace std;
void getCount(vector<vector<int>> a){
    vector<vector<int>> dp(a.size(),vector<int>(a.size(),0));
    int x =dp.size()-1;
    dp[x][x] = a[x][x];
    // cout<< dp[x][x];
    for(int i =dp.size()-2 ; i >=0 ; i--){
        dp[i][dp.size()-1] += dp[i+1][dp.size()-1]+a[i][dp.size()-1];
        dp[dp.size()-1][i] = dp[dp.size()-1][i+1]+a[dp.size()-1][i];
        // cout<< dp[dp.size()-1][i] << " ";
    }
    for(int i =dp.size()-2 ; i >=0 ; i--){
        for(int j =dp.size()-2 ; j >=0 ; j--){
            dp[i][j] = min(dp[i+1][j],dp[i][j+1]);
            dp[i][j] += a[i][j];
        }
    }
    cout<< dp[0][0];
    
}
int main(){
    int n,m;
    cin>> n>> m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i =0 ; i < n ;i++)
        for(int j =0 ; j < m ; j++)
            cin>>a[i][j];
            
    getCount(a);
    return 0;
}