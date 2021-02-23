#include<bits/stdc++.h>
using namespace std;

int comb(vector<int> a, int tar){
    int n = a.size();
    vector<vector<int>> dp(n,vector<int>(tar+1));
    
    for(int i =0 ; i < n ; i++)
        dp[i][0] = 1;
        
    for(int i = 0; i < n ; i++){
        for(int j = 1; j < dp[0].size() ; j++){
            if(i == 0 && j >= a[i]){
                
                dp[i][j] += dp[i][j-a[i]];
            }else if(i >0){
                dp[i][j] = dp[i-1][j];
                if (j >= a[i]){
                    dp[i][j] += dp[i][j-a[i]];
                    
                }
            }
        }
    }
    return dp[a.size()-1][tar];
}
int main(){
    int n;
    cin>> n;
    vector<int> a(n);
    for(int i =0 ; i < n ; i++)
        cin>> a[i];
    int tar=0;
    cin>> tar;
    cout<< comb(a, tar);
    
    return 0;
}