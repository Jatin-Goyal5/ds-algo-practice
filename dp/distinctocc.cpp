#include<bits/stdc++.h>
#define f(i,a,b) for(int i =a ; i < b ; i++)
#define fr(i,a,b) for(int i = a; i>=b ; i--)
using namespace std;
typedef vector<vector<int>> vi;

void test(string s , string t){
    vi dp(t.length()+1,vector<int>(s.length()+1,0));

    f(i,0,dp[0].size())
        dp[0][i] = 1;
    f(i ,1 ,dp.size()){
        f(j,1 , dp[0].size()){
            if(t[i-1] == s[j-1]){
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
            }else{
                dp[i][j] = dp[i][j-1];

            }
        }
    }

    cout<< dp[t.length()][s.length()];
}


int main(){
    int t;
    cin>> t;
    while (t--)
    {
        string s,t;
        cin>> s>> t;
        test(s,t);
    }
    
    return 0;
}