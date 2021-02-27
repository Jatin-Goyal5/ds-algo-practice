// 1. You are given a number n and a number k separated by a space,
//  representing the number of houses and number of colors.
// 2. In the next n rows, you are given k space separated numbers 
// representing the cost of painting nth house with one of the k colors.
// 3. You are required to calculate and print the minimum cost of painting
//  all houses without painting any consecutive house with same color.
#include<bits/stdc++.h>
using namespace std;
void mincost(vector<vector<int>> a){
    vector<vector<int>> dp(a.size(), vector<int>(a[0].size()));
    int least= INT_MAX;
    int sleast= INT_MAX;
    for(int i =0 ; i < a[0].size() ; i++){
        dp[0][i] =a[0][i];
        if(a[0][i] <= least){
            sleast = least;
            least = a[0][i];
        }else if(a[0][i] <=sleast   ){
            sleast = a[0][i];
        }
        
    }
    for(int i =1 ; i < a.size() ; i++){
        int tleast= INT_MAX;
        int tsleast= INT_MAX;
        for(int j =0 ; j < a[0].size(); j++){
            dp[i][j] =a[i][j];
            if(dp[i-1][j] == least){
                dp[i][j] += sleast;
            }else{
               dp[i][j] += least; 
            }
            if(dp[i][j] <= tleast){
                tsleast = tleast;
                tleast =dp[i][j];
            }else if(dp[i][j] <=tsleast   ){
                tsleast = dp[i][j];
            } 
        }
        least = tleast;
        sleast = tsleast;
        
    }
    cout<< least;
}
int main(){
    int m,n;
    cin>> m >> n;
    vector<vector<int>> a(m,vector<int>(n));
    for(int i =0 ; i < m ; i++)
    {
        for(int j=0 ; j < n ; j++)
            cin>> a[i][j];
    }
    mincost(a);
    
    return 0;
}