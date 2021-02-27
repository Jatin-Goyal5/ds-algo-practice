#include<bits/stdc++.h>

using namespace std;

void profit( vector<int> v,vector<int> w, int tar){
     vector<int> dp(tar+1);
     dp[0] =0;
    //  sort(a.begin(),a.end());
    for(int i = 1 ; i < dp.size() ;i++ ){
       // dp[i] = v[i];
        for(int j = 0 ; j < v.size() ; j++){
            // if(i<a[j]){
            //     break;
            // }
            if(w[j]<= i ){
             dp[i] = max(dp[i],dp[i-w[j]]+v[j]);   
            }
        }
    }
    // for(int i=0 ; i < dp.size() ; i++)
    //     cout<< dp[i]<< " ";
    
     cout<< dp[tar];
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
    

    profit(v,w,m);
    

}