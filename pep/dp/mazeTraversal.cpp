#include<bits/stdc++.h>

using namespace std;

void profit( vector<vector<int>> a){
     vector<vector<int>> dp(a.size() , vector<int>(a[0].size()));
     
    for(int i = a.size()-1 ; i >=0 ; i--){
        for(int j = a[0].size()-1 ; j >= 0 ; j-- ){
            
            if(j == a[0].size()-1 && i == a.size()-1){
               dp[i][j] = a[i][j]; 
            }else if(j == a[0].size()-1){
                dp[i][j] = dp[i+1][j]+a[i][j];
            }else if(i == a.size()-1){
                dp[i][j] = dp[i][j+1]+a[i][j];
            }else{
                dp[i][j] = a[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
           
        }
       
    }
    
     cout<< dp[0][0];
   
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