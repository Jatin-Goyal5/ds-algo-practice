#include<bits/stdc++.h>
using namespace std;
int getCount(string s){
    vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));
    int count =0;
    for(int g =0 ; g < dp.size() ; g++){
        for(int i =0 ; i < dp.size() ; i++){
            int j = i+g;
            if(g == 0){
                dp[i][j] = true;
            }else if(g ==1){
                if(s[i] == s[j]){
                    dp[i][j] = true;
                }else{
                    dp[i][j] =false;
                }
            }else{
                    if(s[i] == s[j] && dp[i+1][j-1] == 1){
                    dp[i][j] = true;
                }else{
                    dp[i][j] =false;
                }
            }
            
            if(dp[i][j]){
             count++;   
            }
        }
    }
    return count;
    
}
int main(){
    string s;
    cin>> s;
    cout<< getCount(s)<< endl;
    return 0;
}