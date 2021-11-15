#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    vector<int> a(n);
    for(int i =0 ; i < n ; i++){
        cin>> a[i];
    }
    vector<int> dp(n);
    dp[0] =1;
    int maxans= INT_MIN;
    for(int i = 1 ; i <n ; i++){
        dp[i] = 1;
        for(int j =i-1 ; j>=0 ; j--){
            if(a[j] < a[i]){
                dp[i] = max(dp[j]+1,dp[i]);
            }
        }
        maxans = max(maxans,dp[i]);
    }
    cout<< maxans;

    return 0;
}
// 10
// 10 22 9 33 21 50 41 60 80 1
// 1 2  0  

// 13
// 52 9 11 56 23 59 18 91 28 41 1 30 14
// 1  1  2 3  3  