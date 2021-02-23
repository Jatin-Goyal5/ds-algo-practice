#include<bits/stdc++.h>

using namespace std;

void profit( vector<int> w,vector<int> v, int tar){
     vector<vector<int>> dp(w.size()+1 , vector<int>(tar+1));
     
    for(int i = 1 ; i < dp.size() ;i++ ){
        for(int j = 0 ; j < dp[0].size() ; j++){
            
            if(w[i-1] <=j )
            dp[i][j] = max(dp[i-1][j-w[i-1]]+v[i-1],dp[i-1][j]);
            else if(j != 0){
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    // for(int i = 1 ; i < dp.size() ;i++ ){
    //     for(int j = 0 ; j < dp[0].size() ; j++){
    //         cout<< dp[i][j] <<" ";
    //     }
    //     cout<< endl;
    // }
     cout<< (dp[w.size()][tar]);
    
   
}

int main(){
    int n,m;
    cin>> n;
    
    vector<int> v(n),w(n);
    for(int j =0 ; j < v.size() ; j++){
        cin>> v[j];
    }
    
    
    for(int j =0 ; j < w.size() ; j++){
        cin>> w[j];
    }
    cin>>m;
    

    profit(w,v,m);
    

}