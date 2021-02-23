#include <bits/stdc++.h>
using namespace std;

int cs(int n){
    // write your code here
    vector<int> dp(n+1);
    dp[0]=1;
    dp[3]=3;
    dp[2]=2; 
    dp[1]=1;
    for(int i =3; i <=n ; i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
    return 0;

}

int main(){
    int n;
    cin>>n;
    cout<<cs(n)<<endl;
}