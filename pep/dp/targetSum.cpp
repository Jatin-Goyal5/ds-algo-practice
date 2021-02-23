#include<bits/stdc++.h>

using namespace std;

void profit( vector<int> a, int tar){
     vector<vector<bool>> dp(a.size()+1 , vector<bool>(tar+1));
     
    dp[0][0] = true;
    for(int i = 1 ; i < dp.size() ;i++ ){
        for(int j = 0 ; j < dp[0].size() ; j++){
            dp[i][j] = dp[i-1][j];
            if(a[i-1] <=j )
            dp[i][j] = dp[i][j] || dp[i-1][j-a[i-1]];
        }
    }
    if(dp[a.size()][tar])
    cout<< "true";
    else
        cout<<"false";
   
}

int main(){
    int n,m;
    cin>> n;
    
    vector<int> a(n);
    for(int j =0 ; j < a.size() ; j++){
        cin>> a[j];
    }
    cin>>m;
    

    profit(a,m);
    

}