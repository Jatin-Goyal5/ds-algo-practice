#include<bits/stdc++.h>

using namespace std;

void profit( vector<int> a, int tar){
     vector<int> dp(tar+1);
     dp[0] =1;
     sort(a.begin(),a.end());
    for(int i = 1 ; i < dp.size() ;i++ ){
        
        for(int j = 0 ; j < a.size() ; j++){
            if(a[j]>= i ){
                dp[i] += dp[i-a[j]];
            }
        }
    }
    
    cout<< dp[tar];
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