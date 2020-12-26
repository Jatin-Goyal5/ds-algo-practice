#include<bits/stdc++.h>
using namespace std;

void test(){
    int min =0;
    string s;
    cin>> s;
    vector<int> dp(27);

    for(int i =0 ;  i < s.length() ; i++){
        dp[s[i]-'a'] += 1;
    }
    int c1=0, c2=0;
    for(int i =0 ; i < 27 ; i++){
        if(dp[i] ==1 ){
            c1++;
        }
        if(dp[i]> 0 && dp[i]%2 == 0){
            c2++;
        }
    }
    int ans = c1 <= c2 ? c1:c2;
    if(c2 != 0 && c1 !=0 ){
        cout<< ans<< endl;
    }else
    {
        cout<< "0"<< endl;
    }
    
}

int main(int argc ,char **argv){
    int t;
    cin>> t;
    while (t--)
    {
       
        test();
        
    }

    return 0;
}