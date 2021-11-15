#include<bits/stdc++.h>

using namespace std;

bool check(string s1 ,string s2){
        if(s1.length() < s2.length()){
            for(int i =0 ; i < s1.length() ; i++){
                for(int j =0 ; j < s2.length() ; j++)
                if(s1[i] == s2[j])
                    return false;

            }
        }else{
            for(int i =0 ; i < s2.length() ; i++){
                for(int j =0 ; j < s1.length() ; j++)
                if(s1[j] == s2[i])
                    return false;
            }
        }
        return true;
    }

 int maxLength(vector<string>& arr) {
        
        vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),0));
        for(int g =0 ; g < arr.size() ; g++){
            for(int i =0 ; i < arr.size() && i+g < arr.size();i++){
                if(g==0){
                    dp[i][i] = arr[i].length();
                }else{
                    if(check(arr[i+g],arr[i])){
                        int cl = dp[i][i+g-1]+dp[i+1][i+g];
                        dp[i][i+g] = cl-dp[i+1][i+g-1];
                    }else{
                        dp[i][i+g]=max(dp[i][i+g-1],dp[i+1][i+g]);
                    }
                }
            }
        }
        for(int i =0 ; i < dp.size() ; i++){
            for(int j =0 ;j < dp.size() ;j++)
                cout<< dp[i][j]<< " ";
            cout<< endl;
        }
        return dp[0][arr.size()-1];
        
        
    }
int main(){
    int n;
    cin>> n;
    vector<string> s(n);
    for(int i =0 ; i < s.size() ; i++)
        cin>> s[i];
    cout<< maxLength(s);
}